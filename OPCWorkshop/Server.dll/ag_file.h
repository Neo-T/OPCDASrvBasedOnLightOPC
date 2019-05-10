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


#include <stdio.h>

/// Simple wrapper around stdlib FILE*
class AGFile
{
	FILE *handle;
public:
	AGFile()
	{
		handle = NULL;
	}
	AGFile(LPCTSTR file, LPCTSTR mode)
	{
		handle = NULL;
		fopen(file, mode);
	}

	~AGFile()
	{
		fclose();
	}

	FILE* operator =(FILE* file)
	{
		fclose();
		return handle = file;
	}

	operator FILE*()
	{
		return handle;
	}
	//operator bool()
	//{
	//	return handle != NULL;
	//}


	FILE* fopen(LPCTSTR file, LPCTSTR mode)
	{
		AGFile::fclose();
		handle = ::_tfopen(file,mode);
		return handle;
	}

	int fclose()
	{
		int r = EOF;
		if(	handle ) {
			r = ::fclose( handle );
			handle = NULL;
		}
		return r;
	}
	//int printf(LPCTSTR format, ... )
	//{
	//	va_list marker;

	//	va_start( marker, format );     /* Initialize variable arguments. */
	//	int ret = _vftprintf( handle, format, marker );
	//	va_end( marker );
	//	return ret;
	//}
};