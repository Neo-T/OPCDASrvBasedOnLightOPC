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
#include "stdafx.h"

#include "ag_thread.h"

CNameIndex g_NameIndex;

DWORD CNameIndex::MaxIndex() 
{ 
	thread::CCritSectLocker locker(m_sect);
	return m_NextIndex-1; 
}


/// добавить пару, например из базы :D 
void CNameIndex::addPair( DWORD id, LPCTSTR name )
{
thread::CCritSectLocker locker(m_sect);
	m_StringIndex[name] = id;
	m_DwordIndex[id] = name;
	m_NextIndex = max( m_NextIndex - 1, id ) + 1;
}


CString CNameIndex::operator[] ( DWORD index )
{
	CDwordMapString::iterator it;

	{
		thread::CCritSectLocker locker(m_sect);
		it = m_DwordIndex.find(index);
	}
	if(it != m_DwordIndex.end()) 
		return (*it).second;

	return "";
}

DWORD CNameIndex::operator[] ( LPCTSTR string )
{
DWORD ret = 0;
CStringMapDWORD::iterator it;

	{
		thread::CCritSectLocker locker(m_sect);
		it = m_StringIndex.find(string);
	}
	if(it != m_StringIndex.end())
		ret = (*it).second;
	else {
		thread::CCritSectLocker locker(m_sect);
		m_StringIndex[string] = m_NextIndex;
		m_DwordIndex[m_NextIndex] = string;
		ret = m_NextIndex;
		m_NextIndex ++;
		m_modified = true;
	}
	return ret;	
}
