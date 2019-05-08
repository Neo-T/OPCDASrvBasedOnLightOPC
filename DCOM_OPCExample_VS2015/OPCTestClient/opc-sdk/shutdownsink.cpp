// **************************************************************************
// shutdownsink.cpp
//
// Description:
//	Implements our IOPCShutdown class and IOPCShutdown COM interface.  OPC
//	Servers use this interface to advise us that they are shutting down.
//	Upon shuch notifications, we should release all connections and 
//	interfaces to that server.  We must maintain separate callbacks for each
//	OPC Server we are connected to.
//
//	This interface is rquired for OPC version 2.0.
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
#include "opccomn.h"
#include "shutdownsink.h"


// **************************************************************************
// IKShutdownSink ()
//
// Description:
//	Constructor.	Reference count is initialize to zero.
//
// Parameters:
//  CKServer	*pServer	Pointer to CKServer object to associated with
//							  this interface instance.
//
// Returns:
//  none
// **************************************************************************
IKShutdownSink::IKShutdownSink () : m_cnRef (0)
{

}

// **************************************************************************
// ~IKShutdownSink ()
//
// Description:
//	Destructor.
//
// Parameters:
//  none
//
// Returns:
//  none
// **************************************************************************
IKShutdownSink::~IKShutdownSink ()
	{
	}

// **************************************************************************
// AddRef ()
//
// Description:
//	This function is called to increment our reference count.  Caller should 
//	increment our reference count each time a new pointer to this interface
//	is created (except when obtained by a call to QueryInterface which will
//  bump the reference count on its behalf). 
//
//	This is one of the 3 member functions all COM interfaces must implement. 
//
// Parameters:
//	none
//
// Returns:
//	STDMETHODIMP_(ULONG) - Reference count resulting from this call.
// **************************************************************************
STDMETHODIMP_(ULONG) IKShutdownSink::AddRef ()
	{
	// Increment the reference count then return value:
	return (++m_cnRef);
	}

// **************************************************************************
// Release ()
//
// Description:
//	This function is called to decrement our reference count.  Caller should
//	decrement our reference count just before each pointer to this interface 
//	is destroyed (goes out of scope).  Standard COM practice requires us to
//  self-delete once the refernce count returns to zero.
//
//	This is one of the 3 member functions all COM interfaces must implement.
//
// Parameters:
//	none
//
// Returns:
//	STDMETHODIMP_(ULONG) - Reference count resulting from this call.
// **************************************************************************
STDMETHODIMP_(ULONG) IKShutdownSink::Release ()
	{
	// Decrement reference count and return immediately if not zero:
	if (--m_cnRef != 0)
		return (m_cnRef);

	// If we make it here, then the reference count is zero.  We are 
	// therefore obliged to delete ourselves:
	delete this;

	// Return our refence count, which is zero now:
	return (0);
	}

// **************************************************************************
// QueryInterface ()
//
// Description:
//	This function is called to obtain a pointer to one of the COM interfaces
//	objects of this class support (in this case only IAdviseSink and its base
//	class IUnknown).  As is standard COM practice, our reference count is 
//	incremented upon a successful query.  
//
//  This is one of the 3 member functions all COM interfaces must implement.	
//
// Parameters:
//	REFIID		riid			Requested interface type: IID_IUnknown,
//								  or IID_IAdviseSink.
//	LPVOID		*ppInterface	Pointer to requested interface.
//
// Returns:
//	STDMETHODIMP -
//		S_OK - Query successful, ppInterface set to requested pointer.
//		E_INVALIDARG - One of the arguments was invalid.
//		E_NOINTERFACE - Requested interface is not supported.
// **************************************************************************
STDMETHODIMP IKShutdownSink::QueryInterface (REFIID iid, LPVOID *ppInterface)
	{
	// Validate ppInterface.  Return with "invalid argument" error code if invalid:
	if (ppInterface == NULL)
		return (E_INVALIDARG);

	// Standard COM practice requires that we invalidate output arguments
	// if an error is encountered.  Let's assume an error for now and invalidate
	// ppInterface.  We will reset it to a valid interface pointer later if we
	// determine requested ID is valid:
	*ppInterface = NULL;	

	// Reset ppInterface if requested interface type is valid:
	if (iid == IID_IUnknown)
		*ppInterface = (IUnknown *) this;
	else if (iid == IID_IOPCShutdown)
		*ppInterface = (IOPCShutdown *) this;
	else
		{
		// We have been asked for an interface we don't support.  Return 
		// immediately with "no interface" error code.  ppInterface should
		// still be NULL as required by COM.
		return (E_NOINTERFACE);
		}

	// If we made it here, then the query was successful and ppInterface
	// has been set to requested interface pointer.  Standard COM practice
	// requires us to increment our reference count now.
	AddRef ();

	// Return with "success" code:
	return (S_OK);
	}

// **************************************************************************
// ShutdownRequest ()
//
// Description:
//	This method is provided so that the OPC Server can request that we
//	remove all groups from the server and disconnect.
//
// Parameters:
//  LPCWSTR		lpwszReason		Pointer to string describing reason for
//								  shutdown request.  Could be NULL string.
//
// Returns:
//  STDMETHODIMP - S_OK
// **************************************************************************
STDMETHODIMP IKShutdownSink::ShutdownRequest (LPCWSTR lpwszReason)
	{
	// Pass request and reason to associated server object:
	return (S_OK);
	}