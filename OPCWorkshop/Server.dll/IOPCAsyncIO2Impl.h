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
class IOPCAsyncIO2Impl :
	public IOPCAsyncIO2
{
public:
	/*!
		Read one or more items in a group. The results are 
		returned via the client’s IOPCDataCallback connection 
		established through the server’s IConnectionPointContainer.
	*/
	STDMETHOD(Read)( /*[in]*/ DWORD dwCount, 
				/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
				/*[in]*/ DWORD dwTransactionID, 
				/*[out]*/ DWORD *pdwCancelID, 
				/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors )
	{ 
		OPC_GROUP_CHECK_DELETED();

		VALIDATE_ARGUMENT( phServer );
		VALIDATE_ARGUMENT( ppErrors );

		*ppErrors = allocate_buffer<HRESULT> ( dwCount );

		for( DWORD i=0;i<dwCount; ++i ) {
			thread::CCritSectLocker locker( pT->m_AsyncReadSect );
			pT->m_AsyncRead.insert( phServer[i] );
		}

		return S_OK; 
	}

	/*!
		Write one or more items in a group. The results are returned via 
		the client’s IOPCDataCallback connection established 
		through the server’s IConnectionPointContainer.
	*/
	STDMETHOD(Write)( /*[in]*/ DWORD dwCount, 
				/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
				/*[in, size_is(dwCount)]*/ VARIANT * pItemValues, 
				/*[in]*/ DWORD dwTransactionID, 
				/*[out]*/ DWORD *pdwCancelID, 
				/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors )
	{ 
		OPC_GROUP_CHECK_DELETED();

		if( pdwCancelID ) *pdwCancelID = 0;

		return pT->Ag_OPC::IOPCSyncIOImpl<COPCGroup>::Write( dwCount, phServer, pItemValues, ppErrors );
	}

	/*!
		Force a callback to IOPCDataCallback::OnDataChange for all active items 
		in the group (whether they have changed or not). 
		Inactive items are not included in the callback.
	*/
	STDMETHOD(Refresh2) ( /*[in]*/ OPCDATASOURCE dwSource, 
						  /*[in]*/ DWORD dwTransactionID, 
						  /*[out]*/ DWORD *pdwCancelID )
	{ 
		OPC_GROUP_CHECK_DELETED();

		ItemsInGroupMap::iterator it;
		CLockRead locker( pT->m_ItemsAdded );
		
		for( it = pT->m_ItemsAdded.begin(); it != pT->m_ItemsAdded.end(); ++it ) {
			ItemsInGroup* item = (*it).second;
			if( item->bActive ) {
				thread::CCritSectLocker locker( pT->m_AsyncReadSect );
				pT->m_AsyncRead.insert( (*it).first );

			}
		}

		return S_OK; 
	}

	/// Request that the server cancel an outstanding transaction.
	STDMETHOD(Cancel2) ( /*[in]*/ DWORD dwCancelID )
	{ 
		OPC_GROUP_CHECK_DELETED();
		return E_NOTIMPL; 
	}

	/*! Controls the operation of OnDataChange. Basically setting Enable to FALSE will 
		disable any OnDataChange callbacks with a transaction ID of 0 
		(those which are not the result of a Refresh).
	*/
	STDMETHOD(SetEnable) ( /*[in]*/ BOOL bEnable )
	{ 
		OPC_GROUP_CHECK_DELETED();
		return E_NOTIMPL; 
	}

	/// Retrieves the last Callback Enable value set with SetEnable.
	STDMETHOD(GetEnable) ( /*[out]*/ BOOL *pbEnable )
	{ 
		OPC_GROUP_CHECK_DELETED();
		return E_NOTIMPL; 
	}

};
}