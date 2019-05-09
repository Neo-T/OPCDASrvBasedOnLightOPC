// OPCTestClient.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <stdlib.h>
#include <tchar.h>

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <cstring>
#include "opccomn.h"
#include "opcda.h"
#include "OpcEnum.h"

//* 获取指定名称的OPC服务器的CLSID
static INT __GetRemoteOPCSrvCLSIDByRegistry(CHAR *pszIPAddr, CHAR *pszUserName, CHAR *pszPassword, CHAR *pszOPCSrvProgID, CHAR *pszOPCSrvCLSID)
{
	INT nRtnVal = 0;

	//* 登录远程计算机
	HANDLE hToken;
	if (!LogonUser(pszUserName, pszIPAddr, pszPassword, LOGON32_LOGON_NEW_CREDENTIALS, LOGON32_PROVIDER_DEFAULT, &hToken))
	{
		printf("无法连接IP地址为%s的计算机，错误码：%d", pszIPAddr, GetLastError());
		return -1;
	}

	//* 模拟当前登录的用户
	ImpersonateLoggedOnUser(hToken);
	{
		do {
			CHAR szKey[MAX_PATH + 1];
			DWORD dwLen = MAX_PATH;
			DWORD dwIdx = 0;
			CHAR szCLSID[100];
			LONG lSize;
			HKEY hKey = HKEY_CLASSES_ROOT;			
			DWORD dwRtnVal = RegConnectRegistry(pszIPAddr, HKEY_CLASSES_ROOT, &hKey);
			if (dwRtnVal != ERROR_SUCCESS)
			{
				printf("无法连接IP地址为%s的计算机，错误码：%d", pszIPAddr, dwRtnVal);
				nRtnVal = -2;
				break;
			}

			printf("成功连接IP地址为%s的计算机，开始枚举该计算机系统上的注册表...\r\n", pszIPAddr);

			//* 读取指定键值
			if (RegEnumKey(hKey, dwIdx, szKey, dwLen) == ERROR_SUCCESS)
			{
				HKEY hSubKey;

				//* 打开指定名称的OPC服务器所在的键，在这里就是"OPC.LightOPC-exe"
				sprintf(szKey, pszOPCSrvProgID);

				//* 打开指定键值并取值
				if (RegOpenKey(hKey, szKey, &hSubKey) == ERROR_SUCCESS)
				{
					memset(szCLSID, 0, sizeof(szCLSID));
					lSize = sizeof(szCLSID) - 1;
					if (RegQueryValue(hSubKey, "CLSID", szCLSID, &lSize) == ERROR_SUCCESS)
					{
						if (RegQueryValue(hSubKey, "OPC", NULL, NULL) == ERROR_SUCCESS)
						{
							sprintf(pszOPCSrvCLSID, "%s", szCLSID);
							printf("『%s』服务已找到：%s\r\n", pszOPCSrvProgID, pszOPCSrvCLSID);
						}
						else
						{
							printf("查询OPC键失败，错误码：%d\r\n", GetLastError());
							nRtnVal = -6;
						}
					}
					else
					{ 
						printf("查询CLSID键失败，错误码：%d\r\n", GetLastError());
						nRtnVal = -5;
					}

					RegCloseKey(hSubKey);					
				}
				else
				{
					printf("RegOpenKey()函数执行失败，错误码：%d\r\n", GetLastError());
					nRtnVal = -4;
				}
			}
			else
			{
				printf("RegEnumKey()函数执行失败，错误码：%d\r\n", GetLastError());
				nRtnVal = -3;
			}

		} while (FALSE);		
	}	
	RevertToSelf();	//* 结束模拟

	return nRtnVal;
}

//* 获取指定名称的OPC服务器的CLSID
static INT __GetRemoteOPCSrvCLSIDByOPCEnum(CHAR *pszIPAddr, CHAR *pszUserName, CHAR *pszPassword, CHAR *pszOPCSrvProgID, CHAR *pszOPCSrvCLSID)
{
	HRESULT hr;
	INT nRtnVal = 0;
	
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (!SUCCEEDED(hr))
	{
		printf("CoInitializeEx()初始化失败：0x%08X\r\n", hr);
		return -1;
	}

	do {
		COSERVERINFO stCoServerInfo;
		COAUTHINFO stCoAuthInfo;
		COAUTHIDENTITY stCoAuthID;
		INT nSize = strlen(pszIPAddr) * sizeof(WCHAR);
		memset(&stCoServerInfo, 0, sizeof(stCoServerInfo));
		stCoServerInfo.pwszName = (WCHAR *)CoTaskMemAlloc(nSize * sizeof(WCHAR));
		if (!stCoServerInfo.pwszName)
		{
			printf("CoTaskMemAlloc()函数执行失败!\r\n");
			nRtnVal = -2;
			break;
		}

		ZeroMemory(&stCoAuthID, sizeof(COAUTHIDENTITY));
		stCoAuthID.User = reinterpret_cast<USHORT *>(pszUserName);
		stCoAuthID.UserLength = strlen(pszUserName);
		stCoAuthID.Domain = reinterpret_cast<USHORT *>("");
		stCoAuthID.DomainLength = 0;
		stCoAuthID.Password = reinterpret_cast<USHORT *>(pszPassword);
		stCoAuthID.PasswordLength = strlen(pszPassword);
		stCoAuthID.Flags = SEC_WINNT_AUTH_IDENTITY_ANSI;

		ZeroMemory(&stCoAuthInfo, sizeof(COAUTHINFO));
		stCoAuthInfo.dwAuthnSvc = RPC_C_AUTHN_WINNT;
		stCoAuthInfo.dwAuthzSvc = RPC_C_AUTHZ_NONE;
		stCoAuthInfo.pwszServerPrincName = NULL;
		stCoAuthInfo.dwAuthnLevel = RPC_C_AUTHN_LEVEL_CONNECT;
		stCoAuthInfo.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;	//* 必须是模拟登陆
		stCoAuthInfo.pAuthIdentityData = &stCoAuthID;
		stCoAuthInfo.dwCapabilities = EOAC_NONE;

		mbstowcs(stCoServerInfo.pwszName, pszIPAddr, nSize);
		stCoServerInfo.pAuthInfo = &stCoAuthInfo;
		stCoServerInfo.dwReserved1 = 0;
		stCoServerInfo.dwReserved2 = 0;

		MULTI_QI stMultiQI;
		ZeroMemory(&stMultiQI, sizeof(stMultiQI));
		stMultiQI.pIID = &IID_IOPCServerList;	//* 参见opccomn_i.c
		stMultiQI.pItf = NULL;

		//* 初始化安全结构，模拟登录远程机器
		hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
		if (!(SUCCEEDED(hr) || RPC_E_TOO_LATE == hr))
		{
			printf("CoInitializeSecurity()函数执行失败，错误码：0x%08X\r\n", hr);
			nRtnVal = -3;
			break;
		}

		hr = CoCreateInstanceEx(CLSID_OpcServerList, 
								NULL,
								CLSCTX_REMOTE_SERVER,	//* 显式的指定要连接远程机器
								&stCoServerInfo,
								sizeof(stMultiQI) / sizeof(MULTI_QI),
								&stMultiQI);

		//* 无论成功与否，先释放刚才申请的内存
		CoTaskMemFree(stCoServerInfo.pwszName);

		//* 如果CoCreateInstanceEx()执行失败
		if (FAILED(hr))
		{
			printf("CoCreateInstanceEx()函数执行失败，错误码：0x%08X %s %s\r\n", hr, pszIPAddr, pszUserName);
			nRtnVal = -4;
			break;
		}

		//* 如果没有获取到DCOM组件的查询接
		if (FAILED(stMultiQI.hr))
		{
			printf("获取组件的查询接口失败，错误码：0x%08X\r\n", stMultiQI.hr);
			nRtnVal = -5;
			break;
		}

		//* 读取所有已注册的OPC服务器
		CComPtr<IOPCServerList> pobjOPCSrvList = (IOPCServerList *)stMultiQI.pItf;
		IEnumGUID *pobjEnumGUID = NULL;
		CLSID stCLSID;
		DWORD dwCeltFetchedNum;
		LPOLESTR wszProgID, wszUserType;
		CLSID stCatID = CATID_OPCDAServer20;
		hr = pobjOPCSrvList->EnumClassesOfCategories(1, &stCatID, 1, &stCatID, &pobjEnumGUID);
		if (FAILED(hr))
		{
			printf("EnumClassesOfCategories()函数执行失败，错误码：0x%08X\r\n", hr);
			nRtnVal = -6;
			break;
		}

		//* 开始枚举服务器并获取指定ProgID的CLSID
		while (SUCCEEDED(pobjEnumGUID->Next(1, &stCLSID, &dwCeltFetchedNum)))
		{
			if (!dwCeltFetchedNum)
				break;
			hr = pobjOPCSrvList->GetClassDetails(stCLSID, &wszProgID, &wszUserType);
			if (FAILED(hr))
			{
				printf("GetClassDetails()函数执行失败，错误码：0x%08X\r\n", hr);
				nRtnVal = -7;
				break;
			}

			CHAR szProgID[100];
			CString cstrProgID = wszProgID;
			sprintf(szProgID, "%s", cstrProgID);			

			if(!strcmp(pszOPCSrvProgID, szProgID))
			{ 
				BSTR wszCLSID;				
				StringFromCLSID(stCLSID, &wszCLSID);
				CString cstrCLSID = wszCLSID;

				sprintf(pszOPCSrvCLSID, "%s", cstrCLSID);
				printf("『%s』服务已找到：%s\r\n", pszOPCSrvProgID, pszOPCSrvCLSID);

				//* 释放占用的内存
				CoTaskMemFree(wszProgID);
				CoTaskMemFree(wszUserType);

				break;
			}			

			//* 释放占用的内存
			CoTaskMemFree(wszProgID);
			CoTaskMemFree(wszUserType);
		}
	} while (FALSE);
		
	
	CoUninitialize();

	return nRtnVal;
}


//* OPC规范提供的查询接口索引
#define MQI_IOPCSERVER		0
#define MQI_IOPCCOMMON		1
#define MQI_IOPCCONNPT		2
#define MQI_IOPCITEMPROP	3
#define MQI_IOPCBROWSE		4
#define MQI_IOPCPUBLIC		5
#define MQI_IOPCPERSIST		6

//* OPC调用接口
IOPCServer *pIServer = NULL;
IOPCCommon *pICommon = NULL;
IConnectionPointContainer *pIConnPtContainer = NULL;
IOPCItemProperties *pIItemProps = NULL;
IOPCBrowseServerAddressSpace *pIBrowse = NULL;
IOPCServerPublicGroups *pIPublicGroups = NULL;
IPersistFile *pIPersistFile = NULL;

//* 按OPC规范要求定义一个缺省Group类
typedef DWORD LCID;
class CKGroup : public CObject
{
public:
	CKGroup() {};
	~CKGroup() {};

public:

	DWORD GetUpdateRate() 
	{ 
		return 1000; 
	}
	
	LCID GetLanguageID() 
	{ 
		return 1033; 
	}
};

typedef struct _ST_OPC_ITEM_ {
	OPCHANDLE ohItemSrv;
	CHAR szItemName[50];
} ST_OPC_ITEM, *PST_OPC_ITEM;

CKGroup *pobjGroup;
IOPCItemMgt *pIItemMgt;
IOPCSyncIO *pISync;

//* 添加一个缺省Group
static INT __AddDefaultGroup(void)
{
	INT nRtnVal = 0;

	WCHAR wchBuffer[MAX_PATH];
	WCHAR *pwszName = NULL;
	HRESULT hr;
	LONG lBias = 0;
	FLOAT fDeadband = 0;
	IUnknown *pIUnknown = NULL;
	OPCHANDLE hServer;
	DWORD dwRevUpdateRate;

	//* 缺省GROUP的名称："default_group"
	MultiByteToWideChar(CP_ACP, 0, "default_group", -1, wchBuffer, MAX_PATH - 1);
	pwszName = wchBuffer;

	pobjGroup = new CKGroup();
	hr = pIServer->AddGroup(pwszName, 1, 100, (OPCHANDLE)pobjGroup,
								&lBias, &fDeadband, pobjGroup->GetLanguageID(),
								&hServer, &dwRevUpdateRate, IID_IUnknown, &pIUnknown);
	if (SUCCEEDED(hr) && pIUnknown)
	{
		do {
			hr = pIUnknown->QueryInterface(IID_IOPCItemMgt, (void **)&(pIItemMgt));
			if (FAILED(hr) || pIItemMgt == NULL)
			{
				printf("无法获取IID_IOPCItemMgt接口指针，错误码：0x%08X\r\n", hr);
				nRtnVal = -2;
				break;
			}

			hr = pIUnknown->QueryInterface(IID_IOPCSyncIO, (void **)&(pISync));
			if (FAILED(hr) || pISync == NULL)
			{
				pIItemMgt->Release();
				pIItemMgt = NULL;
				printf("无法获取IID_IOPCSyncIO接口指针，错误码：0x%08X\r\n", hr);
				nRtnVal = -3;
			}				
		} while (FALSE);		

		pIUnknown->Release();				
	}
	else
	{ 
		printf("AddGroup()函数执行失败，错误码：0x%08X\r\n", hr);
		nRtnVal = -1;
	}	

	return nRtnVal;
}

//* 连接OPC服务器并获取相关接口
static INT __ConnOPCServer(CHAR *pszIPAddr, CHAR *pszUserName, CHAR *pszPassword, CHAR *pszOPCSrvCLSID)
{
	HRESULT hr;
	INT nRtnVal = 0;

	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (!SUCCEEDED(hr))
	{
		printf("CoInitializeEx()初始化失败：0x%08X\r\n", hr);
		return -1;
	}

	MULTI_QI stMultiQI[7]; //* OPC规范：每个服务器都提供标准的查询接口数组						   
	ZeroMemory(&stMultiQI[0], sizeof(stMultiQI));

	//* 按照需求初始化查询接口的ID
	stMultiQI[MQI_IOPCSERVER].pIID = &IID_IOPCServer;
	stMultiQI[MQI_IOPCCOMMON].pIID = &IID_IOPCCommon;
	stMultiQI[MQI_IOPCCONNPT].pIID = &IID_IConnectionPointContainer;
	stMultiQI[MQI_IOPCITEMPROP].pIID = &IID_IOPCItemProperties;
	stMultiQI[MQI_IOPCBROWSE].pIID = &IID_IOPCBrowseServerAddressSpace;
	stMultiQI[MQI_IOPCPUBLIC].pIID = &IID_IOPCServerPublicGroups;
	stMultiQI[MQI_IOPCPERSIST].pIID = &IID_IPersistFile;

	do {
		COSERVERINFO stCoServerInfo;
		COAUTHINFO stCoAuthInfo;
		COAUTHIDENTITY stCoAuthID;
		INT nSize = strlen(pszIPAddr) * sizeof(WCHAR);
		memset(&stCoServerInfo, 0, sizeof(stCoServerInfo));
		stCoServerInfo.pwszName = (WCHAR *)CoTaskMemAlloc(nSize * sizeof(WCHAR));
		if (!stCoServerInfo.pwszName)
		{
			printf("CoTaskMemAlloc()函数执行失败!\r\n");
			nRtnVal = -2;
			break;
		}

		ZeroMemory(&stCoAuthID, sizeof(COAUTHIDENTITY));
		stCoAuthID.User = reinterpret_cast<USHORT *>(pszUserName);
		stCoAuthID.UserLength = strlen(pszUserName);
		stCoAuthID.Domain = reinterpret_cast<USHORT *>("");
		stCoAuthID.DomainLength = 0;
		stCoAuthID.Password = reinterpret_cast<USHORT *>(pszPassword);
		stCoAuthID.PasswordLength = strlen(pszPassword);
		stCoAuthID.Flags = SEC_WINNT_AUTH_IDENTITY_ANSI;

		ZeroMemory(&stCoAuthInfo, sizeof(COAUTHINFO));
		stCoAuthInfo.dwAuthnSvc = RPC_C_AUTHN_WINNT;
		stCoAuthInfo.dwAuthzSvc = RPC_C_AUTHZ_NONE;
		stCoAuthInfo.pwszServerPrincName = NULL;
		stCoAuthInfo.dwAuthnLevel = RPC_C_AUTHN_LEVEL_CONNECT;
		stCoAuthInfo.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;	//* 必须是模拟登陆
		stCoAuthInfo.pAuthIdentityData = &stCoAuthID;
		stCoAuthInfo.dwCapabilities = EOAC_NONE;

		mbstowcs(stCoServerInfo.pwszName, pszIPAddr, nSize);
		stCoServerInfo.pAuthInfo = &stCoAuthInfo;
		stCoServerInfo.dwReserved1 = 0;
		stCoServerInfo.dwReserved2 = 0;

		//* 初始化安全结构，模拟登录远程机器
		hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
		if (!(SUCCEEDED(hr) || RPC_E_TOO_LATE == hr))
		{
			printf("CoInitializeSecurity()函数执行失败，错误码：0x%08X\r\n", hr);
			nRtnVal = -3;
			break;
		}

		CString cstrCLSID = CString(pszOPCSrvCLSID);
		CLSID stCLSID;
		CLSIDFromString(cstrCLSID.AllocSysString(), &stCLSID);
		hr = CoCreateInstanceEx(stCLSID, NULL, CLSCTX_REMOTE_SERVER, &stCoServerInfo, sizeof(stMultiQI) / sizeof(MULTI_QI), stMultiQI);

		//* 无论成功与否，先释放刚才申请的内存
		CoTaskMemFree(stCoServerInfo.pwszName);

		//* 如果CoCreateInstanceEx()执行失败
		if (FAILED(hr))
		{
			printf("CoCreateInstanceEx()函数执行失败，错误码：0x%08X %s %s\r\n", hr, pszIPAddr, pszUserName);
			nRtnVal = -4;
			break;
		}

		//* 该接口必须存在，否则一切免谈
		if (FAILED(stMultiQI[MQI_IOPCSERVER].hr))
		{ 
			printf("IID_IOPCServer接口并不存在，连接OPC服务器的进程终止！\r\n", hr);
			nRtnVal = -5;
			break;
		}

		//* 读取并保存所有支持的接口
		pIServer = (IOPCServer*)stMultiQI[MQI_IOPCSERVER].pItf;
		if (SUCCEEDED(stMultiQI[MQI_IOPCCOMMON].hr))		
			pICommon = (IOPCCommon *)stMultiQI[MQI_IOPCCOMMON].pItf;
		if (SUCCEEDED(stMultiQI[MQI_IOPCCONNPT].hr))		
			pIConnPtContainer = (IConnectionPointContainer *)stMultiQI[MQI_IOPCCONNPT].pItf;
		if (SUCCEEDED(stMultiQI[MQI_IOPCITEMPROP].hr))		
			pIItemProps = (IOPCItemProperties *)stMultiQI[MQI_IOPCITEMPROP].pItf;
		if (SUCCEEDED(stMultiQI[MQI_IOPCBROWSE].hr))		
			pIBrowse = (IOPCBrowseServerAddressSpace *)stMultiQI[MQI_IOPCBROWSE].pItf;		
		if (SUCCEEDED(stMultiQI[MQI_IOPCPUBLIC].hr))
			pIPublicGroups = (IOPCServerPublicGroups *)stMultiQI[MQI_IOPCPUBLIC].pItf;
		if (SUCCEEDED(stMultiQI[MQI_IOPCPERSIST].hr))		
			pIPersistFile = (IPersistFile *)stMultiQI[MQI_IOPCPERSIST].pItf;
	} while (FALSE);

	return nRtnVal;
}

static void __DisconnectOPCServer(void)
{	
	if(pIItemMgt)
		pIItemMgt->Release();
	if(pISync)
		pISync->Release();

	delete pobjGroup;

	if (pIPersistFile)
		pIPersistFile->Release();
	if (pIPublicGroups)
		pIPublicGroups->Release();
	if (pIBrowse)
		pIBrowse->Release();
	if (pIItemProps)
		pIItemProps->Release();
	if (pIConnPtContainer)
		pIConnPtContainer->Release();
	if (pICommon)
		pICommon->Release();
	if (pIServer)
		pIServer->Release();

	CoUninitialize();
}

BOOL MapVariantValToString(CHAR *pszVal, VARIANT *pvtVal, VARTYPE vtType)
{
	switch (vtType)
	{
	case VT_BOOL:
		memcpy(pszVal, "0", sizeof("0") - 1);
		if (pvtVal->boolVal)
			memcpy(pszVal, "1", sizeof("1") - 1);
		break;

	case VT_UI1:
	case VT_I1:
	case VT_UI2:
	case VT_I2:
	case VT_UI4:
	case VT_I4:
		sprintf(pszVal, "%d", pvtVal->uintVal);
		break;

	case VT_R4:
		sprintf(pszVal, "%0.4f", pvtVal->fltVal);
		break;

	case VT_R8:
		sprintf(pszVal, "%0.4lf", pvtVal->dblVal);
		break;

	case VT_BSTR:
		sprintf(pszVal, "%s", pvtVal->pbstrVal);
		break;

	default:
		memcpy(pszVal, "N/A", sizeof("N/A") - 1);
		return FALSE;
	}

	return TRUE;
}

static INT __AddItemToLocalMgmtIf(CHAR *pszItemName, VARTYPE vtDataType, OPCHANDLE *pohaItemServer)
{
	HRESULT hRslt;
	OPCITEMDEF *pstOPCItem = NULL;
	OPCITEMRESULT *pstOPCRslt = NULL;
	HRESULT *phErrors = NULL;
	DWORD dwLen;

	pstOPCItem = (OPCITEMDEF *)CoTaskMemAlloc(sizeof(OPCITEMDEF));
	if (pstOPCItem == NULL)
	{
		printf("CoTaskMemAlloc()函数执行失败，错误码(-1)：%d\r\n", GetLastError());
		return -1;
	}

	pstOPCItem->szAccessPath = NULL;

	dwLen = lstrlen(pszItemName);
	pstOPCItem->szItemID = (WCHAR *)CoTaskMemAlloc((dwLen + 1) * sizeof(WCHAR));
	if (pstOPCItem->szItemID == NULL)
	{
		CoTaskMemFree(pstOPCItem);

		printf("CoTaskMemAlloc()函数执行失败，错误码(-2)：%d\r\n", GetLastError());

		return -2;
	}

	MultiByteToWideChar(CP_ACP, 0, pszItemName, -1, pstOPCItem->szItemID, dwLen + 1);

	pstOPCItem->bActive = 1;
	pstOPCItem->hClient = (OPCHANDLE)NULL;
	pstOPCItem->dwBlobSize = 0;
	pstOPCItem->pBlob = NULL;
	pstOPCItem->vtRequestedDataType = (VARTYPE)vtDataType;

	hRslt = pIItemMgt->AddItems(1, pstOPCItem, &pstOPCRslt, &phErrors);
	if (SUCCEEDED(hRslt))
	{
		*pohaItemServer = pstOPCRslt[0].hServer;

		CoTaskMemFree(pstOPCRslt);
		CoTaskMemFree(phErrors);
	}

	CoTaskMemFree(pstOPCItem->szItemID);
	CoTaskMemFree(pstOPCItem);

	return 0;
}

static INT __ReadItem(PST_OPC_ITEM pstaItem, UINT unItemSrvNum)
{
	UINT i;
	INT nRtnVal = 0;

	OPCDATASOURCE dwSource = OPC_DS_DEVICE; //OPC_DS_CACHE;
	OPCHANDLE *pohaItemSrv = NULL;
	OPCITEMSTATE *pstValues = NULL;
	HRESULT *phErrors = NULL;
	HRESULT hr;
	LONG64 hClientItem;
	static time_t tPrevTime = time(NULL);
	time_t tCurTime;
	CHAR szTip[256];

	pohaItemSrv = (OPCHANDLE *)CoTaskMemAlloc(unItemSrvNum * sizeof(OPCHANDLE));
	if (pohaItemSrv == NULL)
	{
		printf("无法为Item Server申请一块有效的内存，错误码：%d\r\n", GetLastError());
		return -1;
	}

	//* 将Item Server句柄复制COM组件内存
	for (i = 0; i<unItemSrvNum; i++)	
		pohaItemSrv[i] = pstaItem[i].ohItemSrv;

	try {
		hr = pISync->Read(dwSource, unItemSrvNum, pohaItemSrv, &pstValues, &phErrors);

		if (SUCCEEDED(hr))
		{
			tPrevTime = time(NULL);
			for (i = 0; i<unItemSrvNum; i++)
			{
				CHAR szVal[128], szTimestamp[128];
				FILETIME stFTLocal;
				SYSTEMTIME stSystime;

				//* 转换数值
				ZeroMemory(szVal, sizeof(szVal));
				if (MapVariantValToString(szVal, &pstValues[i].vDataValue, pstValues[i].vDataValue.vt))
				{
					//* 转换示时间戳
					FileTimeToLocalFileTime(&pstValues[i].ftTimeStamp, &stFTLocal);
					FileTimeToSystemTime(&stFTLocal, &stSystime);
					wsprintf(szTimestamp, _T("%02d:%02d:%02d:%03d"), stSystime.wHour, stSystime.wMinute, stSystime.wSecond, stSystime.wMilliseconds);

					printf("『%s』 %-24s %s\r\n", pstaItem[i].szItemName, szVal, szTimestamp);
				}
				else
				{
					printf("不识别的数据类型！\r\n");
				}				
				
				VariantClear(&pstValues[i].vDataValue);
			}
		}
		else
		{
			tCurTime = time(NULL);
			if ((tCurTime > tPrevTime) && ((tCurTime - tPrevTime) > 30))
			{				
				printf("读取变量数值时发生错误，错误编码为：0x%08X，该错误已持续一段时间(不少于30秒)，系统将被迫关闭!", hr);
				nRtnVal = -4;
			}
		}
	}
	catch (...) {
		nRtnVal = -2;
	}

	CoTaskMemFree(pohaItemSrv);

	if (pstValues)
		CoTaskMemFree(pstValues);

	if (phErrors)
		CoTaskMemFree(phErrors);

	return nRtnVal;
}

volatile BOOL blIsRunning;
BOOL WINAPI ConsoleHandler(DWORD CEvent)
{
	blIsRunning = FALSE;
	printf("系统正在退出，请稍等...\r\n");
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
		CHAR szCLSID[100];

	if (argc != 5)
	{
		printf("Usage:%s opcserver_ip username password OpcProgID\r\n", argv[0]);
		return -1;
	}

	//* 设定该程序捕获控制台CTRL+C输入，以使程序能够正常退出
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE);

	//__GetRemoteOPCSrvCLSIDByOPCEnum(argv[1], argv[2], argv[3], argv[4], szCLSID);
	if (__GetRemoteOPCSrvCLSIDByRegistry(argv[1], argv[2], argv[3], argv[4], szCLSID))
	{
		printf("__GetRemoteOPCSrvCLSIDByRegistry()函数执行失败，进程退出！\r\n");
		return -2;
	}

	//* 连接成功则进行后续操作
	if (!__ConnOPCServer(argv[1], argv[2], argv[3], szCLSID))
	{
		do {
			if (__AddDefaultGroup())
			{
				printf("__AddDefaultGroup()函数执行失败，进程退出！\r\n");
				break;
			}

			ST_OPC_ITEM staItem[1];	

			sprintf(staItem[0].szItemName, "lulu");
			if (__AddItemToLocalMgmtIf(staItem[0].szItemName, VT_I2, &staItem[0].ohItemSrv))	//* exe_samp工程之sample.cpp文件第573行“lulu”变量为VT_I2类型
			{
				printf("__AddItemToLocalMgmtIf()函数执行失败，进程退出！\r\n");
				break;
			}

			blIsRunning = TRUE;			
			while (blIsRunning)
			{
				if (__ReadItem(staItem, sizeof(staItem) / sizeof(ST_OPC_ITEM)))
					break;

				Sleep(1000);				
			}

		} while (FALSE);

		//* 断开连接
		__DisconnectOPCServer();
	}
	else
	{
		printf("__ConnOPCServer()函数执行失败，进程退出！\r\n");
		return -3;
	}

	return 0;
}

