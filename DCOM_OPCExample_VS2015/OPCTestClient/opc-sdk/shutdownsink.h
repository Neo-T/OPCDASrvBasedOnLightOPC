// **************************************************************************
// shutdownsink.h
//
// Description:
//	Defines the IKShutdownSink class.
//
// DISCLAIMER:
//	This programming example is provided "AS IS".  As such Kepware, Inc.
//	makes no claims to the worthiness of the code and does not warranty
//	the code to be error free.  It is provided freely and can be used in
//	your own projects.  If you do find this code useful, place a little
//	marketing plug for Kepware in your code.  While we would love to help
//	every one who is trying to write a great OPC client application, the 
//	uniqueness of every project and the limited number of hours in a day 
//	simply prevents us from doing so.  If you really find yourself in a
//	bind, please contact Kepware's technical support.  We will not be able
//	to assist you with server related problems unless you are using KepServer
//	or KepServerEx.
// **************************************************************************


#ifndef _SHUTDOWNSINK_H
#define _SHUTDOWNSINK_H

// **************************************************************************
class IKShutdownSink : public IOPCShutdown
	{
	public:		
		IKShutdownSink ();
		~IKShutdownSink ();

		// IUnknown Methods
		STDMETHODIMP         QueryInterface (REFIID iid, LPVOID *ppInterface);
		STDMETHODIMP_(ULONG) AddRef ();
		STDMETHODIMP_(ULONG) Release ();

		// IOPCShutdown Methods 
		STDMETHODIMP ShutdownRequest (LPCWSTR lpwszReason);

	private:
		DWORD m_cnRef;
	};


#endif // _SHUTDOWNSINK_H
