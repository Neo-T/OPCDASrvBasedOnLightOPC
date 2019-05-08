// iDCOMTestClient.cpp : 定义控制台应用程序的入口点。
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
				printf("CoTaskMemAlloc()函数执行失败!\r\n");
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
			stCoAuthInfo.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;	//* 必须是模拟登陆
			stCoAuthInfo.pAuthIdentityData = &stCoAuthID;
			stCoAuthInfo.dwCapabilities = EOAC_NONE;						

			mbstowcs(stCoServerInfo.pwszName, "192.168.xxx.xxx", nSize);			
			stCoServerInfo.pAuthInfo = &stCoAuthInfo;
			stCoServerInfo.dwReserved1 = 0;
			stCoServerInfo.dwReserved2 = 0;	

			MULTI_QI stMultiQI; 		
			ZeroMemory(&stMultiQI, sizeof(stMultiQI));
			stMultiQI.pIID = &IID_IArithmeticLib;	//* 参见iDCOMTestSrv_i.c
			stMultiQI.pItf = NULL; 

			//* 初始化安全结构，模拟登录远程机器
			hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
			if(!(SUCCEEDED(hr) || RPC_E_TOO_LATE == hr))
			{
				printf("CoInitializeSecurity()函数执行失败，错误码：0x%08X\r\n", hr);
				break;
			}

			//* 建立COM组件实例并按照需求获取查询接口
			hr = CoCreateInstanceEx(CLSID_ArithmeticLib,	//* 参见iDCOMTestSrv_i.c
									NULL, 
									CLSCTX_REMOTE_SERVER,	//* 显式的指定要连接远程机器
									&stCoServerInfo, 
									sizeof(stMultiQI)/sizeof(MULTI_QI), 
									&stMultiQI);

			//* 无论成功与否，先释放刚才申请的内存
			CoTaskMemFree(stCoServerInfo.pwszName);	

			//* 如果CoCreateInstanceEx()执行失败
			if(FAILED(hr)) 
			{
				printf("CoCreateInstanceEx()函数执行失败，错误码：0x%08X\r\n", hr);
				break;
			}

			//* 如果没有获取到DCOM组件的查询接口
			if(FAILED(stMultiQI.hr))
			{
				printf("获取组件的查询接口失败，错误码：0x%08X\r\n", stMultiQI.hr);
				break;
			}

			//* 查询并获取组件的调用接口，获取完毕后直接释放即可
			IArithmeticLib *piobjArithmetic = NULL;
			stMultiQI.pItf->QueryInterface(&piobjArithmetic);
			stMultiQI.pItf->Release();

			//* 接收用户输入并调用远程组件获得计算结果
			INT blIsRunning = TRUE;
			while(blIsRunning)
			{
				INT nEnterFunCode;
				INT nNum1, nNum2, nResult;

				printf("1: 加; 2: 减; 0: 退出");
				scanf("%d", &nEnterFunCode);

				switch(nEnterFunCode)
				{
				case 1:
					printf("请输入相加的两个整型数字（空格分开）：");
					scanf("%d%d", &nNum1, &nNum2);
					piobjArithmetic->add(nNum1, nNum2, &nResult);
					printf("[加]操作结果为：%d\r\n", nResult);
					break;

				case 2:
					printf("请输入相减的两个整型数字（空格分开）：");
					scanf("%d%d", &nNum1, &nNum2);
					piobjArithmetic->sub(nNum1, nNum2, &nResult);
					printf("[减]操作结果为：%d\r\n", nResult);
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

