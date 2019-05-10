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

#include "NameIndex.h"

#pragma pack( push, AG_Value )
#pragma pack (1)

class CAG_ValueBuffer
{
public:
	DWORD m_NameId;			// идентификатор имени параметра
	FILETIME m_Time;		// время параметра
	WORD m_Quality;		// OPC quolity

	CComVariant m_Value;	// Значение параметра
	
	CAG_ValueBuffer()
	{
		ZeroMemory( this, sizeof(CAG_ValueBuffer) );
	}
	~CAG_ValueBuffer()
	{
		VariantClear( &m_Value );
	}
};


class CAG_Value :
	public CAG_ValueBuffer
{
	inline void ravno(const CAG_Value& val)
	{
		m_NameId = val.m_NameId;
		m_Time = val.m_Time;
		m_Value.Clear();
		m_Value = val.m_Value;
		m_Quality = val.m_Quality;
			
		m_Name = val.m_Name;
		m_Type = m_Value.vt;
	}
public:

	CString m_Name;			// текстовое имя параметра
	VARTYPE m_Type;

	CAG_Value() { m_Type = VT_EMPTY; }

	/// копирующий конструктор
	CAG_Value(const CAG_Value& val)
	{
		ravno(val);
	}
	
	CAG_Value(CAG_ValueBuffer* buff)
	{
		*this = buff; // используем нижеследующий оператор присваивания 
	}

	inline const CAG_Value& operator =(const CAG_Value& val)
	{
		ravno(val);
		return *this;
	}
		
	inline const CAG_Value& operator =(const CAG_ValueBuffer* val)
	{
		m_NameId = val->m_NameId;
		m_Time = val->m_Time;
		m_Value = val->m_Value;
		m_Quality = val->m_Quality;
			
		m_Name = g_NameIndex[m_NameId];
		m_Type = m_Value.vt;
		return *this;
	}

	inline bool operator !=(const CAG_Value& val)
	{
		return ( m_NameId != val.m_NameId ||
				 // m_Time   != val.m_Time   ||  будем сравнивать только значения и статусы 
				 m_Value  != val.m_Value    ||
				 m_Quality != val.m_Quality ||
				 m_Name != val.m_Name /*||
				 m_Type  != val.m_Type*/ );
	}


public:

	void type( LPCTSTR s)
	{
		CString str(s);
		if(str == _T("VT_BSTR")) { m_Type = VT_BSTR; return; }
		if(str == _T("VT_I1")) { m_Type = VT_I1; return; }
		if(str == _T("VT_I2")) { m_Type = VT_I2; return; }
		if(str == _T("VT_I4")) { m_Type = VT_I4; return; }
		if(str == _T("VT_I8")) { m_Type = VT_I8; return; }
		if(str == _T("VT_R4")) { m_Type = VT_R4; return; }
		if(str == _T("VT_R8")) { m_Type = VT_R8; return; }

		if(str == _T("VT_UI1")) { m_Type = VT_UI1; return; }
		if(str == _T("VT_UI2")) { m_Type = VT_UI2; return; }
		if(str == _T("VT_UI4")) { m_Type = VT_UI4; return; }
		if(str == _T("VT_UI8")) { m_Type = VT_UI8; return; }
		m_Type = VT_EMPTY;
	}

	CString type()
	{
		CString str;

		switch(m_Type) {
			case VT_BSTR: str = _T("VT_BSTR");	break;
			case VT_I1: str = _T("VT_I1"); 		break;
			case VT_I2: str = _T("VT_I2"); 		break;
			case VT_I4: str = _T("VT_I4"); 		break;
			case VT_I8: str = _T("VT_I8"); 		break;
			case VT_R4: str = _T("VT_R4"); 		break;
			case VT_R8: str = _T("VT_R8"); 		break;
			case VT_UI1: str = _T("VT_UI1"); 	break;
			case VT_UI2: str = _T("VT_UI2"); 	break;
			case VT_UI4: str = _T("VT_UI4"); 	break;
			case VT_UI8: str = _T("VT_UI8"); 	break;
			default: str = _T("unknown");		break;
		};
		return str;
	}

	void value( LPCTSTR str )
	{
		m_Value.Clear();
		m_Value.vt = m_Type;

		switch(m_Type) {
			case VT_BSTR: m_Value.bstrVal = CComBSTR(str).Detach();	break;
			case VT_I1:  m_Value.bVal = _tstoi(str);	break;
			case VT_I2:  m_Value.iVal = _tstoi(str);	break;
			case VT_I4:  m_Value.lVal = _tstol(str);	break;
			case VT_I8:  m_Value.llVal = _tstoi64(str);	break;
			case VT_R4:  m_Value.fltVal = (float)_tstof(str);	break;
			case VT_R8:  m_Value.dblVal = _tstof(str);	break;
			case VT_UI1: m_Value.bVal = _tstoi(str);	break;
			case VT_UI2: m_Value.uiVal = _tstoi(str);	break;
			case VT_UI4: m_Value.ulVal = _tstol(str);	break;
			case VT_UI8: m_Value.ullVal = _tstoi64(str);	break;
		};
	}

	CString value()
	{
		CString str;

		switch(m_Value.vt) {
			case VT_BSTR:str = CW2T(m_Value.bstrVal);							break;
			case VT_I1:  str.Format(_T("%d"),    int(m_Value.bVal));			break;
			case VT_I2:  str.Format(_T("%d"),    int(m_Value.iVal));			break;
			case VT_I4:  str.Format(_T("%d"),    m_Value.lVal);				break;
			case VT_I8:  str.Format(_T("%I64d"), m_Value.llVal);				break;
			case VT_R4:  str.Format(_T("%f"),    double(m_Value.fltVal) );	break;
			case VT_R8:  str.Format(_T("%f"),    m_Value.dblVal );			break;
			case VT_UI1: str.Format(_T("%u"),    unsigned(m_Value.bVal));		break;
			case VT_UI2: str.Format(_T("%u"),    unsigned(m_Value.uiVal));	break;
			case VT_UI4: str.Format(_T("%u"),    m_Value.ulVal);				break;
			case VT_UI8: str.Format(_T("%I64u"), m_Value.ullVal);				break;
			default:     str = _T("unknown");								break;
		};
		return str;
	}

	HRESULT time(LPCTSTR str) // %H:%M:%S %d-%m-%Y
	{
		long H,M,S,d,m,Y,ms;

		long count = _stscanf(str, _T("%d-%d-%d %d:%d:%d.%d "),&d,&m,&Y,&H,&M,&S,&ms);
		if(count < 6) return E_FAIL;

		SYSTEMTIME st;
		COleDateTime tm( Y, m, d, H, M, S );
		tm.GetAsSystemTime(st);
		::SystemTimeToFileTime(&st, &m_Time);
		return S_OK;
	}

	bool isNull()
	{
		if( m_NameId == 0 && m_Name == _T("") &&
			m_Value.vt == VT_EMPTY ) return true;

		return false;
	}
};

typedef std::vector<CAG_Value> CAG_ValueVector;
typedef std::map<DWORD,CAG_Value> CAG_ValueMap;
typedef std::list<CAG_Value> CAG_ValuesList;
typedef std::list<CAG_ValueVector*> CAG_ValuesQueue;


#pragma pack( pop, AG_Value )
