// **************************************************************************
// fixedsharedfile.h
//
// Description:
//	This is a wrapper for MFCs CSharedFile class that fixes a bug where 
//	the global memory handle is not unlocked on detach.
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


#ifndef _FIXEDSHAREDFILE_H
#define _FIXEDSHAREDFILE_H

#ifdef __AFXADV_H__


// **************************************************************************
class CFixedSharedFile : public CSharedFile
	{
	public:
		CFixedSharedFile (int nGrowBy = 128) : CSharedFile (GMEM_DDESHARE | GMEM_MOVEABLE, nGrowBy)
			{
			}

		BYTE* GetBuffer ()	// Enhancement (must be used with care)
			{
			ASSERT (m_lpBuffer);
			return (m_lpBuffer);
			}

		HGLOBAL Detach ()
			{
			ASSERT (m_hGlobalMemory != NULL);
			HGLOBAL hMem = m_hGlobalMemory;
			m_hGlobalMemory = NULL; // detach from global handle
			
			// This is the fix
			::GlobalUnlock (hMem);

			// re-initialize the CMemFile parts too
			m_lpBuffer = NULL;
			m_nBufferSize = 0;

			return hMem;
			}

		// Enhancement to allow data to be transfered to the clipboard
		BOOL CopyToClipboard (UINT uFmt)
			{
			// Open the clipboard
			if (!::OpenClipboard (NULL))
				{
				TRACE (_T("Shared Memory: Failed to open the clipboard\n"));
				return (false);
				}

			TRACE (_T("Copying %u bytes to the clipboard (uFmt == %u)\n"), GetLength (), uFmt);
			ASSERT (GetLength ());

			// Clear out current contents
			::EmptyClipboard ();

			// Stick the data in
			HANDLE hData = ::SetClipboardData (uFmt, Detach ());
			::CloseClipboard ();

			// Check for success
			if (!hData)
				{
				TRACE (_T("SetClipboardData () failed [OS Error == %u]\n"), GetLastError ());
				ASSERT (FALSE);
				}

			return (hData != NULL);
			}

	protected:

	};


#endif	// __AFXADV_H__
#endif	// _FIXEDSHAREDFILE_H
