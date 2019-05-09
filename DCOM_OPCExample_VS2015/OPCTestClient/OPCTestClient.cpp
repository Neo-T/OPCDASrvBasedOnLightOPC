// OPCTestClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <cstring>
#include "opccomn.h"
#include "opcda.h"
#include "OpcEnum.h"

//* ��ȡָ�����Ƶ�OPC��������CLSID
static INT __GetRemoteOPCSrvCLSIDByRegistry(CHAR *pszIPAddr, CHAR *pszUserName, CHAR *pszPassword, CHAR *pszOPCSrvProgID, CHAR *pszOPCSrvCLSID)
{
	INT nRtnVal = 0;

	//* ��¼Զ�̼����
	HANDLE hToken;
	if (!LogonUser(pszUserName, pszIPAddr, pszPassword, LOGON32_LOGON_NEW_CREDENTIALS, LOGON32_PROVIDER_DEFAULT, &hToken))
	{
		printf("�޷�����IP��ַΪ%s�ļ�����������룺%d", pszIPAddr, GetLastError());
		return -1;
	}

	//* ģ�⵱ǰ��¼���û�
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
				printf("�޷�����IP��ַΪ%s�ļ�����������룺%d", pszIPAddr, dwRtnVal);
				nRtnVal = -2;
				break;
			}

			printf("�ɹ�����IP��ַΪ%s�ļ��������ʼö�ٸü����ϵͳ�ϵ�ע���...\r\n", pszIPAddr);

			//* ��ȡָ����ֵ
			if (RegEnumKey(hKey, dwIdx, szKey, dwLen) == ERROR_SUCCESS)
			{
				HKEY hSubKey;

				//* ��ָ�����Ƶ�OPC���������ڵļ������������"OPC.LightOPC-exe"
				sprintf(szKey, pszOPCSrvProgID);

				//* ��ָ����ֵ��ȡֵ
				if (RegOpenKey(hKey, szKey, &hSubKey) == ERROR_SUCCESS)
				{
					memset(szCLSID, 0, sizeof(szCLSID));
					lSize = sizeof(szCLSID) - 1;
					if (RegQueryValue(hSubKey, "CLSID", szCLSID, &lSize) == ERROR_SUCCESS)
					{
						if (RegQueryValue(hSubKey, "OPC", NULL, NULL) == ERROR_SUCCESS)
						{
							sprintf(pszOPCSrvCLSID, "%s", szCLSID);
							printf("��%s���������ҵ���%s\r\n", pszOPCSrvProgID, pszOPCSrvCLSID);
						}
						else
						{
							printf("��ѯOPC��ʧ�ܣ������룺%d\r\n", GetLastError());
							nRtnVal = -6;
						}
					}
					else
					{ 
						printf("��ѯCLSID��ʧ�ܣ������룺%d\r\n", GetLastError());
						nRtnVal = -5;
					}

					RegCloseKey(hSubKey);					
				}
				else
				{
					printf("RegOpenKey()����ִ��ʧ�ܣ������룺%d\r\n", GetLastError());
					nRtnVal = -4;
				}
			}
			else
			{
				printf("RegEnumKey()����ִ��ʧ�ܣ������룺%d\r\n", GetLastError());
				nRtnVal = -3;
			}

		} while (FALSE);		
	}	
	RevertToSelf();	//* ����ģ��

	return nRtnVal;
}

//* ��ȡָ�����Ƶ�OPC��������CLSID
static INT __GetRemoteOPCSrvCLSIDByOPCEnum(CHAR *pszIPAddr, CHAR *pszUserName, CHAR *pszPassword, CHAR *pszOPCSrvProgID, CHAR *pszOPCSrvCLSID)
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
		stMultiQI.pIID = &IID_IOPCServerList;	//* �μ�opccomn_i.c
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

		//* ���û�л�ȡ��DCOM����Ĳ�ѯ��
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
		DWORD dwCeltFetchedNum;
		LPOLESTR wszProgID, wszUserType;
		CLSID stCatID = CATID_OPCDAServer20;
		hr = pobjOPCSrvList->EnumClassesOfCategories(1, &stCatID, 1, &stCatID, &pobjEnumGUID);
		if (FAILED(hr))
		{
			printf("EnumClassesOfCategories()����ִ��ʧ�ܣ������룺0x%08X\r\n", hr);
			nRtnVal = -6;
			break;
		}

		//* ��ʼö�ٷ���������ȡָ��ProgID��CLSID
		while (SUCCEEDED(pobjEnumGUID->Next(1, &stCLSID, &dwCeltFetchedNum)))
		{
			if (!dwCeltFetchedNum)
				break;
			hr = pobjOPCSrvList->GetClassDetails(stCLSID, &wszProgID, &wszUserType);
			if (FAILED(hr))
			{
				printf("GetClassDetails()����ִ��ʧ�ܣ������룺0x%08X\r\n", hr);
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
				printf("��%s���������ҵ���%s\r\n", pszOPCSrvProgID, pszOPCSrvCLSID);

				//* �ͷ�ռ�õ��ڴ�
				CoTaskMemFree(wszProgID);
				CoTaskMemFree(wszUserType);

				break;
			}			

			//* �ͷ�ռ�õ��ڴ�
			CoTaskMemFree(wszProgID);
			CoTaskMemFree(wszUserType);
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
	CHAR szCLSID[100];

	__GetRemoteOPCSrvCLSIDByOPCEnum(argv[1], argv[2], argv[3], argv[4], szCLSID);
	__GetRemoteOPCSrvCLSIDByRegistry(argv[1], argv[2], argv[3], argv[4], szCLSID);

    return 0;
}

