// **************************************************************************
// datasink20.h
//
// Description:
//	Defines the IKDataSink20 class.
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


#ifndef _DATASINK20_H
#define _DATASINK20_H


// **************************************************************************
class IKDataSink20 : public IOPCDataCallback
	{
	public:
		IKDataSink20 ();
		~IKDataSink20 ();

		// IUnknown Methods
		STDMETHODIMP         QueryInterface (REFIID iid, LPVOID *ppInterface);
		STDMETHODIMP_(ULONG) AddRef ();
		STDMETHODIMP_(ULONG) Release ();

		// IOPCDataCallback Methods 
		STDMETHODIMP OnDataChange (		// OnDataChange notifications
			DWORD dwTransID,			// 0 for normal OnDataChange events, non-zero for Refreshes
			OPCHANDLE hGroup,			// client group handle
			HRESULT hrMasterQuality,	// S_OK if all qualities are GOOD, otherwise S_FALSE
			HRESULT hrMasterError,		// S_OK if all errors are S_OK, otherwise S_FALSE
			DWORD dwCount,				// number of items in the lists that follow
			OPCHANDLE *phClientItems,	// item client handles
			VARIANT *pvValues,			// item data
			WORD *pwQualities,			// item qualities
			FILETIME *pftTimeStamps,	// item timestamps
			HRESULT *pErrors);			// item errors	

		STDMETHODIMP OnReadComplete (	// OnReadComplete notifications
			DWORD dwTransID,			// Transaction ID returned by the server when the read was initiated
			OPCHANDLE hGroup,			// client group handle
			HRESULT hrMasterQuality,	// S_OK if all qualities are GOOD, otherwise S_FALSE
			HRESULT hrMasterError,		// S_OK if all errors are S_OK, otherwise S_FALSE
			DWORD dwCount,				// number of items in the lists that follow
			OPCHANDLE *phClientItems,	// item client handles
			VARIANT *pvValues,			// item data
			WORD *pwQualities,			// item qualities
			FILETIME *pftTimeStamps,	// item timestamps
			HRESULT *pErrors);			// item errors	

		STDMETHODIMP OnWriteComplete (	// OnWriteComplete notifications
			DWORD dwTransID,			// Transaction ID returned by the server when the write was initiated
			OPCHANDLE hGroup,			// client group handle
			HRESULT hrMasterError,		// S_OK if all errors are S_OK, otherwise S_FALSE
			DWORD dwCount,				// number of items in the lists that follow
			OPCHANDLE *phClientItems,	// item client handles
			HRESULT *pErrors);			// item errors	

		STDMETHODIMP OnCancelComplete (	// OnCancelComplete notifications
			DWORD dwTransID,			// Transaction ID provided by the client when the read/write/refresh was initiated
			OPCHANDLE hGroup);

	private:
		DWORD m_cnRef;
	};


#endif // _DATASINK20_H
