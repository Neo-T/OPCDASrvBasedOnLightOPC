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

#include "ag_clocker.h"

#include <list>
#include <vector>
#include "ag_thread.h"

#include "Value.h"
#include "ErrInfoAdapter.h"

// главный 'движок' OPC сервера
#include "opc_Data.h"

#include "NameIndex.h"
#include "ErrorInfoImpl.h"

#include "IOPCServerImpl.h"
#include "IOPCShutdown_CP.h"

#include "IOPCBrowseServerAddressSpaceImpl.h"

#include "OPCBrowser.h"

// COPCServer
class /*ATL_NO_VTABLE*/ COPCServer : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<COPCServer>,
	public IConnectionPointContainerImpl<COPCServer>,
	public AG_IErrorInfoImpl<COPCServer>,
//	public CProxy_IGF_Events<COPCServer>,
//	public AG_EVNT::CGF_EventsReceiver<COPCServer>,
// XL DataAccess
	//public IGF_DataBaseStoreImpl<COPCServer>,
	//public IGF_DataBaseSourceImpl<COPCServer>,
	//public IAG_DataBaseConfigImpl<COPCServer>,
// OPC 2.0
	public IOPCCommonImpl<COPCServer>,
	public IOPCServerImpl<COPCServer>,
	public IOPCItemPropertiesImpl<COPCServer>,
	public CProxy_IOPCShutdown<COPCServer>
{
public:
	COPCServer();
	virtual ~COPCServer();

	/// основной Data manager
	opcData::COPCDataManager m_DM;

//	DECLARE_REGISTRY_RESOURCEID(IDR_OPCSERVER)
//	DECLARE_CLASSFACTORY_SINGLETON(COPCServer)
//	DECLARE_CLASSFACTORY_EX(RSDN::CComClassFactoryPhSingleton<COPCServer>)

	BEGIN_CATEGORY_MAP(COPCServer)
		IMPLEMENTED_CATEGORY(CATID_OPCDAServer20)
	END_CATEGORY_MAP()

	BEGIN_COM_MAP(COPCServer)
// XL DataAccess
		//COM_INTERFACE_ENTRY(IGF_DataBaseStore)
		//COM_INTERFACE_ENTRY(IGF_DataBaseSource)
		//COM_INTERFACE_ENTRY(IAG_DataBaseConfig)
// OPC 2.0		
		COM_INTERFACE_ENTRY(IOPCCommon)
		COM_INTERFACE_ENTRY(IOPCServer)
		COM_INTERFACE_ENTRY(IOPCItemProperties)
//		COM_INTERFACE_ENTRY(IOPCBrowseServerAddressSpace)
		COM_INTERFACE_ENTRY_AGGREGATE(IID_IOPCBrowseServerAddressSpace, m_pBrowserAdapter )

		COM_INTERFACE_ENTRY(IErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
//		COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(COPCServer)
		CONNECTION_POINT_ENTRY(__uuidof(IOPCShutdown))
	END_CONNECTION_POINT_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct()
	{
		ATLTRACE(_T("COPCServer::FinalConstruct()\n"));

		return S_OK;
		//return CoCreateFreeThreadedMarshaler(
		//	GetControllingUnknown(), &m_pUnkMarshaler.p);
	}
	
	void FinalRelease() 
	{
		ATLTRACE(_T("COPCServer::FinalRelease()\n"));
		//m_pUnkMarshaler.Release();
	}

	//CComPtr<IUnknown> m_pUnkMarshaler;

	COPCBrowserAdapter m_BrowserAdapter;
	IUnknown *m_pBrowserAdapter;

public:
	//HRESULT setFileStoreDirectory( LPCTSTR path );
	//virtual HRESULT Event(long cmd,VARIANT val1,VARIANT val2,BSTR IdObject);
};


//OBJECT_ENTRY_AUTO(__uuidof(OPCServer), COPCServer)
extern CComObject<COPCServer> *g_Server;


