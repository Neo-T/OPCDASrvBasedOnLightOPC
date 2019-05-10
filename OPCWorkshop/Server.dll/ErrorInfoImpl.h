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
#include <atlstr.h>

template <class T,const CLSID* pclsid = &CLSID_NULL>
class AG_IErrorInfoImpl :
	public IDispatchImpl<IErrorInfo, &IID_IErrorInfo>
{
protected:
	DWORD m_ErrorDescriptionID;
	CString m_ErrMsg;
public:

	AG_IErrorInfoImpl()
	{
		m_ErrorDescriptionID = 0;
	}


	void setErrorString( DWORD id, ... )
	{
		va_list marker;
		va_start( marker, id );     /* Initialize variable arguments. */

		CString format; format.LoadString(id);
		m_ErrMsg.FormatV( format , marker );
	    va_end( marker );

		m_ErrorDescriptionID = id;
	}

	void setErrorString( LPCTSTR str )
	{
		m_ErrMsg = str;
		m_ErrorDescriptionID = 1;
	}
public:

	STDMETHOD(GetGUID)( GUID *pGUID)
	{
		if(	pGUID == NULL ) return E_INVALIDARG;
		*pGUID = *pclsid;
		return S_OK;
	}
    STDMETHOD(GetSource)( BSTR *pBstrSource)
	{
		LPOLESTR ptr = NULL;
		if( !FAILED( ProgIDFromCLSID(*pclsid, &ptr) )) {
			CComBSTR str = ptr;
			CoTaskMemFree(ptr);

			*pBstrSource = str.Detach();
		}
		return S_OK;
	}
    STDMETHOD(GetDescription)( BSTR *pBstrDescription)
	{
		if(m_ErrorDescriptionID)  {
		//	CComBSTR str;
		//	str.LoadString(m_ErrorDescriptionID);
		//	*pBstrDescription = str.Detach();
		//	return S_OK;
		//}
			CComBSTR str = m_ErrMsg;
			*pBstrDescription = str.Detach();
		}
		return S_OK;
	}
    STDMETHOD(GetHelpFile)( BSTR *pBstrHelpFile )
	{
		return E_NOTIMPL;
	}
    STDMETHOD(GetHelpContext)( DWORD *pdwHelpContext )
	{
		return E_NOTIMPL;
	}

	DWORD showMessageBoxByErrorInfo( )
	{
		return ::MessageBox(NULL, m_ErrMsg, _T("showMessageBoxByErrorInfo()"), MB_OK | MB_ICONERROR );
	}
};

class errorDescription
{
	CString str;
public:
	errorDescription( IUnknown *obj)
	{
		CComQIPtr<IErrorInfo> inf = obj;
		if(inf == NULL) return;

		CComBSTR msg;
		inf->GetDescription(& msg);
		str = CW2T(msg);
	}

	operator LPCTSTR()
	{
		return str;
	}
};

inline DWORD showMessageBoxByErrorInfo( IUnknown *obj )
{
	CComQIPtr<IErrorInfo> inf = obj;
	if(inf == NULL) return 0;

	CComBSTR msg;

	inf->GetDescription(& msg);
	
	return ::MessageBox(NULL, CW2T( msg ), _T("showMessageBoxByErrorInfo()"), MB_OK | MB_ICONERROR );
}