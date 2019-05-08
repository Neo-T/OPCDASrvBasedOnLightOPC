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


//* 需要注意，由于我们编译的是64位版本，而datasink20.cpp中使用的OPCHANDLE则是DWORD类型，其经常作为保存指针地址的变量类型来用，64位机器的指针地址
//* 也是64位的，这样就会缺号高32位数值，导致程序运行故障，所以一定注意一旦使用带有OPCHANDLER参数的函数传递地址时，要手动将函数参数类型改为64位，
//* 也就是不再使用OPCHANDLER作为参数类型，显式的采用LONG64类型
int main()
{
	HRESULT hr = S_OK;
	MULTI_QI mqi;
	COSERVERINFO sin;
	CComPtr<IOPCServerList> spServerList = NULL;

	WCHAR wszNodeName[256];
	memset(wszNodeName, 0, 256);

	// remote node name
	wcscpy(wszNodeName, L"RemoteComputerName");

	// create opc server list object
	if (wcslen(wszNodeName) <= 0)
	{
		// local server enumerate		                      
		hr = CoCreateInstance(CLSID_OpcServerList, NULL, CLSCTX_ALL,
			__uuidof(IOPCServerList), (LPVOID *)&spServerList);
		if (FAILED(hr))
		{
			printf("Error: Could not load local OPC Server Enumerator Object\r\n");
			return 0;
		}
	}
	else
	{
		sin.dwReserved1 = 0;
		sin.dwReserved2 = 0;
		sin.pwszName = wszNodeName;
		sin.pAuthInfo = NULL;

		mqi.pIID = &__uuidof(IOPCServerList);
		mqi.hr = 0;
		mqi.pItf = 0;

		hr = CoCreateInstanceEx(CLSID_OpcServerList, NULL, CLSCTX_REMOTE_SERVER, &sin, 1, &mqi);
		if (FAILED(hr) || FAILED(mqi.hr))
		{
			printf("Error: Could not load OPC Server Enumerator Object\r\n");
			return 0;
		}

		spServerList = (IOPCServerList *)mqi.pItf;
	}

	// enumerate server list
	IEnumGUID *pEnumGUID = NULL;
	CLSID clsId;
	DWORD count;
	LPOLESTR szProgId, szUserType;
	CLSID catId = CATID_OPCDAServer20;

	hr = spServerList->EnumClassesOfCategories(1, &catId, 1, &catId, &pEnumGUID);
	if (FAILED(hr))
		return 0;

	while (SUCCEEDED(pEnumGUID->Next(1, &clsId, &count)))
	{
		hr = spServerList->GetClassDetails(clsId, &szProgId, &szUserType);
		if (FAILED(hr))
			return 0;

		// do your own things with zProgId
		// TODO

		printf("%lls\r\n", szProgId);

		// probably want to save the class id in the item data field for this entry.
		CoTaskMemFree(szProgId);
		CoTaskMemFree(szUserType);
	}

    return 0;
}

