

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue May 07 20:36:10 2019
 */
/* Compiler settings for iDCOMTestSrv.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __iDCOMTestSrv_i_h__
#define __iDCOMTestSrv_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IArithmeticLib_FWD_DEFINED__
#define __IArithmeticLib_FWD_DEFINED__
typedef interface IArithmeticLib IArithmeticLib;
#endif 	/* __IArithmeticLib_FWD_DEFINED__ */


#ifndef __ArithmeticLib_FWD_DEFINED__
#define __ArithmeticLib_FWD_DEFINED__

#ifdef __cplusplus
typedef class ArithmeticLib ArithmeticLib;
#else
typedef struct ArithmeticLib ArithmeticLib;
#endif /* __cplusplus */

#endif 	/* __ArithmeticLib_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IArithmeticLib_INTERFACE_DEFINED__
#define __IArithmeticLib_INTERFACE_DEFINED__

/* interface IArithmeticLib */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IArithmeticLib;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCF5334D-F9A7-43C0-BEDD-1AAD1C01838F")
    IArithmeticLib : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE add( 
            /* [in] */ int nNum1,
            /* [in] */ int nNum2,
            /* [out] */ int *pnResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE sub( 
            /* [in] */ int nNum1,
            /* [in] */ int nNum2,
            /* [out] */ int *pnResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IArithmeticLibVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IArithmeticLib * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IArithmeticLib * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IArithmeticLib * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IArithmeticLib * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IArithmeticLib * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IArithmeticLib * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IArithmeticLib * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *add )( 
            IArithmeticLib * This,
            /* [in] */ int nNum1,
            /* [in] */ int nNum2,
            /* [out] */ int *pnResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *sub )( 
            IArithmeticLib * This,
            /* [in] */ int nNum1,
            /* [in] */ int nNum2,
            /* [out] */ int *pnResult);
        
        END_INTERFACE
    } IArithmeticLibVtbl;

    interface IArithmeticLib
    {
        CONST_VTBL struct IArithmeticLibVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IArithmeticLib_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IArithmeticLib_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IArithmeticLib_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IArithmeticLib_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IArithmeticLib_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IArithmeticLib_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IArithmeticLib_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IArithmeticLib_add(This,nNum1,nNum2,pnResult)	\
    ( (This)->lpVtbl -> add(This,nNum1,nNum2,pnResult) ) 

#define IArithmeticLib_sub(This,nNum1,nNum2,pnResult)	\
    ( (This)->lpVtbl -> sub(This,nNum1,nNum2,pnResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IArithmeticLib_INTERFACE_DEFINED__ */



#ifndef __iDCOMTestSrvLib_LIBRARY_DEFINED__
#define __iDCOMTestSrvLib_LIBRARY_DEFINED__

/* library iDCOMTestSrvLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_iDCOMTestSrvLib;

EXTERN_C const CLSID CLSID_ArithmeticLib;

#ifdef __cplusplus

class DECLSPEC_UUID("26597882-6249-4DB7-AB7C-049EFC3A0F4D")
ArithmeticLib;
#endif
#endif /* __iDCOMTestSrvLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


