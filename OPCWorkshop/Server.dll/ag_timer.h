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


template <class T>
class CWin32Timer :
	private thread::CThreadingObject
{
	DWORD m_ms; // время таймера
	T* m_ptr; // указатель на CallBack
public:
	CWin32Timer(T* ptr)
	{	
		m_ms = 0;
		m_ptr = ptr;
		
	}

	void SetTimer(int ms)
	{
		m_ms = ms;
		if( isRunning() ) {
			WakeUp();
		}
		else {
			Execute();
		}
	}

	void KillTimer()
	{
		Shutdown();
	}

	void run()
	{
		while(1)
		{
			HANDLE h[2] = {  m_hWakeUp, m_hWantQuit };
			DWORD ret_code = WaitForMultipleObjects( 2, h, FALSE, m_ms );
			switch(ret_code) {
				case WAIT_OBJECT_0: //  если сигнал m_hWakeUp - значит поменяли значение таймера
					ResetEvent( m_hWakeUp );
					break;
				case WAIT_OBJECT_0+1: // значит пора на выход
					// предварительно сбрасываем флажок чтобы можно было запуститься еще раз
					ResetEvent( m_hWantQuit );
					return;
				case WAIT_TIMEOUT:
					try {
						m_ptr->OnTimer();
					} catch(...) {
						ATLTRACE("Exception On CWin32Timer::run( call OnTimer() )\n");
					}
				break;
			}
		}
	}
	void step()
	{
	}
	bool IsRunning()
	{
		return thread::CThreadingObject::isRunning();
	}	
};