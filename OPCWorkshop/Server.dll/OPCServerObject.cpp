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

#include "StdAfx.h"
#include <atlsafe.h>

#include "ag_thread.h"
#include "NameIndex.h"

#include "opc.h"
#include "opc_Data.h"
#include "opc_impl.h"

#include "OPCServer.h"
#include "myCF.h"
#include "opcServerObject.h"

#include "opcDataTranslator.h"

static COPCDataTranslator *g_DataTranslator = NULL;
ExportClass FILETIME FILETIME_NULL = {0,0};

COPCServerObject::COPCServerObject(void)
{
	if( !g_DataTranslator )
		g_DataTranslator= new COPCDataTranslator();
}

const DWORD COPCServerObject::QualityGood = OPC_QUALITY_GOOD;
const DWORD COPCServerObject::QualityBad = OPC_QUALITY_BAD;

COPCServerObject::~COPCServerObject(void)
{
	if( g_DataTranslator ) {
		delete g_DataTranslator; 
		g_DataTranslator = NULL;
	}
}


/// Установить имя объект?сервер?
void COPCServerObject::setServerProgID(LPCTSTR progID)
{
	OPCServerProgID = progID;
}

/// установить CLSID сервер?
void COPCServerObject::setServerCLSID(REFCLSID progID)
{
	CLSID_OPCServerEXE  = progID;
}


/// зарегистрировать сервер ?систем?
int COPCServerObject::RegisterServer()
{
	char np[FILENAME_MAX + 32];
	printf("Registering");
	GetModuleFileName(NULL, np, sizeof(np) - 8);

	return ServerRegister(&CLSID_OPCServerEXE, 
                               OPCServerProgID,
							   "OPCServer (c) Alexey Obukhov", np, 0);
}

/// резрегистрироват?сервер ?систем?
int COPCServerObject::UnregisterServer()
{
	return ServerUnregister(&CLSID_OPCServerEXE, OPCServerProgID);
}

/// запустит?сервер
int COPCServerObject::StartServer(OPCSERVERSTATE state)
{
	HRESULT hr = CoRegisterClassObject(CLSID_OPCServerEXE, &my_CF,
                                        CLSCTX_LOCAL_SERVER |
                                        CLSCTX_REMOTE_SERVER |
                                        CLSCTX_INPROC_SERVER,
	                                    REGCLS_MULTIPLEUSE, &m_objid);
	if(SUCCEEDED(hr))
		my_CF.serverAdd();
	
	my_CF.CreateServer();
	g_Server->m_ServerStatus.dwServerState = state;

	return FAILED(hr);
}

void COPCServerObject::SetServerState(OPCSERVERSTATE state)
{
	g_Server->m_ServerStatus.dwServerState = state;
}

/// отстановит?процес?сервер?
int COPCServerObject::StopServer()
{
	g_Server->m_ServerStatus.dwServerState = OPC_STATUS_FAILED;
	g_DataTranslator->Unsubscribe( );
	my_CF.CreateServer( false );
    HRESULT hr = CoRevokeClassObject(m_objid);
	return FAILED(hr);
}

void COPCServerObject::SetDelimeter( const char *ch )
{
	strcpy( g_BrowseNameDelimeter , ch );
}

extern CBrowseItemsList g_BrowseItems;

/// добавить те??базу сервер?
///		пр?этом указывается ти?тега ?возможност?клиент?писать ?этот параметр
void COPCServerObject::AddTag( LPCTSTR name, VARTYPE type, bool readOnly)
{
	if( g_BrowseItems.find( name ) == g_BrowseItems.end() )  // проверка на существовани?тега
	{
		DWORD new_index = g_NameIndex[ name ];
		g_BrowseItems.push_back( CItemForBrowse( new_index, name , type, 
			readOnly ? OPC_READABLE : OPC_READABLE | OPC_WRITEABLE ) );		
	}
}

/// передать значение параметр?
bool COPCServerObject::WriteValue( LPCTSTR name, FILETIME ft, WORD quality, VARIANT &value )
{
	CBrowseItemsList::iterator it = g_BrowseItems.find( name );
	if(it == g_BrowseItems.end()) return false;

	CAG_Value adapt;
	adapt.m_Name = name;
	adapt.m_NameId = g_NameIndex[ name ];
	adapt.m_Value = value;
	adapt.m_Quality = quality;

	if( ft == FILETIME_NULL )
		CoFileTimeNow( &adapt.m_Time );
	else
		adapt.m_Time = ft;

	adapt.m_Type = value.vt;

	return SUCCEEDED( g_Server->m_DM.pushNewData( adapt ) );
}

bool COPCServerObject::WriteValue( LPCTSTR name, FILETIME ft, WORD quality, int value )
{
	CComVariant var = value;
	return WriteValue( name, ft, quality, var );
}
bool COPCServerObject::WriteValue( LPCTSTR name, FILETIME ft, WORD quality, float value )
{
	CComVariant var = value;
	return WriteValue( name, ft, quality, var );
}
bool COPCServerObject::WriteValue( LPCTSTR name, FILETIME ft, WORD quality, double value )
{
	CComVariant var = value;
	return WriteValue( name, ft, quality, var );
}
bool COPCServerObject::WriteValue( LPCTSTR name, FILETIME ft, WORD quality, int* value , unsigned count )
{
	CComSafeArray<int> var;
	var.Add( count, value );
	return WriteValue( name, ft, quality, CComVariant(var) );
}
bool COPCServerObject::WriteValue( LPCTSTR name, FILETIME ft, WORD quality, float* value, unsigned count )
{
	CComSafeArray<float> var;
	var.Add( count, value );
	return WriteValue( name, ft, quality,CComVariant(var) );
}
bool COPCServerObject::WriteValue( LPCTSTR name, FILETIME ft, WORD quality, double* value, unsigned count )
{
	CComSafeArray<double> var;
	var.Add( count, value );
	return WriteValue( name, ft, quality, CComVariant(var) );
}

void COPCServerObject::setDataReceiver( COPCReceiveData *receiver)
{
	if( g_Server == NULL )
		my_CF.CreateServer();

	g_DataTranslator->setDataReceiver( receiver );
	g_DataTranslator->SetAcceptAll( true );
	g_DataTranslator->Subscribe( &g_Server->m_DM );
}

