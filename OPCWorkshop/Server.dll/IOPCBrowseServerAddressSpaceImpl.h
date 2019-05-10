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

#include "crEnum.h"

#include <set>

extern char g_BrowseNameDelimeter[20];

template <class T>
class IOPCBrowseServerAddressSpaceImpl :
	public IOPCBrowseServerAddressSpace
{
	BOOL isExistBrowsePath( CString position )
	{
		if( position.GetLength() )
			position += g_BrowseNameDelimeter; //_T(".");
		else 
			return TRUE;

		CBrowseItemsList::iterator it;
		for(it = g_BrowseItems.begin(); it != g_BrowseItems.end(); ++it) {
			CItemForBrowse item( *it );
			if( position.GetLength() && item.name.Left( position.GetLength() ) == position ) 
				return TRUE;
		}
		return FALSE;
	}

public:
	CString m_BrowsePosition;

	STDMETHOD(QueryOrganization) ( /*[out]*/ OPCNAMESPACETYPE * pNameSpaceType )
	{
		if(pNameSpaceType == NULL) return E_INVALIDARG;
		*pNameSpaceType = OPC_NS_HIERARCHIAL;
		ATLTRACE(_T("QueryOrganization\n"));
		return S_OK; 
	}
	STDMETHOD(ChangeBrowsePosition) ( /*[in]*/ OPCBROWSEDIRECTION dwBrowseDirection,
									/*[in, string]*/ LPCWSTR szString )
	{
		CString branch = CW2T(szString);
		CString new_position;
		//return E_NOTIMPL; 
		ATLTRACE(_T("ChangeBrowsePosition (%s) "),CW2T(szString));
		switch( dwBrowseDirection ) {
			case OPC_BROWSE_DOWN:
				ATLTRACE(_T("OPC_BROWSE_DOWN\n"));
				if( branch.IsEmpty() ) return E_INVALIDARG;
				if(m_BrowsePosition.GetLength()) 
					new_position = m_BrowsePosition + g_BrowseNameDelimeter; //_T(".");
				new_position += CW2T( szString );
				if( isExistBrowsePath( new_position ) )
					m_BrowsePosition = new_position;
				else
					return E_INVALIDARG;
				break;
			case OPC_BROWSE_TO:
				ATLTRACE(_T("OPC_BROWSE_TO\n"));
				if( isExistBrowsePath( branch ) )
					m_BrowsePosition = branch;
				else
					return E_INVALIDARG;
//				m_BrowsePosition = CW2T( szString );
				break;
			case OPC_BROWSE_UP:
				ATLTRACE(_T("OPC_BROWSE_UP\n"));
				if( m_BrowsePosition.IsEmpty() ) return E_FAIL;
				while( m_BrowsePosition.GetLength() ) {
					if( m_BrowsePosition[m_BrowsePosition.GetLength()-1] == g_BrowseNameDelimeter[0]/*'.'*/) {
						m_BrowsePosition = m_BrowsePosition.Left( m_BrowsePosition.GetLength()-1 );
						break;
					}
					else
						m_BrowsePosition = m_BrowsePosition.Left( m_BrowsePosition.GetLength()-1 );
				}
				break;
			default:
				return E_INVALIDARG;
		}
		return S_OK;
	}
	STDMETHOD(BrowseOPCItemIDs) ( /*[in]*/ OPCBROWSETYPE dwBrowseFilterType, 
						/*[in, string]*/ LPCWSTR szFilterCriteria,
						/*[in]*/ VARTYPE vtDataTypeFilter,
						/*[in]*/ DWORD dwAccessRightsFilter,
						/*[out]*/ LPENUMSTRING * ppIEnumString  )
	{
//		CString filter = CW2T(szFilterCriteria);
		//TODO szFilterCriteria
		ATLTRACE(_T("BrowseOPCItemIDs\n"));

		std::vector<LPOLESTR> strings;
		T* pT = static_cast<T*> (this);

		//if( dwAccessRightsFilter != OPC_READABLE && 
		//	dwAccessRightsFilter != OPC_WRITEABLE &&
		//	dwAccessRightsFilter != (OPC_READABLE & OPC_WRITEABLE) ) 
		//		return E_INVALIDARG;
		
		if(dwBrowseFilterType == OPC_LEAF) {
			CBrowseItemsList::iterator it;
			for(it = g_BrowseItems.begin(); it != g_BrowseItems.end(); ++it) {
				CItemForBrowse item( *it );
				bool adding = false;
				CString name = item.name;
				
				//TODO сделать отбор  параметров по типу 

				if( item.dwAccessRights && (dwAccessRightsFilter & OPC_WRITEABLE) )
					adding = true;

				if( m_BrowsePosition.GetLength() && name.Left( m_BrowsePosition.GetLength() ) == m_BrowsePosition ) {
					name = name.Mid( m_BrowsePosition.GetLength()+1);
					adding = true;
				} else
					adding = false;
				if( m_BrowsePosition.GetLength() == 0 && name.Find(g_BrowseNameDelimeter) < 0 && name.GetLength() > 0 )
					adding = true;
				if( adding && name.GetLength() && name.Find(g_BrowseNameDelimeter/*_T(".")*/) < 0 ) {
					LPOLESTR str = name.AllocSysString();
					strings.push_back( str );
				}
			}
		}

		if(dwBrowseFilterType == OPC_BRANCH ) {
			std::set<CString> unique_str;
			{
			for(CBrowseItemsList::iterator it = g_BrowseItems.begin(); it != g_BrowseItems.end(); ++it) {
				CItemForBrowse item( *it );
				
				// если одинаковое начало
				if( m_BrowsePosition.GetLength() ) {
					if( item.name.Left( m_BrowsePosition.GetLength() ) == m_BrowsePosition ) 
					{
						CString ostatok = item.name.Mid( m_BrowsePosition.GetLength() );
						if( ostatok.Left(strlen(g_BrowseNameDelimeter)) != g_BrowseNameDelimeter )
							continue;
						ostatok.TrimLeft(g_BrowseNameDelimeter/*_T(".")*/);
						int i = ostatok.Find(g_BrowseNameDelimeter/*_T(".")*/);
						if( i > 0 ) unique_str.insert( ostatok.Left( i ) );
					}
				} 
				else {
					int i = item.name.Find( g_BrowseNameDelimeter );
					if( i > 0 ) 
						unique_str.insert( item.name.Left( i ) );
				}

			}}	

			std::set<CString>::iterator it;
			for( it = unique_str.begin(); it != unique_str.end(); ++it) {
				strings.push_back( (*it).AllocSysString() );
			}
		}

		//if(strings.size()) 
		{
			strings.push_back( NULL );
			return  CreateEnumerator<StringEnum,LPOLESTR,LPENUMSTRING *>(ppIEnumString, 
				&strings[0], &strings[strings.size()-1], this, AtlFlagCopy);
		}
		return S_FALSE; 
	}

	STDMETHOD(GetItemID) ( /*[in]*/ LPWSTR szItemDataID, /*[out, string]*/ LPWSTR * szItemID )
	{
		VALIDATE_ARGUMENT( szItemDataID );
		VALIDATE_ARGUMENT( szItemID );

		CString str = CW2T( szItemDataID );
		if( m_BrowsePosition.GetLength() )
			str = m_BrowsePosition + g_BrowseNameDelimeter /*_T(".")*/ + str;
		if( szItemID && *szItemID == NULL ) {
			(*szItemID) = (LPWSTR) CoTaskMemAlloc( (str.GetLength() + 1) * sizeof(WCHAR) ); 
			CopyMemory(*szItemID, CT2W(str), (str.GetLength() + 1) * sizeof(WCHAR) );
		}
		//ATLTRACE(_T("GetItemID\n"));
		return S_OK; 
	}

	STDMETHOD(BrowseAccessPaths) ( /*[in, string]*/ LPCWSTR szItemID, /*[out]*/ LPENUMSTRING * ppIEnumString )
	{
		ATLTRACE(_T("BrowseAccessPaths\n"));
		return S_FALSE; 
	}
};
