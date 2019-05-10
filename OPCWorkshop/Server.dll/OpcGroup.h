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

#define MINIMUM_UPDATE_RATE 100


#include "ErrorInfoImpl.h"

#include "ag_timer.h"
//#include "sf_timer.h"
//extern CTimerHost g_TimerHost;

//#include "xl_events.h"
//#include "_IGF_Events_CP.H"

/// Описывае?параметр нахо?щийся ?группе OPC сервер?
class ItemsInGroup
{
public:
	OPCHANDLE hClient;
	VARTYPE type;
//	volatile LONG modified;
	BOOL bActive;

	ItemsInGroup(OPCHANDLE h = 0,BOOL act = FALSE) : 
		  hClient(h), 
//		  modified(FALSE), 
		  bActive(act), 
		  type(VT_EMPTY) 
	{ 
	}
};
class ItemsInGroupMap : 
	public std::map<OPCHANDLE,ItemsInGroup*>,
	public CRWMonitor
{ };
typedef std::pair<OPCHANDLE,ItemsInGroup*> ItemsInGroupMapPair;

//#include "NameIndex.H"
#include "BrowseItem.H"

#define OPC_GROUP_CHECK_DELETED()	T* pT = static_cast<T*>(this); \
									if(pT->m_Deleted) return E_FAIL;

class COPCServer;

#include "IOPCItemMgtImpl.h"
#include "IOPCGroupStateMgtImpl.h"
#include "IOPCSyncIOImpl.h"
#include "IOPCAsyncIO2Impl.h"
#include "IOPCDataCallback_CP.h"

class ATL_NO_VTABLE COPCGroup : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COPCGroup>,
	public IConnectionPointContainerImpl<COPCGroup>,
	public AG_IErrorInfoImpl<COPCGroup>,
//	public CProxy_IGF_Events<COPCGroup>,

	public CProxy_IOPCDataCallback<COPCGroup>,
	public IOPCItemMgtImpl<COPCGroup>,
	public IOPCGroupStateMgtImpl<COPCGroup>,
	public IOPCSyncIOImpl<COPCGroup>,
	public IOPCAsyncIO2Impl<COPCGroup>,
	public opcData::COPCDataCustomer
{
	// флажок, указател?на которы?добавляем всем параметрам буффер?
	// BOOL m_FlagChangedValues;
public:
	DWORD m_UpdateRate;
	CString m_GroupName;
	OPCHANDLE m_ClientHandle;
	OPCHANDLE m_ServerHandle;
	DWORD m_TimeBias;
	FLOAT m_PercentDeadband;
	LCID m_dwLCID;

	CWin32Timer< COPCGroup >   m_Timer;
    //CTimerThunk< COPCGroup >   m_Timer;

	bool m_Deleted;

	// <server,client>
	ItemsInGroupMap m_ItemsAdded;

	// список параметров для которы?необходимо прочитат?асинхронно
	CComAutoCriticalSection m_AsyncReadSect;
	std::set<OPCHANDLE> m_AsyncRead;


	// перенесено ка?наследование 
	//opcData::COPCDataCustomer m_DataCustomer;

	COPCGroup() :
		m_Timer( this )
		//m_Timer( g_TimerHost, this, OnTimer )
	{
		m_ClientHandle = NULL;
		m_UpdateRate = 1000;
		m_ServerHandle = NULL;
		m_TimeBias = 0;

		m_Deleted = false;
		// m_FlagChangedValues = FALSE;

		// OPC группа не може?принимат?вс?параметр?бе?подписки
		/*m_DataCustomer.*/SetAcceptAll( false ); 
	}

	virtual ~COPCGroup()
	{

	}

	BEGIN_COM_MAP(COPCGroup)
		COM_INTERFACE_ENTRY(IOPCItemMgt)
		COM_INTERFACE_ENTRY(IOPCGroupStateMgt)
		COM_INTERFACE_ENTRY(IErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(IOPCSyncIO)
		COM_INTERFACE_ENTRY(IOPCAsyncIO2)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(COPCGroup)
		CONNECTION_POINT_ENTRY(__uuidof(IOPCDataCallback))
	END_CONNECTION_POINT_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:
	/// сообщени?от таймер?пр?достижении времен? когд?нужн?отдавать данные
    void OnTimer(/*DWORD dwTime*/)
	{
		sendChangedDataToClient();
		//m_Timer.KillTimer();
		//	RemoveOldDumps( m_WriteParametrs.m_ArchiveLength );
		//setTimer( -1 );
	}

	void sendChangedDataToClient();
};

template <typename T>
T* allocate_buffer( size_t count )
{
	T* p = (T*)CoTaskMemAlloc( sizeof(T) * count );
	ZeroMemory( p, sizeof(T) * count );
	return p;
}

