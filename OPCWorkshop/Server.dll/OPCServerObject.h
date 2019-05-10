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

#ifdef _USRDLL
	#define ExportClass   __declspec( dllexport )
#else
	#define ExportClass   __declspec( dllimport )
#endif


class COPCReceiveData
{
public:
	virtual void newData(LPCTSTR name, FILETIME &time, VARIANT &value) = 0;
};

#ifndef __opcda_h__
	typedef 
	enum tagOPCSERVERSTATE
		{	OPC_STATUS_RUNNING	= 1,
		OPC_STATUS_FAILED	= OPC_STATUS_RUNNING + 1,
		OPC_STATUS_NOCONFIG	= OPC_STATUS_FAILED + 1,
		OPC_STATUS_SUSPENDED	= OPC_STATUS_NOCONFIG + 1,
		OPC_STATUS_TEST	= OPC_STATUS_SUSPENDED + 1,
		OPC_STATUS_COMM_FAULT	= OPC_STATUS_TEST + 1
		} 	OPCSERVERSTATE;
#endif

/*!
	Интерфейсный класс дял работы с OPC сервером 
	
	все функции возвращают 0 если нет ошибок
*/
class ExportClass COPCServerObject
{
protected:
	  DWORD m_objid;
public:
	COPCServerObject(void);
	virtual ~COPCServerObject(void);

	static const DWORD QualityGood;
	static const DWORD QualityBad;

	/// Установить имя объекта сервера
	void setServerProgID(LPCTSTR progID);

	/// установить CLSID сервера 
	void setServerCLSID(REFCLSID progID);

	/// зарегистрировать сервер в системе
	int RegisterServer();

	/// резрегистрировать сервер в системе
	int UnregisterServer();

    /// запустить сервер
	int StartServer(OPCSERVERSTATE state = OPC_STATUS_NOCONFIG);

    /// отстановить процесс сервера
	int StopServer();

	/// 
	void SetServerState(OPCSERVERSTATE state);

	/// указать серверу разделитель в именах параметров
	void SetDelimeter( const char *ch );

	/// добавить тег в базу сервера
	///		при этом указывается тип тега и возможность клиенту писать в этот параметр
	void AddTag( LPCTSTR name, VARTYPE type, bool readOnly = true);

	/// передать значение параметра
	bool WriteValue( LPCTSTR name, FILETIME ft, WORD quality, VARIANT &value );
	bool WriteValue( LPCTSTR name, FILETIME ft, WORD quality, int value );
	bool WriteValue( LPCTSTR name, FILETIME ft, WORD quality, float value );
	bool WriteValue( LPCTSTR name, FILETIME ft, WORD quality, double value );
	bool WriteValue( LPCTSTR name, FILETIME ft, WORD quality, int* value , unsigned count );
	bool WriteValue( LPCTSTR name, FILETIME ft, WORD quality, float* value, unsigned count );
	bool WriteValue( LPCTSTR name, FILETIME ft, WORD quality, double* value, unsigned count );

	/// указать серверу интерфейс по которому сообщать об изменении параметров базы
	void setDataReceiver( COPCReceiveData *receiver);


};

extern ExportClass FILETIME FILETIME_NULL;