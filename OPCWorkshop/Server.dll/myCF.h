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
 
 #pragma once

extern GUID CLSID_OPCServerEXE;
extern CString OPCServerProgID;

/**** Server Counting stuff & OLE ICF implementation *****************************
  The IClassFactory is unavoidable evil. Feel free to go ahead.
  Basically we've to unload when the server_count being zero.
  But there are different techniques for in-/out-of- proc servers.
*/

class myClassFactory : 
	public IClassFactory
{
public:
 int  is_out_of_proc, 
      server_inuse; /* go 0 when unloading initiated */
 LONG server_count;
 CRITICAL_SECTION lk_count;  /* protect server_count */

	myClassFactory(): is_out_of_proc(0), server_inuse(0), server_count(0)
   {
      InitializeCriticalSection(&lk_count);
   }

	~myClassFactory()
   {
      DeleteCriticalSection(&lk_count);
   }

  void serverAdd(void);
  void serverRemove(void);

/* Do nothing: we're static, he-he */  
  STDMETHODIMP_(ULONG) AddRef(void) { return 1; }
  STDMETHODIMP_(ULONG) Release(void) { return 1; }

	STDMETHODIMP QueryInterface(REFIID iid, LPVOID *ppInterface)
    {
      if (ppInterface == NULL)
        return E_INVALIDARG;
      if (iid == IID_IUnknown || iid == IID_IClassFactory)
        {
//          UL_DEBUG((LOGID, "myClassFactory::QueryInterface() Ok"));
          *ppInterface = this;
          AddRef();
          return S_OK;
        }
  //    UL_DEBUG((LOGID, "myClassFactory::QueryInterface() Failed"));
      *ppInterface = NULL;
      return E_NOINTERFACE;
    }

	STDMETHODIMP LockServer(BOOL fLock)
    {
    //  UL_DEBUG((LOGID, "myClassFactory::LockServer(%d)", fLock));
      if (fLock) serverAdd();
      else serverRemove();
      return S_OK;
    }

	STDMETHODIMP CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid,
                              LPVOID *ppvObject);

	static HRESULT CreateServer(bool create = true);
};

extern myClassFactory my_CF;

HRESULT manageOPCDAcat(const GUID *service, int remove);
int ServerUnregister(const GUID *CLSID_Svr, const char *ProgID);
int ServerRegister(const GUID *CLSID_Svr, const char *ProgID,
                     const char *Name, const char *exPath,
                     const char *Model /* 0=exe, ""=STA dll, "Both", "Free" ...*/);

