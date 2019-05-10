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


class COPCDataTranslator :
	public COPCDataCustomer
{
	COPCReceiveData *m_Receiver;
public:

	COPCDataTranslator()
	{
		m_Receiver = NULL;
	}
	/// фильтрует пераметры из входной очереди, и отправляет их клиенту
	virtual void step()
	{
		CAG_Value* adapt = NULL;

		while( (adapt = m_Queue.pop()) != NULL ) {
			if( m_Receiver ) {
				if( m_AcceptAllData ) {
					m_Receiver->newData( adapt->m_Name, adapt->m_Time, adapt->m_Value );
				}
				else {
					thread::CCritSectLocker locker(&m_AcceptedParamsSect);
					if( m_AcceptedParams.find( adapt->m_NameId ) != m_AcceptedParams.end())
						m_Receiver->newData( adapt->m_Name, adapt->m_Time, adapt->m_Value );
				}
			}
			delete adapt;
		}
	}

	void setDataReceiver( COPCReceiveData *receiver)
	{
		m_Receiver = receiver;
	}

};