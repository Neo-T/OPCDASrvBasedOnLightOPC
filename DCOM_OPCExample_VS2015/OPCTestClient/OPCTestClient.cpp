// OPCTestClient.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include "opccomn.h"
#include "opcda.h"
#include "fixedsharedfile.h"
#include "shutdownsink.h"
#include "group.h"
#include "datasink20.h"
#include "OpcEnum.h"

//* 获取指定名称的OPC服务器的CLSID
static INT __GetRemoteOPCSrvCLSID(CHAR *pszIPAddr, CHAR *pszUserName, CHAR *pszPassword, CHAR *pszOPCSrvProgID, CHAR *pszOPCSrvCLSID)
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
		stMultiQI.pIID = &IID_IOPCServerList;	//* 参见iDCOMTestSrv_i.c
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

		//* 如果没有获取到DCOM组件的查询接口
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
		DWORD dwCount;
		LPOLESTR szProgId, szUserType;
		CLSID stCatID = CATID_OPCDAServer20;
		hr = pobjOPCSrvList->EnumClassesOfCategories(1, &stCatID, 1, &stCatID, &pobjEnumGUID);
		if (FAILED(hr))
		{
			printf("EnumClassesOfCategories()函数执行失败，错误码：0x%08X\r\n", hr);
			nRtnVal = -6;
			break;
		}

		//* 开始枚举服务器并获取指定ProgID的CLSID
		while (SUCCEEDED(pobjEnumGUID->Next(1, &stCLSID, &dwCount)))
		{
			hr = pobjOPCSrvList->GetClassDetails(stCLSID, &szProgId, &szUserType);
			if (FAILED(hr))
			{
				printf("GetClassDetails()函数执行失败，错误码：0x%08X\r\n", hr);
				nRtnVal = -7;
				break;
			}

			printf("%lls\r\n", szProgId);

			//* 是否占用的内存
			CoTaskMemFree(szProgId);
			CoTaskMemFree(szUserType);
		}
	} while (FALSE);
		
	
	CoUninitialize();

	return nRtnVal;
}


//* 需要注意，由于我们编译的是64位版本，而datasink20.cpp中使用的OPCHANDLE则是DWORD类型，其经常作为保存指针地址的变量类型来用，64位机器的指针地址
//* 也是64位的，这样就会缺号高32位数值，导致程序运行故障，所以一定注意一旦使用带有OPCHANDLER参数的函数传递地址时，要手动将函数参数类型改为64位，
//* 也就是不再使用OPCHANDLER作为参数类型，显式的采用LONG64类型
int main(int argc, CHAR* argv[])
{
	__GetRemoteOPCSrvCLSID(argv[1], argv[2], argv[3], NULL, NULL);

    return 0;
}

