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

template <class T>
class IOPCItemPropertiesImpl :
	public IOPCItemProperties
{
public:
	STDMETHOD(QueryAvailableProperties) (
		/*[in]*/ LPWSTR szItemID,
		/*[out]*/ DWORD * pdwCount,
		/*[out, size_is(,*pdwCount)]*/ DWORD **ppPropertyIDs,
		/*[out, size_is(,*pdwCount)]*/ LPWSTR **ppDescriptions,
		/*[out, size_is(,*pdwCount)]*/ VARTYPE **ppvtDataTypes
		)
	{
		printf( "QueryAvailableProperties [%s]\n", CW2T(szItemID) );
		return E_NOTIMPL;
	}
	STDMETHOD(GetItemProperties) (
		/*[in]*/ LPWSTR szItemID,
		/*[in]*/ DWORD dwCount,
		/*[in, size_is(dwCount)]*/ DWORD * pdwPropertyIDs,
		/*[out, size_is(,dwCount)]*/ VARIANT ** ppvData,
		/*[out, size_is(,dwCount)]*/ HRESULT **ppErrors
		)
	{
		printf( "GetItemProperties [%s]\n", CW2T(szItemID) );
		return E_NOTIMPL;
	}

	STDMETHOD(LookupItemIDs) (
		/*[in]*/ LPWSTR szItemID,
		/*[in]*/ DWORD dwCount,
		/*[in, size_is(dwCount)]*/ DWORD *pdwPropertyIDs,
		/*[out, string, size_is(,dwCount)]*/ LPWSTR ** ppszNewItemIDs,
		/*[out, size_is(,dwCount)]*/ HRESULT **ppErrors
		)
	{
		printf( "LookupItemIDs [%s]\n", CW2T(szItemID) );
		return E_NOTIMPL;
	}

};