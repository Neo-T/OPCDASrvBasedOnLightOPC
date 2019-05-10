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
//#include "resource.h"       // main symbols

#include "ag_thread.h"
#include "opc.h"
#include "opc_Data.h"
#include "opc_impl.h"

#include "OpcGroup.h"

void COPCGroup::sendChangedDataToClient()
{
	DWORD i;
	CLockWrite locker( m_ItemsAdded );

	thread::CCritSectLocker locker2( m_FilteredDataSect );

	/// сначал?отфильтруе?вс?неактивные теги 
	std::map<OPCHANDLE,CAG_Value>::iterator it,it2; 
	for( it = m_FilteredData.begin(); it != m_FilteredData.end(); ) {
		CAG_Value &value = (*it).second;
		ItemsInGroup *item = (*m_ItemsAdded.find( value.m_NameId )).second;
		if( item ) 
			if( !item->bActive ) {
				it2 = it; ++it2; // бере?следующи?
				m_FilteredData.erase(it); // удаляем неактивный те?
				it = it2; // встаем на следующи?элемен?
				continue; // пропускаем перехо?цикл?на следующи?элемен?
			}
		++it;
	}

	/// поддержк?асинхронного чтен? 
	{
		thread::CCritSectLocker locker( m_AsyncReadSect );
		std::set<OPCHANDLE>::iterator it;
		for( it = m_AsyncRead.begin(); it != m_AsyncRead.end(); ++it) {
			// если такого параметр?не??сиписк?на отсылк?
			if(m_FilteredData.find( *it ) == m_FilteredData.end() )
				m_FilteredData.insert( std::pair<OPCHANDLE,CAG_Value>( *it, m_LastValues[*it] ));
		}
		m_AsyncRead.erase( m_AsyncRead.begin(), m_AsyncRead.end() );
	}


	/// ?теперь вс?чт?осталось отошле?получателю
	DWORD dwCount = m_FilteredData.size();
	if( dwCount == 0) return; // ту?делать нечего

	OPCHANDLE *phClientItems = allocate_buffer<OPCHANDLE>( dwCount );
	VARIANT	  *pvValues = allocate_buffer<VARIANT>( dwCount );
	WORD	  *pwQualities = allocate_buffer<WORD>( dwCount );
	FILETIME  *pftTimeStamps = allocate_buffer<FILETIME>( dwCount );
	HRESULT   *pErrors	= allocate_buffer<HRESULT> ( dwCount );

	HRESULT hrMasterquality = S_OK;
	HRESULT hrMastererror = S_OK;

	// заполняем буффер 
	for( i=0,it = m_FilteredData.begin(); it != m_FilteredData.end(); ++it, ++i) {
		CAG_Value &value = (*it).second;
		ItemsInGroup *item = (*m_ItemsAdded.find( value.m_NameId )).second;
		
		phClientItems[i] = item->hClient; 
		VariantInit( &pvValues[i] );
		VariantCopy( &pvValues[i], &value.m_Value );
		pwQualities[i] = value.m_Quality;
		if( item->type )
			VariantChangeType( &pvValues[i],&pvValues[i], NULL, item->type );
		pftTimeStamps[i] = value.m_Time;
		pErrors[i] = S_OK;
		
		hrMastererror &= pErrors[i];
	}
 
//	for(i=0, it = changed_items.begin(); it != changed_items.end(); ++i, ++it ) {
//		CLockRead locker( g_LastValues );
//		ItemsInGroupMap::iterator it_item = m_ItemsAdded.find( *it );
//		ItemsInGroup *item = (*it_item).second;
//
////		InterlockedExchange( & item->modified, FALSE ); // сбрасываем флажок 
//
//		phClientItems[i] = item->hClient; // (*it).second;
//
//		CAG_Value *pAdapt = g_LastValues.get_pointer( *it );
//		if( pAdapt == NULL) {
//			pwQualities[i] = OPC_QUALITY_OUT_OF_SERVICE;
//			pErrors[i] = E_FAIL;
//		}
//		else {
//			CAG_Value &adapt = g_LastValues[ *it ];
//			VariantCopy( &pvValues[i], &adapt.m_Value );
//			pwQualities[i] = OPC_QUALITY_GOOD;
//			if( item->type )
//				VariantChangeType( &pvValues[i],&pvValues[i], NULL, item->type );
//			pftTimeStamps[i] = adapt.m_Time;
//		}
//		//hrMasterquality &= 
//		hrMastererror &= pErrors[i];
//	}

		try {
			Fire_OnDataChange( 0, m_ClientHandle, hrMasterquality, hrMastererror, dwCount, 
					phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors );
		} catch(...) {

		}
	/// очищае?буффер
	m_FilteredData.erase( m_FilteredData.begin(), m_FilteredData.end() );

	CoTaskMemFree( phClientItems );
	for(i=0;i<dwCount;i++)
		VariantClear( &pvValues[i] );
	CoTaskMemFree( pvValues );
	CoTaskMemFree( pwQualities );
	CoTaskMemFree( pftTimeStamps );
	CoTaskMemFree( pErrors );
}
