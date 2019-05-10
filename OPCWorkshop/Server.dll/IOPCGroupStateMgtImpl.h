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

#include "OPCHDA_Error.h"

namespace Ag_OPC {

template <class T>
class IOPCGroupStateMgtImpl :
	public IOPCGroupStateMgt
{
public:
	STDMETHOD (GetState)( /*[out]*/ DWORD * pUpdateRate, 
						/*[out]*/ BOOL * pActive, 
						/*[out, string]*/ LPWSTR * ppName, 
						/*[out]*/ LONG * pTimeBias, 
						/*[out]*/ FLOAT * pPercentDeadband, 
						/*[out]*/ DWORD * pLCID, 
						/*[out]*/ OPCHANDLE * phClientGroup, 
						/*[out]*/ OPCHANDLE * phServerGroup ) 
	{ 
		T* pT = static_cast<T*>(this);
		if(pT->m_Deleted) return E_FAIL;

		if(pUpdateRate) *pUpdateRate = pT->m_UpdateRate;
		if(pActive) *pActive = pT->m_Timer.IsRunning();

		//CComBSTR gname(pT->m_GroupName);
		if(ppName) {
			long len = 0;
			*ppName = (LPWSTR)CoTaskMemAlloc( len = (strlen(pT->m_GroupName)+1)*sizeof(OLECHAR) ); //gname.Detach();
			memcpy( *ppName, CT2W( pT->m_GroupName ), len );
		}

		if(pTimeBias) *pTimeBias = pT->m_TimeBias;
		if(pPercentDeadband) *pPercentDeadband = pT->m_PercentDeadband;
		if(phClientGroup) *phClientGroup = pT->m_ClientHandle;
		if(phServerGroup) *phServerGroup = pT->m_ServerHandle;
		return S_OK;
	}

	STDMETHOD (SetState)( /*[unique, in]*/ DWORD * pRequestedUpdateRate, 
					/*[out]*/ DWORD * pRevisedUpdateRate, 
					/*[unique, in]*/ BOOL *pActive, 
					/*[unique, in]*/ LONG * pTimeBias, 
					/*[unique, in]*/ FLOAT * pPercentDeadband, 
					/*[unique, in]*/ DWORD * pLCID, 
					/*[unique, in]*/ OPCHANDLE *phClientGroup ) 
	{ 
		T* pT = static_cast<T*>(this);
		if(pT->m_Deleted) return E_FAIL;

		bool rate_changed = false;
		DWORD new_rate = * pRequestedUpdateRate;
		if(new_rate < MINIMUM_UPDATE_RATE) new_rate = MINIMUM_UPDATE_RATE;
		*pRevisedUpdateRate = new_rate;

		if( new_rate != pT->m_UpdateRate) {
			rate_changed = true;
			pT->m_UpdateRate = new_rate;
		}

		// если прос€т остановитьс€
		if( ! *pActive ) pT->m_Timer.KillTimer();
		else {
			if(pT->m_Timer.IsRunning()) {
				if(rate_changed) {
					pT->m_Timer.KillTimer();
					pT->m_Timer.SetTimer( pT->m_UpdateRate );
				}
			}
			else
				pT->m_Timer.SetTimer( pT->m_UpdateRate );
		}		
		if(phClientGroup)
			pT->m_ClientHandle = *phClientGroup; 
		/// игнорируем 
		if(pTimeBias)
			pT->m_TimeBias = *pTimeBias;
		if(pPercentDeadband)
			pT->m_PercentDeadband = *pPercentDeadband;
		if(pLCID)
			pT->m_dwLCID = *pLCID;

		if( * pRequestedUpdateRate != *pRevisedUpdateRate)
			return OPC_S_UNSUPPORTEDRATE;
		return S_OK; 
	}

	STDMETHOD (SetName)( /*[in, string]*/ LPCWSTR szName ) 
	{ 
		T* pT = static_cast<T*>(this);
		if(pT->m_Deleted) return E_FAIL;

		// ѕосылка сообщени€ серверу об изменении имени группы 
		//pT->Fire_Event( 1, &CComVariant( CComBSTR(pT->m_GroupName)),
		//				   &CComVariant( CComBSTR(szName )),
		//				   &CComVariant( CComBSTR(L"IOPCGroup")) );

		//if(pT->m_Server)
		//	pT->m_Server->OnChangedName( , CW2T(  ) );
		pT->m_GroupName = CW2T( szName );
		return S_OK; 
	}

	STDMETHOD (CloneGroup)(/*[in, string]*/ LPCWSTR szName, 
					/*[in]*/ REFIID riid, 
					/*[out, iid_is(riid)]*/ LPUNKNOWN * ppUnk ) 
	{ 
		T* pT = static_cast<T*>(this);
		if(pT->m_Deleted) return E_FAIL;
		return E_NOTIMPL; 
	}
};
}
using namespace Ag_OPC;
