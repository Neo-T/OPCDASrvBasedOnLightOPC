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
class IOPCSyncIOImpl :
	public IOPCSyncIO
{
public:
	STDMETHOD(Read) ( /*[in]*/ OPCDATASOURCE dwSource, 
				/*[in]*/ DWORD dwCount, 
				/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
				/*[out, size_is(,dwCount)]*/ OPCITEMSTATE ** ppItemValues, 
				/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors )
	{ 
		HRESULT ret = S_OK;
		CAG_Value value;
		T* pT = static_cast<T*> (this);
		dwSource; // ignoring 
		if( dwCount == 0 ) return S_OK;

		VALIDATE_ARGUMENT( phServer );
		VALIDATE_ARGUMENT( ppItemValues );
		VALIDATE_ARGUMENT( ppErrors );

		*ppItemValues = allocate_buffer<OPCITEMSTATE> ( dwCount );
		*ppErrors = allocate_buffer<HRESULT> ( dwCount );

		CLockRead locker2( pT->m_ItemsAdded );

		for(DWORD i=0;i< dwCount;i++) {
			/// если мы не подписаны на такой параметр
			if( ! pT->isAcceptedParam( phServer[i] ) ) {
				(*ppItemValues)[i].wQuality = OPC_QUALITY_OUT_OF_SERVICE;
				ret = S_FALSE;
				(*ppErrors)[i] = E_FAIL;
				continue;
			}

			ItemsInGroup *item = (*pT->m_ItemsAdded.find( phServer[i] )).second;

			/// вычитываем последнее значение параметра

			if( item && pT->getLastValue( phServer[i], value ) ) {
				(*ppItemValues)[i].hClient = item->hClient;
				(*ppItemValues)[i].wQuality = OPC_QUALITY_GOOD;
				(*ppItemValues)[i].ftTimeStamp = value.m_Time;
				VariantInit( &(*ppItemValues)[i].vDataValue );
				VariantCopy( &(*ppItemValues)[i].vDataValue, &value.m_Value );
				(*ppErrors)[i] = S_OK;
			}
			else {
				(*ppItemValues)[i].wQuality = OPC_QUALITY_OUT_OF_SERVICE;
				ret = S_FALSE;
				(*ppErrors)[i] = E_FAIL;
			}
			//// проверяем, принадлежит ли данный параметр нашей группе 
			//ItemsInGroupMap::iterator it = pT->m_ItemsAdded.find( phServer[i] );
			//if( it == pT->m_ItemsAdded.end()) {
			//	(*ppItemValues)[i].wQuality = OPC_QUALITY_OUT_OF_SERVICE;
			//	ret = S_FALSE;
			//	(*ppErrors)[i] = E_FAIL;
			//	continue;
			//}


			// проверяем есть ли такой параметр 
			//CAG_Value *pAdapt = opcData::g_LastValues.get_pointer( phServer[i] );
			//if( it == pT->m_ItemsAdded.end() || pAdapt == NULL) {
			//	ppItemValues[i]->wQuality = OPC_QUALITY_OUT_OF_SERVICE;
			//	ret = S_FALSE;
			//	(*ppErrors)[i] = E_FAIL;
			//}
			//CAG_Value &adapt = opcData::g_LastValues[ phServer[i] ];

			//(*ppErrors)[i] = S_OK;
		}

		return ret; 
	}

	STDMETHOD(Write) ( /*[in]*/ DWORD dwCount, 
				/*[in, size_is(dwCount)]*/ OPCHANDLE * phServer, 
				/*[in, size_is(dwCount)]*/ VARIANT * pItemValues, 
				/*[out, size_is(,dwCount)]*/ HRESULT ** ppErrors )
	{ 
		DWORD i;
		HRESULT hr = S_OK;
		T* pT = static_cast<T*> (this);

		VALIDATE_ARGUMENT( phServer );
		VALIDATE_ARGUMENT( pItemValues );
		VALIDATE_ARGUMENT( ppErrors );

		*ppErrors = allocate_buffer<HRESULT> ( dwCount );

		for(i=0;i<dwCount; ++i) {
			if( !pT->isAcceptedParam( phServer[i] ) ) {
				(*ppErrors)[i] = E_FAIL;
				hr = S_FALSE;
			}
			else {
				CAG_Value adapt;
				adapt.m_NameId = phServer[i];
				adapt.m_Name = g_NameIndex[ adapt.m_NameId ];
				CoFileTimeNow( &adapt.m_Time );
				adapt.m_Value = pItemValues[i];
				adapt.m_Type = adapt.m_Value.vt;

				if( pT->m_Manager )
					pT->m_Manager->pushNewData( adapt );
			}
		}

		return hr; 
	}

};

}
using namespace Ag_OPC;
