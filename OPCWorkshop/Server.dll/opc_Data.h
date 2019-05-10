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
     Идеология такая, что источник данных передает пачку данных в COPCDataManager::pushNewData
     где она попадает в общую очередь
	 пачки данных разбиваются в сплошной поток данных и распихиваются по подписчикам (COPCDataCustomer)

	 Реализация COPCDataCustomer позволяет управлять какие параметры будут попадать во внутреннюю очередь
	 параметров. ( SetAcceptAll, ResetAcceptList, AcceptParam )
*/

#define MAX_CUSTOMER_BUFFER 10000

/* 
   Флаг отвечающий за возможность фильтрования одинаковых значений параметра 
   если в сервер записали тег с тем-же самым значением и статусом, но другим временем, то при 
   USE_NEW_DATA_FILTER == 1 такой тег передаваться клиенту не будет, иначе будет передаваться все 
   что в сервер записано.
*/
#define USE_NEW_DATA_FILTER 1

namespace opcData {

//extern CRarefiedArray<CAG_Value> g_LastValues;

class COPCDataCustomer;
class COPCDataManager;
class COPCDataSource;

typedef std::list<COPCDataCustomer*> COPCDataCustomerList;

/// абстрактный класс для реализации общей функциональности подписчиков и источников
class COPCDataOperator
{
public:
	COPCDataManager *m_Manager;

	COPCDataOperator();
	virtual ~COPCDataOperator();

	virtual bool Subscribe( COPCDataManager *man ) = 0;
	virtual bool Unsubscribe() = 0;
};

/// шаблон реализующий очередь произвольных типов защищенную с помощью критической секции
/// в основном подходит только для указателей, но если есть копирующий конструктор
/// то можно и без указателей
template <class T>
class COPCDataQueue //: private CComAutoCriticalSection
{
	/// очередь параметров
	CComAutoCriticalSection m_QueueSect;
	std::list<T*> m_Queue;
public:
	/// засунуть в очередь диапазон (с копированием)
	template< class _it >
	void push_copy ( _it begin, _it end )
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		for( _it it = begin; it != end; ++it)
			m_Queue.push_back( new T(*it) );
	}

	/// засунуть в очередь диапазон
	template< class _it >
	void push ( _it begin, _it end )
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		m_Queue.insert( m_Queue.end(), begin, end );
	}

	/// засунуть в очередь
	void push ( T* value )
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		m_Queue.push_back( value );
	}

	/// выплюнуть из очереди
	T* pop()
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		if( m_Queue.size() ) {
			T* vect = *m_Queue.begin();
			m_Queue.pop_front();
			return vect;
		}
		/// если пусто, то возвращаем нулевое значение - поэтому можно держать только указатели
		return NULL;
	}
	/// получить размер очереди 
	size_t size()
	{
		thread::CCritSectLocker locker(&m_QueueSect);
		return m_Queue.size();
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////
/// подписчик на данные от COPCDataManager
class COPCDataCustomer :
	public COPCDataOperator,
	private thread::CThreadingObject
{
protected:
	/// флаг признака, что приемник принимает все параметры
	bool m_AcceptAllData;
	CComAutoCriticalSection m_AcceptedParamsSect;
	std::set<OPCHANDLE> m_AcceptedParams;

	/// очередь нефильтрованных параметров
	COPCDataQueue<CAG_Value> m_Queue;

	/// Архив последних значений каждого параметра
	CRarefiedArray<CAG_Value> m_LastValues;
	/// запихивает тег в конечный буффер для отправки клиенту 
	void PushToClient( CAG_Value* adapt );
protected:
	/// фильтрованные параметры.
	std::map<OPCHANDLE,CAG_Value> m_FilteredData;
	/// критическая секция защищает вектор m_FilteredData
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
	/// функция перегружаемая наследником класса,
	/// выдает true если нужно отдавать подписчику параметры не по одному а всей пачкой 
	// virtual CustomerType pushDataType(); (может и не нужна)

	/// передать подписчику очередной параметр
	/// эта функция должна отдавать управление как можно быстрее
	virtual int pushData(CAG_Value* adap, bool copy = true);
	/// передать подписчику очередную пачку параметров
	/// эта функция должна отдавать управление как можно быстрее
	virtual int pushData(CAG_ValueVector* adap);


public:
	/// устанавливает принимать ли все параметры подписчику
	void SetAcceptAll( bool allow = true );
	/// сбрасывает список параметров, которые может принимать подписчик
	void ResetAcceptList( );
	/// добавляет в список элемент, который будет приниматься подписчиком.
	void AcceptParam( OPCHANDLE h );
	/// удаляет элемент из списка подписки
	void DeclineParam( OPCHANDLE h );
	/// проверяет подписан ли потребитель на данный параметр
	bool isAcceptedParam( OPCHANDLE h );

	/// получить для определенного параметра его последнее значение 
	bool getLastValue( OPCHANDLE h, CAG_Value& value );
protected:
	/// фильтрует пераметры из входной очереди, и перекладывает их во внутренний буффер.
	virtual void step();
};

//////////////////////////////////////////////////////////////////////////////////////////////////
/// класс обеспечивающий отношения между opc_DataSource & opc_DataCustomer
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
	/// подписать кастомера на поток данных от манагера
	bool AddCustomer( COPCDataCustomer *cust);
	/// удалить кастомера из подписки
	bool RemoveCustomer( COPCDataCustomer *cust);

public:
	/// засовываем в манагер новую порцию данных
	/// сам объект вектора остается у манагера и ставиться им в очередь, удалит он его сам.
	virtual HRESULT pushNewData( CAG_ValueVector *vect );

	/// засовываем в манагер новую порцию данных
	/// сам объект вектора остается у манагера и ставиться им в очередь, удалит он его сам.
	virtual HRESULT pushNewData( CAG_Value &val );

	/// процедура распихивающия данные по подписчикам.
	virtual void step();

	/// получить из глобального буфера последние значения 
	CAG_Value getLastValue( DWORD nameID );
};
/*
//////////////////////////////////////////////////////////////////////////////////////////////////
/// Класс источник данных
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
