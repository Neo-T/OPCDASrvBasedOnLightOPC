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
// Server.dll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "opcda.h"

class COPCServerModule : 
	public CAtlExeModuleT< COPCServerModule >
{
public :
	//DECLARE_LIBID(LIBID_XmlUtilsLib)
	//DECLARE_REGISTRY_APPID_RESOURCEID(IDR_XMLUTILS, "{0E3C0CC6-5397-49E4-8273-7DFB51B8787C}")
};

COPCServerModule _AtlModule;


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    
	
	return TRUE;
}


#include "opcda_i.c"

