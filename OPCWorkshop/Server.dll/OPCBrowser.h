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

class ATL_NO_VTABLE COPCBrowser :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<COPCBrowser>,
	public IOPCBrowseServerAddressSpaceImpl<COPCBrowser>
{
public:
	COPCServer *m_server;

//	DECLARE_PROTECT_FINAL_CONSTRUCT()

	COPCBrowser();
	virtual ~COPCBrowser();
	void FinalRelease();

	BEGIN_COM_MAP(COPCBrowser)
		COM_INTERFACE_ENTRY(IOPCBrowseServerAddressSpace)
	END_COM_MAP()
};

/// класс который агрегируется в COPCServer и на каждый QueryInterface ( IID_IOPCBrowseServerAddressSpace ) 
/// отдает новую копию класса броузера 
class COPCBrowserAdapter :
	public IUnknown
	//public CComObjectRootEx<CComMultiThreadModel>,
	//public CComCoClass<COPCBrowserAdapter>
{
///  IUnknown implementation.
	ULONG m_dwRef; /// внутренний счетчик ссылок	
	CComAutoCriticalSection m_sect;
public:
	COPCServer *m_server;

	COPCBrowserAdapter()
	{
		m_server = NULL;
		m_dwRef = 0;
	}

	//void Lock() {}
	//void Unlock() {}

// -------------------------------------------------------------------------------------------
///  IUnknown implementation.

	STDMETHOD(QueryInterface) (REFIID iid, void** ppv);

	STDMETHOD_(ULONG,AddRef) (void)
	{
		thread::CCritSectLocker locker( m_sect );
		return ++m_dwRef;
	}

	STDMETHOD_(ULONG,Release) (void)
	{
		thread::CCritSectLocker locker( m_sect );
		if (0 != --m_dwRef)
			return m_dwRef;

	//	delete this;
		return 0;
	}

/*
	//if _InternalQueryInterface is undefined then you forgot BEGIN_COM_MAP
	HRESULT _InternalQueryInterface(REFIID iid, void** ppvObject) throw()
	{
		if( iid == IID_IUnknown) {
			*ppvObject = (IUnknown*)(this);
			InternalAddRef();
			return S_OK;
		}
		if( iid == IID_IOPCBrowseServerAddressSpace ) {
			CComObject<COPCBrowser> *br = NULL;
			CComObject<COPCBrowser>::CreateInstance( & br );
			if( br )
				return br->QueryInterface( iid, ppvObject );
			else 
				return E_FAIL;
		}
		return E_NOINTERFACE;
	}
*/
};
