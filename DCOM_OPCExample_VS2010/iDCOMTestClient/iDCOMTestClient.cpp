// iDCOMTestClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include "iDCOMTestSrv_i.h"
#include "iDCOMTestSrv_i.c"

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);
	{
		do{
			HRESULT hr;

			COSERVERINFO stCoServerInfo;
			COAUTHINFO stCoAuthInfo;
			COAUTHIDENTITY stCoAuthID;
			INT nSize = strlen("192.168.xxx.xxx") * sizeof(WCHAR);
			memset(&stCoServerInfo, 0, sizeof(stCoServerInfo));
			stCoServerInfo.pwszName = (WCHAR *)CoTaskMemAlloc(nSize * sizeof(WCHAR));
			if(!stCoServerInfo.pwszName)								
			{
				printf("CoTaskMemAlloc()����ִ��ʧ��!\r\n");
				break;
			}

			ZeroMemory(&stCoAuthID, sizeof(COAUTHIDENTITY));
			stCoAuthID.User =  reinterpret_cast<USHORT *>("user");
			stCoAuthID.UserLength = strlen("user");
			stCoAuthID.Domain = reinterpret_cast<USHORT *>("");
			stCoAuthID.DomainLength = 0;
			stCoAuthID.Password = reinterpret_cast<USHORT *>("password");
			stCoAuthID.PasswordLength = strlen("password");
			stCoAuthID.Flags = SEC_WINNT_AUTH_IDENTITY_ANSI;
		
			ZeroMemory(&stCoAuthInfo, sizeof(COAUTHINFO));
			stCoAuthInfo.dwAuthnSvc =  RPC_C_AUTHN_WINNT;
			stCoAuthInfo.dwAuthzSvc = RPC_C_AUTHZ_NONE;
			stCoAuthInfo.pwszServerPrincName = NULL;
			stCoAuthInfo.dwAuthnLevel = RPC_C_AUTHN_LEVEL_CONNECT;
			stCoAuthInfo.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;	//* ������ģ���½
			stCoAuthInfo.pAuthIdentityData = &stCoAuthID;
			stCoAuthInfo.dwCapabilities = EOAC_NONE;						

			mbstowcs(stCoServerInfo.pwszName, "192.168.xxx.xxx", nSize);			
			stCoServerInfo.pAuthInfo = &stCoAuthInfo;
			stCoServerInfo.dwReserved1 = 0;
			stCoServerInfo.dwReserved2 = 0;	

			MULTI_QI stMultiQI; 		
			ZeroMemory(&stMultiQI, sizeof(stMultiQI));
			stMultiQI.pIID = &IID_IArithmeticLib;	//* �μ�iDCOMTestSrv_i.c
			stMultiQI.pItf = NULL; 

			//* ��ʼ����ȫ�ṹ��ģ���¼Զ�̻���
			hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
			if(!(SUCCEEDED(hr) || RPC_E_TOO_LATE == hr))
			{
				printf("CoInitializeSecurity()����ִ��ʧ�ܣ������룺0x%08X\r\n", hr);
				break;
			}

			//* ����COM���ʵ�������������ȡ��ѯ�ӿ�
			hr = CoCreateInstanceEx(CLSID_ArithmeticLib,	//* �μ�iDCOMTestSrv_i.c
									NULL, 
									CLSCTX_REMOTE_SERVER,	//* ��ʽ��ָ��Ҫ����Զ�̻���
									&stCoServerInfo, 
									sizeof(stMultiQI)/sizeof(MULTI_QI), 
									&stMultiQI);

			//* ���۳ɹ�������ͷŸղ�������ڴ�
			CoTaskMemFree(stCoServerInfo.pwszName);	

			//* ���CoCreateInstanceEx()ִ��ʧ��
			if(FAILED(hr)) 
			{
				printf("CoCreateInstanceEx()����ִ��ʧ�ܣ������룺0x%08X\r\n", hr);
				break;
			}

			//* ���û�л�ȡ��DCOM����Ĳ�ѯ�ӿ�
			if(FAILED(stMultiQI.hr))
			{
				printf("��ȡ����Ĳ�ѯ�ӿ�ʧ�ܣ������룺0x%08X\r\n", stMultiQI.hr);
				break;
			}

			//* ��ѯ����ȡ����ĵ��ýӿڣ���ȡ��Ϻ�ֱ���ͷż���
			IArithmeticLib *piobjArithmetic = NULL;
			stMultiQI.pItf->QueryInterface(&piobjArithmetic);
			stMultiQI.pItf->Release();

			//* �����û����벢����Զ�������ü�����
			INT blIsRunning = TRUE;
			while(blIsRunning)
			{
				INT nEnterFunCode;
				INT nNum1, nNum2, nResult;

				printf("1: ��; 2: ��; 0: �˳�");
				scanf("%d", &nEnterFunCode);

				switch(nEnterFunCode)
				{
				case 1:
					printf("��������ӵ������������֣��ո�ֿ�����");
					scanf("%d%d", &nNum1, &nNum2);
					piobjArithmetic->add(nNum1, nNum2, &nResult);
					printf("[��]�������Ϊ��%d\r\n", nResult);
					break;

				case 2:
					printf("����������������������֣��ո�ֿ�����");
					scanf("%d%d", &nNum1, &nNum2);
					piobjArithmetic->sub(nNum1, nNum2, &nResult);
					printf("[��]�������Ϊ��%d\r\n", nResult);
					break;

				case 0:
				default:
					blIsRunning = FALSE;
					break;
				}
			}
		}while(FALSE);		
	}
	CoUninitialize();

	return 0;
}

