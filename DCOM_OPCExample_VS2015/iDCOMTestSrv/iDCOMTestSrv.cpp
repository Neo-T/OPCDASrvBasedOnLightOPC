// iDCOMTestSrv.cpp : WinMain 的实现


#include "stdafx.h"
#include "resource.h"
#include "iDCOMTestSrv_i.h"


using namespace ATL;

#include <stdio.h>

class CiDCOMTestSrvModule : public ATL::CAtlServiceModuleT< CiDCOMTestSrvModule, IDS_SERVICENAME >
{
public :
	DECLARE_LIBID(LIBID_iDCOMTestSrvLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IDCOMTESTSRV, "{9D17DCE8-2F22-4893-A9C1-659AC7274E98}")
		HRESULT InitializeSecurity() throw()
	{
		// TODO : 调用 CoInitializeSecurity 并为服务提供适当的安全设置
		// 建议 - PKT 级别的身份验证、
		// RPC_C_IMP_LEVEL_IDENTIFY 的模拟级别
		// 以及适当的非 NULL 安全描述符。

		return S_OK;
	}
	};

CiDCOMTestSrvModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

