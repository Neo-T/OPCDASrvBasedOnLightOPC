/***************************************************************************
 *   Copyright (C) 2005 by Alexey Obukhov                                  *
 *   obukhoff@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "stdafx.h"
#include "ag_thread.h"
#include "NameIndex.h"

#include "opc.h"
#include "opc_Data.h"
#include "opc_impl.h"

#include "OPCServer.h"

#include "myCF.h"

// {4EA2713D-CA07-11d4-BEF5-00002120DB5E}   exe-server by default 
GUID CLSID_OPCServerEXE = { 0x4ea2713d, 0xca07, 0x11d4, {0xbe, 0xf5, 0x0, 0x0, 0x21, 0x20, 0xdb, 0x5E} };
CString OPCServerProgID = _T("OPC.Test_OPCServer");
myClassFactory my_CF;


void myClassFactory::serverAdd(void)
{
	EnterCriticalSection(&lk_count);
	if (is_out_of_proc) CoAddRefServerProcess();  
	++server_count;
	LeaveCriticalSection(&lk_count);
}

void myClassFactory::serverRemove(void)
{
	EnterCriticalSection(&lk_count);
	if (is_out_of_proc)
	{
		if (0 == CoReleaseServerProcess())
			server_inuse = 0;
	}
	if (0 == --server_count && server_inuse) server_inuse = 0;
	LeaveCriticalSection(&lk_count);
}

HRESULT myClassFactory::CreateServer(bool create)
{
	static CComAutoCriticalSection m_sect;
	thread::CCritSectLocker locker(m_sect);


	if( create && g_Server == NULL) {
		CComObject<COPCServer>::CreateInstance( &g_Server );
		if( g_Server )
			g_Server->AddRef();
		else return E_FAIL;
	}
	if( !create && g_Server != NULL) {
		g_Server->Fire_ShutdownRequest( L"Close OPC Server Application" );
		g_Server->Release();
		g_Server = NULL;
	}
	return S_OK;
}

STDMETHODIMP myClassFactory::CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid,
											LPVOID *ppvObject)
{
	//  IUnknown *server = 0;
	HRESULT hr = S_OK;

	///* OPTIONAL: security stuff */
	//  OLECHAR *userid = 0;
	//  wchar_t *cuserid;
	//  LONG userno;
	//  static LONG usercount;
	//
	//  userno = InterlockedIncrement(&usercount);
	//
	//  CoQueryClientBlanket(0, 0, 0, 0, 0, (RPC_AUTHZ_HANDLE*)&userid, 0);
	//  if (!userid) userid = L"{unknown}";
	//
	//  UL_WARNING((LOGID, "USER:#%ld <%ls>", userno, userid));
	//  if (use_console)
	//    printf("+Attaching a client #%ld. USERID: <%ls>\n", usercount, userid);
	//
	//  if (cuserid = (wchar_t*)malloc((wcslen(userid) + 16) * sizeof(wchar_t)))
	//    swprintf(cuserid, L"#%ld %ls", userno, userid);
	///* -- end of security stuff */

	if (pUnkOuter)
	{
#if 0 /* Do we support aggregation? */
		if (riid != IID_IUnknown) 
#endif
			return CLASS_E_NOAGGREGATION;
	}

	serverAdd();  /* the lock for a_server_finished() */

	if(FAILED( CreateServer() ) )
		return E_FAIL;


	return g_Server->QueryInterface(riid, ppvObject);
}



static char VendorName[] = "Alexey Obukhov obukhoff@gmail.com";

static void IIDtoStr (char str[40], const GUID* iid)
{
	sprintf (str, "{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		iid->Data1, iid->Data2, iid->Data3, iid->Data4[0], iid->Data4[1],
		iid->Data4[2], iid->Data4[3], iid->Data4[4],
		iid->Data4[5], iid->Data4[6], iid->Data4[7]);
}

int ServerRegister(const GUID *CLSID_Svr, const char *ProgID,
					 const char *Name, const char *exPath,
					 const char *Model /* 0=exe, ""=STA dll, "Both", "Free" ...*/)
{
	HKEY hKey;
	HKEY hKeyAux;
	char sStr[260];
	char sIID [40];
	const char *srvtype = "InprocServer32";
	LONG ec = ERROR_INVALID_PARAMETER;

	if (!ProgID /*|| !exPath*/) goto SetErr;
	if (exPath && !*exPath) exPath = NULL;
	// UL_TRACE((LOGID, "loServerRegister(%s)", ProgID));

	if (0 == Model) srvtype = "LocalServer32";
	/*   {
	char *ext;
	if (0 > extype ||
	(ext = strrchr(exPath, '.')) &&
	!stricmp(ext, ".exe")) srvtype = "LocalServer32";
	}*/

	IIDtoStr (sIID, CLSID_Svr);

	if (ERROR_SUCCESS != (ec = RegCreateKey(HKEY_CLASSES_ROOT, ProgID, &hKey)))
		goto SetErr;

	if (Name) RegSetValue(hKey, NULL, REG_SZ, Name, strlen(Name)+1);
	if (ERROR_SUCCESS != (ec = RegCreateKey(hKey, "CLSID", &hKeyAux)))
		goto Fail;
	ec = RegSetValue(hKeyAux, NULL, REG_SZ, sIID, strlen(sIID)+1);
	RegCloseKey(hKeyAux);
	if (ERROR_SUCCESS != ec) goto Fail;

	if (ERROR_SUCCESS != (ec = RegCreateKey(hKey, "OPC", &hKeyAux)))
		goto Fail;
	{
		HKEY vendor;
		/*        RegSetValue (hKeyAux, NULL, REG_SZ, sIID, strlen(sIID)+1); */
		/* Should "vendor" be a subkey or a named value? */
		if (ERROR_SUCCESS == RegCreateKey(hKeyAux, "Vendor", &vendor))
		{
			RegSetValue(vendor, NULL, REG_SZ, VendorName, sizeof(VendorName));
			RegCloseKey(vendor);
		}
		RegCloseKey(hKeyAux);
	}
	RegCloseKey(hKey);

	sprintf (sStr, "AppID\\%s", sIID);
	if (ERROR_SUCCESS != (ec = RegCreateKey(HKEY_CLASSES_ROOT, sStr, &hKey)))
		goto UnReg;
	if (Name) RegSetValue(hKey, NULL, REG_SZ, Name, strlen(Name)+1);
	/* DllSurrogate=""
	RunAs="Interactive User"
	RemoteServerName= */
	RegCloseKey(hKey);

	sprintf (sStr, "CLSID\\%s", sIID);
	if (ERROR_SUCCESS != (ec = RegCreateKey(HKEY_CLASSES_ROOT, sStr, &hKey)))
		goto UnReg;
	if (Name) RegSetValue(hKey, NULL, REG_SZ, Name, strlen(Name)+1);
	if (exPath)
	{
		if (ERROR_SUCCESS != (ec = RegCreateKey(hKey, srvtype, &hKeyAux)))
			goto Fail;
		ec = RegSetValue(hKeyAux, NULL, REG_SZ, exPath, strlen(exPath)+1);
		if (Model && *Model) /* dll */
			RegSetValueEx(hKeyAux, "ThreadingModel", 0, REG_SZ, 
			(const BYTE*)Model, strlen(Model)+1);
		RegCloseKey(hKeyAux);
		if (ERROR_SUCCESS != ec) goto Fail;
	}
	// The NAIL for DCOMcnfg !!!
	//       RegSetValueEx(hKeyAux, NULL, 0, REG_EXPAND_SZ, exPath, strlen(exPath)+1);
	RegSetValueEx(hKey, "AppID", 0, REG_SZ, (const BYTE*)sIID, strlen(sIID)+1);
	//    RegSetValue(hKey, "AppID", REG_SZ, sIID, strlen(sIID)+1);

	if (ERROR_SUCCESS != (ec = RegCreateKey(hKey, "ProgID", &hKeyAux)))
		goto Fail;
	ec = RegSetValue(hKeyAux, NULL, REG_SZ, ProgID, strlen(ProgID)+1);
	RegCloseKey(hKeyAux);
	if (ERROR_SUCCESS != ec) goto Fail;

	if (FAILED(manageOPCDAcat(CLSID_Svr, 0)))
	{
		RegCloseKey(hKeyAux);
		IIDtoStr (sIID, &CATID_OPCDAServer20);
		sprintf (sStr, "Implemented Categories\\%s", sIID);
		if (ERROR_SUCCESS != (ec = RegCreateKey(hKey, sStr, &hKeyAux)))
			goto Fail;
		RegCloseKey(hKeyAux);
	}
	RegCloseKey(hKey);

	return 0;

Fail:
	RegCloseKey(hKey);
UnReg:
	ServerUnregister(CLSID_Svr, Name);
SetErr:
	SetLastError(ec);
	return -1;
}

int ServerUnregister(const GUID *CLSID_Svr, const char *ProgID)
{
	char sStr[256];
	char sIID [40];
	int offs;
	LONG errs = ERROR_INVALID_PARAMETER, ec = 0;
	IIDtoStr (sIID, CLSID_Svr);

	if (!ProgID || !*ProgID) goto SetErr;

	manageOPCDAcat(CLSID_Svr, -1);

	offs = sprintf(sStr, "%s\\", ProgID);
	strcpy(sStr + offs, "CurrentVersion");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "OPC\\Vendor");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);

	strcpy(sStr + offs, "OPC");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "CLSID");
	errs = RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	if (ERROR_SUCCESS != (ec = RegDeleteKey (HKEY_CLASSES_ROOT, ProgID)))
	{
		if (ERROR_SUCCESS == errs) errs = ec;
	}

	offs = sprintf(sStr, "AppID\\%s\\", sIID);
	strcpy(sStr + offs, "LocalService");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "ServiceParameters");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	sStr[offs - 1] = 0;
	if (ERROR_SUCCESS != (ec = RegDeleteKey (HKEY_CLASSES_ROOT, sStr)))
	{
		if (ERROR_SUCCESS == errs) errs = ec;
	}

	offs = sprintf(sStr, "CLSID\\%s\\", sIID);

	IIDtoStr(sIID, &CATID_OPCDAServer10);
	sprintf(sStr + offs, "Implemented Categories\\%s", sIID);
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	IIDtoStr(sIID, &CATID_OPCDAServer20);
	sprintf(sStr + offs, "Implemented Categories\\%s", sIID);
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "Implemented Categories");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);

	strcpy(sStr + offs, "InprocServer32\\ThreadingModel");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "InprocServer32");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "LocalServer32");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "InprocHandler32");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "ProgID");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	strcpy(sStr + offs, "AppID");
	RegDeleteKey (HKEY_CLASSES_ROOT, sStr);
	sStr[offs - 1] = 0;
	if (ERROR_SUCCESS != (ec = RegDeleteKey (HKEY_CLASSES_ROOT, sStr)))
	{
		if (ERROR_SUCCESS == errs) errs = ec;
	}

SetErr:
	if (ERROR_SUCCESS != errs) 
	{
		SetLastError(errs);
		return -1;
	}
	return 0;
}



HRESULT manageOPCDAcat(const GUID *service, int remove)
{
	HRESULT hr, hri;
	ICatRegister *pcr;

	hri = CoInitialize(0);
	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr, 
		NULL, CLSCTX_INPROC_SERVER, 
		IID_ICatRegister, (void **)&pcr );

	if (SUCCEEDED(hr))
	{
		CATID catid[2];

		if (0 == remove)
		{
			CATEGORYINFO catinf[1];
			catinf[0].catid = CATID_OPCDAServer20;
			wcscpy(catinf[0].szDescription, L"OPC Data Access Servers Version 2.0");
			catinf[0].lcid = 0x0409;

			hr = pcr->RegisterCategories(1, catinf);
		}

		catid[0] = CATID_OPCDAServer20;
		catid[1] = CATID_OPCDAServer10;

		hr = remove? pcr->UnRegisterClassImplCategories(*service, 2, catid):
		pcr->RegisterClassImplCategories(*service, 1, catid);
		pcr->Release();
	}
	if (SUCCEEDED(hri)) 
		CoUninitialize();

	return hr;
}
