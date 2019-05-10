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

#include "OpcGroupItem.h"
#include "OPCGroup.h"
#include "ag_thread.h"

#include "crEnum.h"

namespace Ag_OPC {

template <class T>
class IOPCServerImpl :
	public IOPCServer
{
public:
	CComAutoCriticalSection m_Sect;
	CEvent m_EmptyGroupsEvent;

	OPCSERVERSTATUS m_ServerStatus;
	COpcGroupItemMap m_GroupsIndex;
	DWORD m_UniqueIndex;

	typedef std::map<CString,OPCHANDLE> CGroupNameIndex;
	CGroupNameIndex m_GroupNameIndex;

	IOPCServerImpl() :
		m_EmptyGroupsEvent( TRUE, FALSE )
	{
		ZeroMemory(&m_ServerStatus, sizeof(OPCSERVERSTATUS));
		CoFileTimeNow( & m_ServerStatus.ftStartTime );
		m_ServerStatus.szVendorInfo = L"Alexey Obukhov";
		m_ServerStatus.dwServerState = OPC_STATUS_NOCONFIG;
		m_ServerStatus.dwBandWidth = 0xFFFFFFFF;
		m_ServerStatus.wMajorVersion = 2;

		m_UniqueIndex = 1;
	}


	STDMETHOD(AddGroup) (
		/*[in, string]*/ LPCWSTR szName,
		/*[in]*/ BOOL bActive,
		/*[in]*/ DWORD dwRequestedUpdateRate,
		/*[in]*/ OPCHANDLE hClientGroup,
		/*[unique, in]*/ LONG *pTimeBias,
		/*[in]*/ FLOAT * pPercentDeadband,
		/*[in]*/ DWORD dwLCID,

		/*[out]*/ OPCHANDLE * phServerGroup,
		/*[out]*/ DWORD *pRevisedUpdateRate,
		/*[in]*/ REFIID riid,
		/*[out, iid_is(riid)]*/ LPUNKNOWN * ppUnk )
	{
		T* pT = static_cast<T*> (this);
		thread::CCritSectLocker locker( m_Sect );

		COpcGroupItemMap::iterator it;
		if(m_GroupNameIndex.find( CString( CW2T( szName ))) != m_GroupNameIndex.end() )
			return OPC_E_DUPLICATENAME;

		if( pPercentDeadband )
			if( *pPercentDeadband < 0. || *pPercentDeadband > 100. ) return E_INVALIDARG;

		CString gname = CW2T(szName);
		if( gname == _T("") ) return E_INVALIDARG;

		COpcGroupItem *grpItem = new COpcGroupItem();
		HRESULT hr = grpItem->m_Group->SetState( &dwRequestedUpdateRate, pRevisedUpdateRate, &bActive, 
								pTimeBias, pPercentDeadband, &dwLCID, &hClientGroup);
		if( FAILED( hr ))  {
			delete grpItem;
			return hr;
		}
				
		hr = grpItem->m_Group->QueryInterface( riid, (void**)ppUnk );
		if( FAILED(hr) || *ppUnk == NULL) {
			delete grpItem;
			return E_NOINTERFACE;
		}
		
		grpItem->m_Group->m_ServerHandle = m_UniqueIndex++;
		grpItem->m_Group->m_GroupName = szName;
		m_GroupNameIndex[ grpItem->m_Group->m_GroupName ] = grpItem->m_Group->m_ServerHandle;
		m_GroupsIndex[  grpItem->m_Group->m_ServerHandle ] = grpItem;
		
		if(phServerGroup)
			*phServerGroup = grpItem->m_Group->m_ServerHandle;

		grpItem->m_Group->Subscribe( &pT->m_DM  );
//TODO - подписаться на события группы 
//		pT->AdviseAl( grpItem->m_Group->GetUnknown() );

		/// сбрасываем сигнал об пустом списке групп 
		m_EmptyGroupsEvent.Reset();

		if(dwRequestedUpdateRate != *pRevisedUpdateRate)
			return OPC_S_UNSUPPORTEDRATE;

		return S_OK;
	}

	STDMETHOD(GetErrorString) (
		/*[in]*/ HRESULT dwError,
		/*[in]*/ LCID dwLocale,
		/*[out, string]*/ LPWSTR *ppString )
	{
		T* pT = static_cast<T*> (this);
		thread::CCritSectLocker locker( m_Sect );

		return E_NOTIMPL;
	}

	STDMETHOD(GetGroupByName) (
		/*[in, string]*/ LPCWSTR szName,
		/*[in]*/ REFIID riid,
		/*[out, iid_is(riid)]*/ LPUNKNOWN * ppUnk )
	{
		T* pT = static_cast<T*> (this);
		thread::CCritSectLocker locker( m_Sect );

		if( CString(CW2T(szName)) == _T("") )  return E_INVALIDARG;
		if( riid != IID_IOPCItemMgt ) return E_NOINTERFACE;
		if( ppUnk == NULL ) return E_INVALIDARG;
		if( *ppUnk == NULL ) return E_INVALIDARG;

		CGroupNameIndex::iterator it = m_GroupNameIndex.find( CString( szName ));
		if(it == m_GroupNameIndex.end() ) return E_FAIL;

		OPCHANDLE hand = (*it).second;
		if(m_GroupsIndex.find( hand) == m_GroupsIndex.end()) 
			return E_FAIL;

		COpcGroupItem *grpItem = m_GroupsIndex[ hand ];
		if(grpItem == NULL) return E_FAIL;

		HRESULT hr = grpItem->m_Group->QueryInterface( riid, (void**)ppUnk );
		if( FAILED(hr) || *ppUnk == NULL)
			return E_NOINTERFACE;

		return S_OK;
	}

	STDMETHOD(GetStatus) ( /*[out]*/ OPCSERVERSTATUS ** ppServerStatus )
	{
		T* pT = static_cast<T*> (this);
		thread::CCritSectLocker locker( m_Sect );

		if(ppServerStatus == NULL) return E_INVALIDARG;
//		T* pT = static_cast<T*> (this);

		OPCSERVERSTATUS *stat = (OPCSERVERSTATUS *)CoTaskMemAlloc( sizeof(OPCSERVERSTATUS) );
		CopyMemory( stat, &m_ServerStatus, sizeof(OPCSERVERSTATUS) );
		CoFileTimeNow(&( stat->ftCurrentTime));
		
		*ppServerStatus = stat;
		stat->szVendorInfo = (LPWSTR)CoTaskMemAlloc( wcslen( m_ServerStatus.szVendorInfo)*2 + 2 );
		CopyMemory( stat->szVendorInfo, m_ServerStatus.szVendorInfo, wcslen( m_ServerStatus.szVendorInfo)*2 + 2);
		stat->dwGroupCount = (DWORD) m_GroupNameIndex.size();

		return S_OK;
	}

	STDMETHOD(RemoveGroup) ( /*[in]*/ OPCHANDLE hServerGroup, /*[in]*/ BOOL bForce )
	{
		HRESULT hr = S_OK;
		T* pT = static_cast<T*> (this);
		thread::CCritSectLocker locker( m_Sect );

		if(m_GroupsIndex.find( hServerGroup ) == m_GroupsIndex.end()) 
			return E_FAIL;

		COpcGroupItem *grpItem = m_GroupsIndex[ hServerGroup ];
		if( grpItem->m_Group->m_dwRef > 1 && bForce ) 
			hr = OPC_S_INUSE;

		m_GroupsIndex.erase( hServerGroup );
		m_GroupNameIndex.erase( grpItem->m_Group->m_GroupName );

// отписаться от событий группы 
//		pT->UnadviseAl( grpItem->m_Group->GetUnknown() );

		grpItem->m_Group->Unsubscribe(/* &pT->m_DM  */);

		grpItem->m_Group->m_Timer.KillTimer();
		grpItem->m_Group->m_Deleted = true;
		delete grpItem;

		// сигнализируем что кончились все группы 
		if( m_GroupsIndex.size() == 0 )
			m_EmptyGroupsEvent.Set();

		return hr;
	}

	/// TODO - не протестировано !
	STDMETHOD(CreateGroupEnumerator) ( 
		/*[in]*/ OPCENUMSCOPE dwScope, 
		/*[in]*/ REFIID riid, 
		/*[out, iid_is(riid)]*/ LPUNKNOWN* ppUnk )
	{
		T* pT = static_cast<T*> (this);
		thread::CCritSectLocker locker( m_Sect );

		if( riid == IID_IEnumUnknown ) 
		{
			std::vector<IUnknown*> unkn( m_GroupsIndex.size() );
			COpcGroupItemMap::iterator it;
			for( it = m_GroupsIndex.begin(); it!= m_GroupsIndex.end(); ++it)

				unkn.push_back( reinterpret_cast<IOPCItemMgt*> ((*it).second->m_Group) );

			if(unkn.size()) {
				unkn.push_back( NULL );
				return  CreateEnumerator<UnknownEnum,LPUNKNOWN,LPUNKNOWN*>(ppUnk, 
					&unkn[0], &unkn[unkn.size()-1], this, AtlFlagCopy);
			}

		} else if( riid == IID_IEnumString ) {

		}
		else {
			return E_INVALIDARG;
		}

		return S_OK;
	}

};

}