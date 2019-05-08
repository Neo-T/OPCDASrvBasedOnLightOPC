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


//* ��Ҫע�⣬�������Ǳ������64λ�汾����datasink20.cpp��ʹ�õ�OPCHANDLE����DWORD���ͣ��侭����Ϊ����ָ���ַ�ı����������ã�64λ������ָ���ַ
//* Ҳ��64λ�ģ������ͻ�ȱ�Ÿ�32λ��ֵ�����³������й��ϣ�����һ��ע��һ��ʹ�ô���OPCHANDLER�����ĺ������ݵ�ַʱ��Ҫ�ֶ��������������͸�Ϊ64λ��
//* Ҳ���ǲ���ʹ��OPCHANDLER��Ϊ�������ͣ���ʽ�Ĳ���LONG64����
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

