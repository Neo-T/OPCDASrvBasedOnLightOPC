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

// OPCServer.cpp : Implementation of COPCServer
#include "stdafx.h"
//#include "resource.h"       // main symbols

#include "ag_thread.h"
#include "NameIndex.h"

#include "opc.h"
#include "opc_Data.h"
#include "opc_impl.h"

#include "ag_utils.h"
#include "ag_clocker.h"

#include "OPCServer.h"
#include "OPCBrowser.h"


TCHAR g_BrowseNameDelimeter[20] = _T(".");

////////////////////////////////////////////////////////////////////////////////////////

COPCBrowser::COPCBrowser()
{
	m_server = NULL;
	m_BrowsePosition = _T("");
}

COPCBrowser::~COPCBrowser()
{

}

void COPCBrowser::FinalRelease() 
{
	if(m_server) { // отпускае?сервер ?? прибил?объект броузе?
		m_server->Release();
		m_server = NULL;
	}
}


STDMETHODIMP COPCBrowserAdapter::QueryInterface(REFIID iid, void** ppv)
{
	*ppv = NULL;

	if( iid == IID_IUnknown) {
		*ppv = (IUnknown*)(this);
		AddRef();
		return S_OK;
	}
	if( iid == IID_IOPCBrowseServerAddressSpace ) {
		CComObject<COPCBrowser> *br = NULL;
		CComObject<COPCBrowser>::CreateInstance( & br );
		if( br ) {
			if(m_server)
				m_server->AddRef(); // чт?бы на?сервер не упол?бе?браузера
			br->m_server = m_server;
			return br->QueryInterface( iid, ppv );
		}
		else 
			return E_FAIL;
	}
	return E_NOINTERFACE;
}
