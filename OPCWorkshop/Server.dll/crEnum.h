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

template <class EnumType, class ElementType, class Enumerator>
HRESULT CreateEnumerator(Enumerator/*IUnknown***/ ppUnk,
                            ElementType* begin, ElementType* end,
                            IUnknown* pUnk,
                            CComEnumFlags flags)
{
    if (ppUnk == NULL)
        return E_POINTER;
    *ppUnk = NULL;

    CComObject<EnumType>* pEnum = NULL;
    HRESULT hr = CComObject<EnumType>::CreateInstance(&pEnum);

    if (FAILED(hr))
        return hr;

    hr = pEnum->Init(begin, end, pUnk, flags);

    if (SUCCEEDED(hr))
        hr = pEnum->QueryInterface(ppUnk);

    if (FAILED(hr))
        delete pEnum;

    return hr;

} // CreateEnumerator

typedef CComEnum<IEnumString, &IID_IEnumString, LPOLESTR,
                              _Copy<LPOLESTR> > StringEnum;

typedef CComEnum<IEnumUnknown, &IID_IEnumUnknown, LPUNKNOWN,
                              _Copy<LPUNKNOWN> > UnknownEnum;

