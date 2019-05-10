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

#include <list>
#include <algorithm>

class CItemForBrowse
{
public:
	CItemForBrowse( OPCHANDLE h, LPCTSTR n, VARTYPE t, DWORD write = OPC_READABLE)
	{
		handle = h;
		name = n;
		type = t;
		dwAccessRights = write;
	}
	CItemForBrowse( const CItemForBrowse& it )
	{
		handle = it.handle;
		name = it.name;
		type = it.type;
		dwAccessRights = it.dwAccessRights;
	}

	CString name;
	VARTYPE type;
	DWORD dwAccessRights;
	OPCHANDLE handle;
	
	bool operator ==(const OPCHANDLE& h)
	{
		return (handle == h);
	}
	bool operator ==(LPCTSTR n)
	{
		return (name == n);
	}

};


class CBrowseItemsList :
	public std::list<CItemForBrowse>
{
	//typedef std::map< OPCHANDLE, std::list<CItemForBrowse>::reverse_iterator > CFindHash;
	//typedef std::pair< OPCHANDLE, std::list<CItemForBrowse>::reverse_iterator > CFindHashPair;
	//CFindHash m_HashForFind;
public:
	//virtual void push_back(const CItemForBrowse& _Val)
	//{	// insert element at end
	//	_Insert(end(), _Val);
	//	m_HashForFind.insert( CFindHashPair( _Val.handle, rbegin() ));
	//}
	iterator find( OPCHANDLE key )
	{
		return std::find( 	begin(), end(), key );
		//CFindHash::iterator it = m_HashForFind.find(key);
		//if(it == m_HashForFind.end() ) return end();
		//
		//return (*it).second;
	}
	iterator find( LPCTSTR key )
	{
		return std::find( 	begin(), end(), key );
		//CFindHash::iterator it = m_HashForFind.find(key);
		//if(it == m_HashForFind.end() ) return end();
		//
		//return (*it).second;
	}
};

extern CBrowseItemsList g_BrowseItems;