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

class CLockWrite;
class CLockRead;

class CRWMonitor
{
	CRITICAL_SECTION cs;

private:
	friend class CLockWrite;
	friend class CLockRead;

	void lock() 
	{
		EnterCriticalSection(&cs);
	} 
	void unlock() 
	{
		LeaveCriticalSection(&cs);
	} 
public:
	CRWMonitor() 
	{ 
		InitializeCriticalSection(&cs);
	}   
	~CRWMonitor() 
	{ 
		DeleteCriticalSection(&cs);
	}
};


class CLockRead
{
	CRWMonitor &m_mon;
public:
	CLockRead(CRWMonitor *mon) : m_mon(*mon) 
	{
		if( mon == NULL) throw(_T("CLockRead:: mon==NULL"));
		m_mon.lock();
	}
	CLockRead(CRWMonitor &mon) : m_mon(mon) 
	{
		m_mon.lock();
	}
	~CLockRead()
	{
		m_mon.unlock();
	}
};

class CLockWrite
{
	CRWMonitor &m_mon;
public:
	CLockWrite(CRWMonitor &mon) : m_mon(mon) 
	{
		m_mon.lock();
	}
	~CLockWrite()
	{
		m_mon.unlock();
	}
};
