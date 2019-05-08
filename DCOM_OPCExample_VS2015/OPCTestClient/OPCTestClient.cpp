// OPCTestClient.cpp : �������̨Ӧ�ó������ڵ㡣
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

//* ��ȡָ�����Ƶ�OPC��������CLSID
static INT __GetRemoteOPCSrvCLSID(CHAR *pszIPAddr, CHAR *pszUserName, CHAR *pszPassword, CHAR *pszOPCSrvProgID, CHAR *pszOPCSrvCLSID)
{
	HRESULT hr;
	INT nRtnVal = 0;
	
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (!SUCCEEDED(hr))
	{
		printf("CoInitializeEx()��ʼ��ʧ�ܣ�0x%08X\r\n", hr);
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
			printf("CoTaskMemAlloc()����ִ��ʧ��!\r\n");
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
		stCoAuthInfo.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;	//* ������ģ���½
		stCoAuthInfo.pAuthIdentityData = &stCoAuthID;
		stCoAuthInfo.dwCapabilities = EOAC_NONE;

		mbstowcs(stCoServerInfo.pwszName, pszIPAddr, nSize);
		stCoServerInfo.pAuthInfo = &stCoAuthInfo;
		stCoServerInfo.dwReserved1 = 0;
		stCoServerInfo.dwReserved2 = 0;

		MULTI_QI stMultiQI;
		ZeroMemory(&stMultiQI, sizeof(stMultiQI));
		stMultiQI.pIID = &IID_IOPCServerList;	//* �μ�iDCOMTestSrv_i.c
		stMultiQI.pItf = NULL;

		//* ��ʼ����ȫ�ṹ��ģ���¼Զ�̻���
		hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
		if (!(SUCCEEDED(hr) || RPC_E_TOO_LATE == hr))
		{
			printf("CoInitializeSecurity()����ִ��ʧ�ܣ������룺0x%08X\r\n", hr);
			nRtnVal = -3;
			break;
		}

		hr = CoCreateInstanceEx(CLSID_OpcServerList, 
								NULL,
								CLSCTX_REMOTE_SERVER,	//* ��ʽ��ָ��Ҫ����Զ�̻���
								&stCoServerInfo,
								sizeof(stMultiQI) / sizeof(MULTI_QI),
								&stMultiQI);

		//* ���۳ɹ�������ͷŸղ�������ڴ�
		CoTaskMemFree(stCoServerInfo.pwszName);

		//* ���CoCreateInstanceEx()ִ��ʧ��
		if (FAILED(hr))
		{
			printf("CoCreateInstanceEx()����ִ��ʧ�ܣ������룺0x%08X %s %s\r\n", hr, pszIPAddr, pszUserName);
			nRtnVal = -4;
			break;
		}

		//* ���û�л�ȡ��DCOM����Ĳ�ѯ�ӿ�
		if (FAILED(stMultiQI.hr))
		{
			printf("��ȡ����Ĳ�ѯ�ӿ�ʧ�ܣ������룺0x%08X\r\n", stMultiQI.hr);
			nRtnVal = -5;
			break;
		}

		//* ��ȡ������ע���OPC������
		CComPtr<IOPCServerList> pobjOPCSrvList = (IOPCServerList *)stMultiQI.pItf;
		IEnumGUID *pobjEnumGUID = NULL;
		CLSID stCLSID;
		DWORD dwCount;
		LPOLESTR szProgId, szUserType;
		CLSID stCatID = CATID_OPCDAServer20;
		hr = pobjOPCSrvList->EnumClassesOfCategories(1, &stCatID, 1, &stCatID, &pobjEnumGUID);
		if (FAILED(hr))
		{
			printf("EnumClassesOfCategories()����ִ��ʧ�ܣ������룺0x%08X\r\n", hr);
			nRtnVal = -6;
			break;
		}

		//* ��ʼö�ٷ���������ȡָ��ProgID��CLSID
		while (SUCCEEDED(pobjEnumGUID->Next(1, &stCLSID, &dwCount)))
		{
			hr = pobjOPCSrvList->GetClassDetails(stCLSID, &szProgId, &szUserType);
			if (FAILED(hr))
			{
				printf("GetClassDetails()����ִ��ʧ�ܣ������룺0x%08X\r\n", hr);
				nRtnVal = -7;
				break;
			}

			printf("%lls\r\n", szProgId);

			//* �Ƿ�ռ�õ��ڴ�
			CoTaskMemFree(szProgId);
			CoTaskMemFree(szUserType);
		}
	} while (FALSE);
		
	
	CoUninitialize();

	return nRtnVal;
}


//* ��Ҫע�⣬�������Ǳ������64λ�汾����datasink20.cpp��ʹ�õ�OPCHANDLE����DWORD���ͣ��侭����Ϊ����ָ���ַ�ı����������ã�64λ������ָ���ַ
//* Ҳ��64λ�ģ������ͻ�ȱ�Ÿ�32λ��ֵ�����³������й��ϣ�����һ��ע��һ��ʹ�ô���OPCHANDLER�����ĺ������ݵ�ַʱ��Ҫ�ֶ��������������͸�Ϊ64λ��
//* Ҳ���ǲ���ʹ��OPCHANDLER��Ϊ�������ͣ���ʽ�Ĳ���LONG64����
int main(int argc, CHAR* argv[])
{
	__GetRemoteOPCSrvCLSID(argv[1], argv[2], argv[3], NULL, NULL);

    return 0;
}

