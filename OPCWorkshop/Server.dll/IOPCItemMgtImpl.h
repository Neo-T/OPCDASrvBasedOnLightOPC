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

namespace Ag_OPC {

#define VALIDATE_ARGUMENT(a) if(a == NULL) return E_INVALIDARG;


template <class T>
class IOPCItemMgtImpl :
	public IOPCItemMgt
{
public:

	STDMETHOD(AddItems)( /*[in]*/ DWORD dwCount, 
		/*[in, size_is(dwCount)]*/ OPCITEMDEF * pItemArray, 
		/*[out, size_is(,dwCount)]*/ OPCITEMRESULT ** ppAddResults, 
		/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors ) 
	{ 
		OPC_GROUP_CHECK_DELETED();
//		T* pT = static_cast<T*> (this);

		HRESULT res = S_OK;
		if(pItemArray == NULL || ppAddResults == NULL || ppErrors == NULL)
			return E_INVALIDARG;

		if( dwCount == 0 ) return S_OK;
		*ppAddResults = (OPCITEMRESULT *)CoTaskMemAlloc( sizeof(OPCITEMRESULT) * dwCount );
		if( *ppAddResults == NULL ) return E_OUTOFMEMORY;
		ZeroMemory( *ppAddResults, sizeof(OPCITEMRESULT) * dwCount );

		*ppErrors = (HRESULT*)CoTaskMemAlloc( sizeof(HRESULT) * dwCount );
		if( *ppErrors == NULL ) { CoTaskMemFree(*ppAddResults); return E_OUTOFMEMORY; }
		ZeroMemory( *ppErrors, sizeof(HRESULT) * dwCount );


		for( DWORD i=0;i<dwCount; ++i) {
			OPCITEMDEF &pItem = pItemArray[i];
			OPCITEMRESULT &pResult = (*ppAddResults)[i];

			OPCHANDLE hServer = g_NameIndex[ CString(pItem.szItemID) ];

			CBrowseItemsList::iterator browseIT = g_BrowseItems.find( hServer );
			if( browseIT == g_BrowseItems.end() ) {
				(*ppErrors)[i] = E_FAIL;
				continue;
			}

			ItemsInGroup *newItem = NULL;
			{
				CLockWrite locker( pT->m_ItemsAdded );
				// если параметр уж?подключе?то мы клиент?отшиваем - 
				// нефига нескольк?ра?подключать параметр
				if( pT->m_ItemsAdded.find( pItem.hClient ) != pT->m_ItemsAdded.end() ) {
					(*ppErrors)[i] = E_FAIL;
					continue;
				}
				newItem = new ItemsInGroup( pItem.hClient, pItem.bActive );
				pT->m_ItemsAdded.insert( ItemsInGroupMapPair( hServer, newItem ));
				/// указывае?кастомер?на получени?данных /*m_DataCustomer.*/
				pT->AcceptParam( hServer );
			}
			pResult.hServer = hServer;
			pResult.vtCanonicalDataType = (*browseIT).type;
			pResult.dwAccessRights = (*browseIT).dwAccessRights;
			pResult.dwBlobSize = 0;
			pResult.pBlob = NULL;

			/// передаем клиент?пустой параметр посл?того ка?он подписал? на него
			CAG_Value adapt ( pT->m_Manager->getLastValue( hServer ) );
			if( adapt.isNull() ) { 
				// если добавляем параметр на которы?не разу не приходил?данные от источников
				adapt.m_NameId = hServer;
				adapt.m_Name = pItem.szItemID;
				adapt.m_Type = pResult.vtCanonicalDataType;
	//			adapt.m_Value = 0;
				adapt.m_Value.ChangeType( adapt.m_Type );
			}

			pT->pushData( &adapt, true );


//			// добавить указател?на newItem->modified ?список нотификаци?нужног?параметр?сервер?
//			{
//				CLockWrite locker( g_LastValues );
//				CAG_Value &adapt = g_LastValues[ hServer ];
////				newItem->modified = TRUE; // делаем, чт?бы сраз?были послан?данные из буффер?
//				adapt.m_ChangeMonitoring.insert( &(newItem->modified) );
//				ATLASSERT( adapt.m_ChangeMonitoring.find( &(newItem->modified) ) != adapt.m_ChangeMonitoring.end() );
//			}
		}

		return S_OK; 
	}

	STDMETHOD(ValidateItems)( /*[in]*/ DWORD dwCount, 
		/*[in, size_is(dwCount)]*/ OPCITEMDEF * pItemArray, 
		/*[in]*/ BOOL bBlobUpdate, 
		/*[out, size_is(,dwCount)]*/ OPCITEMRESULT ** ppValidationResults, 
		/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors ) 
	{ 
		DWORD i;
		HRESULT res = S_OK;
		OPC_GROUP_CHECK_DELETED();
		
		VALIDATE_ARGUMENT(pItemArray);
		VALIDATE_ARGUMENT(ppValidationResults);
		VALIDATE_ARGUMENT(ppErrors);

		*ppValidationResults = allocate_buffer<OPCITEMRESULT> ( dwCount );
		*ppErrors = allocate_buffer<HRESULT> ( dwCount );

		/// проверяем на наличи?таки?параметров 
		for( i=0;i<dwCount; ++i) {
			OPCHANDLE hServer = g_NameIndex[ CString(pItemArray[i].szItemID) ];
			CBrowseItemsList::iterator browseIT = g_BrowseItems.find( hServer );
			if( browseIT == g_BrowseItems.end() ) {
				(*ppErrors)[i] = OPC_E_UNKNOWNITEMID;
				res = S_FALSE;
			}
			else
			{				
				(*ppValidationResults)->vtCanonicalDataType = browseIT->type;
				break;
			}
		}
		// TODO проверка типа параметр?		

		return res; 
	}

	STDMETHOD(RemoveItems)( /*[in]*/ DWORD dwCount, 
		/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
		/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors ) 
	{ 
		OPC_GROUP_CHECK_DELETED();
		VALIDATE_ARGUMENT(phServer)
		VALIDATE_ARGUMENT(ppErrors)

		*ppErrors = (HRESULT*)CoTaskMemAlloc( sizeof(HRESULT) * dwCount );
		if( *ppErrors == NULL ) { return E_OUTOFMEMORY; }
		ZeroMemory( *ppErrors, sizeof(HRESULT) * dwCount );

		ItemsInGroupMap::iterator it;
		CLockWrite locker( pT->m_ItemsAdded );
		for( DWORD i=0;i<dwCount; i++)  {
			it = pT->m_ItemsAdded.find( phServer[i] );
			if( it == pT->m_ItemsAdded.end())
				(*ppErrors)[i] = E_FAIL;
			else {
				//{
				//	//отсоединит?item->modified от список?нотификаци?нужног?параметр?сервер?
				//	CLockWrite locker( g_LastValues );
				//	g_LastValues[ phServer[i] ].m_ChangeMonitoring.erase( &((*it).second->modified) );
				//}
				pT->DeclineParam( phServer[i] ); /*m_DataCustomer.*/
				pT->m_ItemsAdded.erase( it );
			}
		}
		return S_OK; 
	}

	STDMETHOD(SetActiveState)( /*[in]*/ DWORD dwCount, 
						/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
						/*[in]*/ BOOL bActive, 
						/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors ) 
	{ 
		OPC_GROUP_CHECK_DELETED();
		VALIDATE_ARGUMENT(phServer)
		VALIDATE_ARGUMENT(ppErrors)

		*ppErrors = (HRESULT*)CoTaskMemAlloc( sizeof(HRESULT) * dwCount );
		if( *ppErrors == NULL ) { return E_OUTOFMEMORY; }
		ZeroMemory( *ppErrors, sizeof(HRESULT) * dwCount );

		ItemsInGroupMap::iterator it;
		CLockWrite locker( pT->m_ItemsAdded );
		for( DWORD i=0;i<dwCount; i++) {
			it = pT->m_ItemsAdded.find( phServer[i] );
			if(it == pT->m_ItemsAdded.end())
				(*ppErrors)[i] = E_FAIL;
			else
				(*it).second->bActive = bActive;
		}

		return S_OK; 
	}

	//TODO
	STDMETHOD(SetClientHandles)( /*[in]*/ DWORD dwCount, 
						/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
						/*[in, size_is(dwCount)]*/ OPCHANDLE * phClient, 
						/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors ) 
	{
		OPC_GROUP_CHECK_DELETED();
		VALIDATE_ARGUMENT(phServer)
		VALIDATE_ARGUMENT(phClient)
		VALIDATE_ARGUMENT(ppErrors)

		*ppErrors = (HRESULT*)CoTaskMemAlloc( sizeof(HRESULT) * dwCount );
		if( *ppErrors == NULL ) { return E_OUTOFMEMORY; }
		ZeroMemory( *ppErrors, sizeof(HRESULT) * dwCount );

		ItemsInGroupMap::iterator it;
		CLockWrite locker( pT->m_ItemsAdded );
		for(DWORD i=0;i<dwCount;i++) {
			it = pT->m_ItemsAdded.find( phServer[i] );
			if(it == pT->m_ItemsAdded.end())
				(*ppErrors)[i] = E_FAIL;
			else
				(*it).second->hClient = phClient[i];
		}
		return S_OK; 
	}

	//TODO
	STDMETHOD(SetDatatypes)(  /*[in]*/ DWORD dwCount, 
						/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
						/*[in, size_is(dwCount)]*/ VARTYPE * pRequestedDatatypes, 
						/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors ) 
	{ 
		OPC_GROUP_CHECK_DELETED();
		VALIDATE_ARGUMENT(phServer)
		VALIDATE_ARGUMENT(pRequestedDatatypes)
		VALIDATE_ARGUMENT(ppErrors)

		*ppErrors = (HRESULT*)CoTaskMemAlloc( sizeof(HRESULT) * dwCount );
		if( *ppErrors == NULL ) { return E_OUTOFMEMORY; }
		ZeroMemory( *ppErrors, sizeof(HRESULT) * dwCount );

		ItemsInGroupMap::iterator it;
		CLockWrite locker( pT->m_ItemsAdded );
		for(DWORD i=0;i<dwCount;i++) {
			it = pT->m_ItemsAdded.find( phServer[i] );
			if(it == pT->m_ItemsAdded.end())
				(*ppErrors)[i] = E_FAIL;
			else
				(*it).second->type = pRequestedDatatypes[i];
		}
		return S_OK; 
	}

	//TODO
	STDMETHOD(CreateEnumerator)( /*[in]*/ REFIID riid, 
						/*[out, iid_is(riid)]*/ LPUNKNOWN* ppUnk ) 
	{ 
		OPC_GROUP_CHECK_DELETED();
		return S_OK; 
	}

};
}
using namespace Ag_OPC;
