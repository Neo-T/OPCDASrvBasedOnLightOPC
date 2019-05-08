// **************************************************************************
// item.h
//
// Description:
//	Defines the CKItem class.
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


#ifndef _ITEM_H
#define _ITEM_H

class CKGroup;


// **************************************************************************
class CKItem : public CObject  
	{
	public:
		// construction/destruction
		CKItem (CKGroup *pParent);
		~CKItem ();

	public:
		// property accessor/manipulators
		void SetAccessPath (LPCTSTR strAccessPath) {m_strAccessPath = strAccessPath;}
		LPCTSTR GetAccessPath () {return (m_strAccessPath);}

		void SetActive (BOOL bActive) {m_bActive = bActive;}
		BOOL IsActive () {return (m_bActive);}

		void SetDataType (VARTYPE vtType) {m_vtDataType = vtType;}
		VARTYPE GetDataType () 
			{
			if (m_vtValue.vt != VT_EMPTY)
				return (m_vtValue.vt);

			return (m_vtDataType);
			}

		void SetItemID (LPCTSTR strItemID) {m_strItemID = strItemID;}
		LPCTSTR GetItemID () {return (m_strItemID);}

		void SetServerHandle (OPCHANDLE hServer) {m_hServer = hServer;}
		OPCHANDLE GetServerHandle () {return (m_hServer);}

		void SetAccessRights (DWORD dwAccess) {m_dwAccessRights = dwAccess;}
		DWORD GetAccessRights () {return (m_dwAccessRights);}

		void SetValid (BOOL bValid) 
			{
			m_bValid = bValid;

			if (!bValid)
				{
				m_wQuality = 0x1C;//OPC_QUALITY_BAD_OUT_OF_SERVICE;
				m_cdwUpdates = 0;
				m_bTimeStamped = FALSE;

				VariantInit (&m_vtValue);
				}
			}

		BOOL IsValid () {return (m_bValid);}

		// data
		void UpdateData (VARIANT &vtVal, WORD wQuality);
		void UpdateData (VARIANT &vtVal, WORD wQuality, FILETIME &ftTimeStamp);

		void GetValue (CString &strValue);
		LPCTSTR GetQuality ();
		void GetTimeStamp (CString &strTimeStamp);
		DWORD GetUpdateCount ();

		// This can be dangerous!!
		VARIANT* GetValue () {return (&m_vtValue);}

		// serialization
		virtual void Serialize (CArchive &ar);

		// cut/copy/paste
		void Copy (CFixedSharedFile &sf);
		void Paste (CFixedSharedFile &sf);

		// parent group access
		CKGroup* GetParentGroup () {return (m_pGroup);}

		// list management
		void SetPrev (CKItem *pPrev) {m_pPrev = pPrev;}
		CKItem* GetPrev () {return (m_pPrev);}

		void SetNext (CKItem *pNext) {m_pNext = pNext;}
		CKItem* GetNext () {return (m_pNext);}

		// GUI management
		void SetWParam (WPARAM wParam) {m_wParam = wParam;}
		WPARAM GetWParam () {return (m_wParam);}

	private:
		// properties
		CString m_strAccessPath;	// access path
		CString m_strItemID;		// fully qualified item ID
		BOOL m_bActive;				// active state
		VARTYPE m_vtDataType;		// server's canonical datatype
		DWORD m_dwAccessRights;		// access rights
		OPCHANDLE m_hServer;		// server handle for this item

		typedef struct _flags
			{
			DWORD Reserved					: 32;
			} FLAGS;

		FLAGS m_bfFlags;

		BOOL m_bValid;				// TRUE if successfully added to an OPC server
		BOOL m_bTimeStamped;		// TRUE if the last update included a timestamp

		// data
		FILETIME m_ftTimeStamp;		// timestamp attached to value
		WORD m_wQuality;			// quality attached to value
		VARIANT m_vtValue;			// current value

		DWORD m_cdwUpdates;

		// parent server
		CKGroup *m_pGroup;

		// list management
		CKItem *m_pPrev;
		CKItem *m_pNext;

		// threading
		CCriticalSection m_csDataLock;

		// GUI management
		WPARAM m_wParam;
	};


#endif // _ITEM_H
