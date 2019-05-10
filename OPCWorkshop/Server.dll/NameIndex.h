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

typedef std::map<CString,DWORD> CStringMapDWORD;
typedef std::map<DWORD,CString> CDwordMapString;

class CNameIndex
{
protected:
	CComAutoCriticalSection m_sect;
	
	bool m_modified;
	CStringMapDWORD m_StringIndex;
	CDwordMapString m_DwordIndex;
	DWORD m_NextIndex;
public:
	
	CNameIndex()
	{
		m_NextIndex = 1;
		m_modified = false;
	}

	DWORD MaxIndex();
	inline bool IsModified() { return m_modified; }

	/// добавить пару, например из базы :D 
	void addPair( DWORD id, LPCTSTR name );


	/// операторы определения соответствия строки числу или числа строке 
	CString operator[] ( DWORD index );
	DWORD operator[] ( LPCTSTR string );

	//void fillNameVector( std::vector<LPOLESTR> &strings )
	//{
	//	CDwordMapString::iterator it;

	//	{
	//		CLockRead locker(*this);
	//		strings.reserve( m_DwordIndex.size() );
	//		for( it = m_DwordIndex.begin(); it != m_DwordIndex.end(); ++it)
	//			strings.push_back( (*it).second.AllocSysString() );
	//	}		
	//}

	typedef CDwordMapString::iterator iterator;
	iterator begin() 
	{
		return m_DwordIndex.begin();
	}
	iterator end() 
	{
		return m_DwordIndex.end();
	}
};

extern CNameIndex g_NameIndex;
