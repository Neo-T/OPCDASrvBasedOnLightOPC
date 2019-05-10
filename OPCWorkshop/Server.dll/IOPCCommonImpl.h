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

template <class T>
class IOPCCommonImpl :
	public IOPCCommon
{
public:
	CString m_ClientName;
	LCID m_dwLcid;

	STDMETHOD(SetLocaleID) (/*[in]*/ LCID dwLcid )
	{
		if( dwLcid != LOCALE_SYSTEM_DEFAULT && 
			dwLcid != MAKELCID( LANG_RUSSIAN , SUBLANG_DEFAULT  ) )
			return E_INVALIDARG;
		m_dwLcid = dwLcid;
		return S_OK;
	}
	STDMETHOD(GetLocaleID) ( /*[out]*/ LCID *pdwLcid ) 
	{
		if( pdwLcid == NULL)  return E_INVALIDARG;
		*pdwLcid = m_dwLcid;
		return S_OK;
	}

	STDMETHOD(QueryAvailableLocaleIDs) ( /*[out]*/ DWORD *pdwCount, /*[out, sizeis(, *pdwCount)]*/ LCID **ppdwLcid )
	{
		if( pdwCount == NULL || ppdwLcid == NULL) return E_INVALIDARG;
			
		*ppdwLcid = new LCID[2];
		*ppdwLcid[0] = LOCALE_SYSTEM_DEFAULT;
		*ppdwLcid[1] = MAKELCID( LANG_RUSSIAN , SUBLANG_DEFAULT  );
		*pdwCount = 2;
		return S_OK;
	}
	STDMETHOD(GetErrorString) ( /*[in]*/ HRESULT dwError, /*[out, string]*/ LPWSTR *ppString )
	{
		return E_NOTIMPL;
	}
	STDMETHOD(SetClientName) ( /*[in, string]*/ LPCWSTR szName )
	{
		m_ClientName = CW2T( szName );
		return S_OK;
	}
};

}