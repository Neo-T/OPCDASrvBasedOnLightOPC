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

#include "Value.h"
#include "RarefiedArray.h"

/*
     ��������� �����, ��� �������� ������ �������� ����� ������ � COPCDataManager::pushNewData
     ��� ��� �������� � ����� �������
	 ����� ������ ����������� � �������� ����� ������ � ������������� �� ����������� (COPCDataCustomer)

	 ���������� COPCDataCustomer ��������� ��������� ����� ��������� ����� �������� �� ���������� �������
	 ����������. ( SetAcceptAll, ResetAcceptList, AcceptParam )
*/

#define MAX_CUSTOMER_BUFFER 10000

/* 
   ���� ���������� �� ����������� ������������ ���������� �������� ��������� 
   ���� � ������ �������� ��� � ���-�� ����� ��������� � ��������, �� ������ ��������, �� ��� 
   USE_NEW_DATA_FILTER == 1 ����� ��� ������������ ������� �� �����, ����� ����� ������������ ��� 
   ��� � ������ ��������.
*/
#define USE_NEW_DATA_FILTER 1

namespace opcData {

//extern CRarefiedArray<CAG_Value> g_LastValues;

class COPCDataCustomer;
class COPCDataManager;
class COPCDataSource;

typedef std::list<COPCDataCustomer*> COPCDataCustomerList;

/// ����������� ����� ��� ���������� ����� ���������������� ����������� � ����������
class COPCDataOperator
{
public:
	COPCDataManager *m_Manager;

	COPCDataOperator();
	virtual ~COPCDataOperator();

	virtual bool Subscribe( COPCDataManager *man ) = 0;
	virtual bool Unsubscribe() = 0;
};

/// ������ ����������� ������� ������������ ����� ���������� � ������� ����������� ������
/// � �������� �������� ������ ��� ����������, �� ���� ���� ���������� �����������
/// �� ����� � ��� ����������
template <class T>
class COPCDataQueue //: private CComAutoCriticalSection
{
	/// ������� ����������
	CComAutoCriticalSection m_QueueSect;
	std::list<T*> m_Queue;
public:
	/// �������� � ������� �������� (� ������������)
	template< class _it >
	void push_copy ( _it begin, _it end )
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		for( _it it = begin; it != end; ++it)
			m_Queue.push_back( new T(*it) );
	}

	/// �������� � ������� ��������
	template< class _it >
	void push ( _it begin, _it end )
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		m_Queue.insert( m_Queue.end(), begin, end );
	}

	/// �������� � �������
	void push ( T* value )
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		m_Queue.push_back( value );
	}

	/// ��������� �� �������
	T* pop()
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		if( m_Queue.size() ) {
			T* vect = *m_Queue.begin();
			m_Queue.pop_front();
			return vect;
		}
		/// ���� �����, �� ���������� ������� �������� - ������� ����� ������� ������ ���������
		return NULL;
	}
	/// �������� ������ ������� 
	size_t size()
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		return m_Queue.size();
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////
/// ��������� �� ������ �� COPCDataManager
class COPCDataCustomer :
	public COPCDataOperator,
	private thread::CThreadingObject
{
protected:
	/// ���� ��������, ��� �������� ��������� ��� ���������
	bool m_AcceptAllData;
	CComAutoCriticalSection m_AcceptedParamsSect;
	std::set<OPCHANDLE> m_AcceptedParams;

	/// ������� ��������������� ����������
	COPCDataQueue<CAG_Value> m_Queue;

	/// ����� ��������� �������� ������� ���������
	CRarefiedArray<CAG_Value> m_LastValues;
	/// ���������� ��� � �������� ������ ��� �������� ������� 
	void PushToClient( CAG_Value* adapt );
protected:
	/// ������������� ���������.
	std::map<OPCHANDLE,CAG_Value> m_FilteredData;
	/// ����������� ������ �������� ������ m_FilteredData
	CComAutoCriticalSection m_FilteredDataSect;


public:
	COPCDataCustomer();
	virtual ~COPCDataCustomer();
	virtual bool Subscribe( COPCDataManager *man );
	virtual bool Unsubscribe();

	enum CustomerType {
		PUSH_DATA_BY_ONE,
		PUSH_DATA_BY_PACK
	};
	/// ������� ������������� ����������� ������,
	/// ������ true ���� ����� �������� ���������� ��������� �� �� ������ � ���� ������ 
	// virtual CustomerType pushDataType(); (����� � �� �����)

	/// �������� ���������� ��������� ��������
	/// ��� ������� ������ �������� ���������� ��� ����� �������
	virtual int pushData(CAG_Value* adap, bool copy = true);
	/// �������� ���������� ��������� ����� ����������
	/// ��� ������� ������ �������� ���������� ��� ����� �������
	virtual int pushData(CAG_ValueVector* adap);


public:
	/// ������������� ��������� �� ��� ��������� ����������
	void SetAcceptAll( bool allow = true );
	/// ���������� ������ ����������, ������� ����� ��������� ���������
	void ResetAcceptList( );
	/// ��������� � ������ �������, ������� ����� ����������� �����������.
	void AcceptParam( OPCHANDLE h );
	/// ������� ������� �� ������ ��������
	void DeclineParam( OPCHANDLE h );
	/// ��������� �������� �� ����������� �� ������ ��������
	bool isAcceptedParam( OPCHANDLE h );

	/// �������� ��� ������������� ��������� ��� ��������� �������� 
	bool getLastValue( OPCHANDLE h, CAG_Value& value );
protected:
	/// ��������� ��������� �� ������� �������, � ������������� �� �� ���������� ������.
	virtual void step();
};

//////////////////////////////////////////////////////////////////////////////////////////////////
/// ����� �������������� ��������� ����� opc_DataSource & opc_DataCustomer
class COPCDataManager :
	private thread::CThreadingObject
{
	CRarefiedArray<CAG_Value> m_LastValue;

	CComAutoCriticalSection m_CustomerSect;
	COPCDataCustomerList m_CustomerList;

	COPCDataQueue<CAG_ValueVector> m_Queue;
	//CComAutoCriticalSection m_QueueSect;
	//CAG_ValuesQueue m_Queue;
public:
	COPCDataManager();
	virtual ~COPCDataManager();

private:
	friend class COPCDataCustomer;
	/// ��������� ��������� �� ����� ������ �� ��������
	bool AddCustomer( COPCDataCustomer *cust);
	/// ������� ��������� �� ��������
	bool RemoveCustomer( COPCDataCustomer *cust);

public:
	/// ���������� � ������� ����� ������ ������
	/// ��� ������ ������� �������� � �������� � ��������� �� � �������, ������ �� ��� ���.
	virtual HRESULT pushNewData( CAG_ValueVector *vect );

	/// ���������� � ������� ����� ������ ������
	/// ��� ������ ������� �������� � �������� � ��������� �� � �������, ������ �� ��� ���.
	virtual HRESULT pushNewData( CAG_Value &val );

	/// ��������� ������������� ������ �� �����������.
	virtual void step();

	/// �������� �� ����������� ������ ��������� �������� 
	CAG_Value getLastValue( DWORD nameID );
};
/*
//////////////////////////////////////////////////////////////////////////////////////////////////
/// ����� �������� ������
class COPCDataSource :
	public COPCDataOperator
{
public:
	COPCDataManager *m_Manager;

	COPCDataSource();
	virtual ~COPCDataSource() { Unsubscribe(); }

	virtual bool Subscribe( COPCDataManager *man );
	virtual bool Unsubscribe();
};

*/
}; // namespace opcData;

using namespace opcData;
