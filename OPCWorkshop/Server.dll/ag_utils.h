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

#include <vector>

#ifndef  __ATLTIME_H__
	#error Must include atltime.h
#endif


namespace AG
{


namespace Utils
{

	/*!
		Класс осуществляет извлечение произвольных частей из полного пути к файлу
	*/
	class CPathExtractor
	{
		TCHAR drive[_MAX_DRIVE];
		TCHAR dir[_MAX_DIR];
		TCHAR fname[_MAX_FNAME];
		TCHAR ext[_MAX_EXT];
	public:
		CPathExtractor( LPCTSTR filename )
		{
			ZeroMemory( drive, _MAX_DRIVE );
			ZeroMemory( dir, _MAX_DIR );
			ZeroMemory( fname, _MAX_FNAME );
			ZeroMemory( ext, _MAX_EXT );
			_tsplitpath(filename, drive, dir, fname, ext );
		}

		CString path()
		{
		CString str;
			
			str.Format(_T("%s%s"), drive, dir);
			return str;
		}
		CString name()
		{
			return CString(fname);
		}
		CString full_name()
		{
			return CString(fname) + CString(ext);
		}
	};


inline void UuidToString(const UUID &m_guid,CString &rString)
{
	rString.Format(_T("%08lX-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X"),
		m_guid.Data1, m_guid.Data2, m_guid.Data3,
		m_guid.Data4[0], m_guid.Data4[1], m_guid.Data4[2], m_guid.Data4[3],
		m_guid.Data4[4], m_guid.Data4[5], m_guid.Data4[6], m_guid.Data4[7]);
}

inline HRESULT ShowOlePropertyPage(HWND hWnd,long x,long y,LPCOLESTR caption,IUnknown *unk,GUID additional,IUnknown *config)
{
HRESULT hr;

	if(unk == NULL)
		return E_FAIL;

	CComQIPtr<ISpecifyPropertyPages> lpSPP = unk;
	if(lpSPP == NULL) return E_FAIL;

	CAUUID cauuid;
	hr = lpSPP->GetPages(&cauuid);
	if FAILED(hr)
		return hr;
//	lpSPP.Release(); само по деструктору отвалится 

	std::vector<GUID> pages;
	for(ULONG i=0;i<cauuid.cElems;i++)
		pages.push_back(cauuid.pElems[i]);

	if(additional != CLSID_NULL)
		pages.push_back(additional);

	std::vector<IUnknown*> uV;
	uV.push_back(unk);
	if(config)  {
		//uV.push_back(NULL);
		uV.push_back(config);
	}

	HRESULT res = OleCreatePropertyFrame(hWnd,x,y,caption,
									uV.size(),&(*uV.begin()),
									(DWORD)pages.size(),&pages[0],0,0,NULL);

	return res;

}

inline void StepMessageLoop(void)
{
	MSG msg;

	// There is one or more window message available. Dispatch them
	while(PeekMessage(&msg,0,0,0,PM_NOREMOVE))
	{
		// check for unicode window so we call the appropriate functions
		BOOL bUnicode = ::IsWindowUnicode(msg.hwnd);
		BOOL bRet;

		if (bUnicode)
			bRet = ::GetMessageW(&msg, NULL, 0, 0);
		else
			bRet = ::GetMessageA(&msg, NULL, 0, 0);

		if (bRet > 0)
		{
			::TranslateMessage(&msg);

			if (bUnicode)
				::DispatchMessageW(&msg);
			else
				::DispatchMessageA(&msg);
		}
	}
}

inline bool isFileExists (LPCTSTR fname)
{
    WIN32_FIND_DATA wfd;
    HANDLE hFind = ::FindFirstFile(fname, &wfd);
    if (INVALID_HANDLE_VALUE != hFind) {
        // Если этого не сделать то произойдет утечка ресурсов
        ::FindClose(hFind);
        return true;
    }
    return false;
}

inline bool isDirectory (LPCTSTR fname)
{
	CString str = fname;
	str.TrimRight(_T("\\/"));
    WIN32_FIND_DATA wfd;
    HANDLE hFind = ::FindFirstFile(str, &wfd);
	if (INVALID_HANDLE_VALUE != hFind && 
		(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
        // Если этого не сделать то произойдет утечка ресурсов
        ::FindClose(hFind);
        return true;
    }
    return false;
}

inline CString extractPath(LPCTSTR filename)
{
	return CPathExtractor(filename).path();
}

inline CString extractNameFromPath(LPCTSTR filename)
{
	return CPathExtractor(filename).name();
}


inline CString AtlLoadString(UINT nID)
{
CString str;

	::AtlLoadString(nID,str.GetBufferSetLength(MAX_PATH),MAX_PATH);
	str.ReleaseBuffer();

	return str;
}


inline BOOL rotateBackupFiles(LPCTSTR file_name)
{
	if( ! isFileExists( file_name ) )
		return false;

	CPathExtractor file_path(file_name);

	CString path = file_path.path() + _T("_backup\\");
	CString file = file_path.full_name() + 
			CTime::GetCurrentTime().Format(_T(".%d%m%y_%H%M%S.back"));	
	
	CreateDirectory( path, NULL );
	return MoveFile( file_name, path + file );
}

}

}