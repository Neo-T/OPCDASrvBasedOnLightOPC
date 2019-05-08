

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue May 07 17:22:43 2019
 */
/* Compiler settings for ..\opc\opcda.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "opcda_h.h"

#define TYPE_FORMAT_STRING_SIZE   2161                              
#define PROC_FORMAT_STRING_SIZE   3597                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _opcda_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } opcda_MIDL_TYPE_FORMAT_STRING;

typedef struct _opcda_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } opcda_MIDL_PROC_FORMAT_STRING;

typedef struct _opcda_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } opcda_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const opcda_MIDL_TYPE_FORMAT_STRING opcda__MIDL_TypeFormatString;
extern const opcda_MIDL_PROC_FORMAT_STRING opcda__MIDL_ProcFormatString;
extern const opcda_MIDL_EXPR_FORMAT_STRING opcda__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO CATID_OPCDAServer10_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO CATID_OPCDAServer10_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO CATID_OPCDAServer20_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO CATID_OPCDAServer20_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO CATID_OPCDAServer30_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO CATID_OPCDAServer30_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO CATID_XMLDAServer10_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO CATID_XMLDAServer10_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCServerPublicGroups_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCServerPublicGroups_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCBrowseServerAddressSpace_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCBrowseServerAddressSpace_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCGroupStateMgt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCGroupStateMgt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCPublicGroupStateMgt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCPublicGroupStateMgt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCSyncIO_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCSyncIO_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCAsyncIO_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCAsyncIO_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCItemMgt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCItemMgt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumOPCItemAttributes_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumOPCItemAttributes_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCDataCallback_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCDataCallback_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCAsyncIO2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCAsyncIO2_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCItemProperties_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCItemProperties_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCItemDeadbandMgt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCItemDeadbandMgt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCItemSamplingMgt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCItemSamplingMgt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCBrowse_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCBrowse_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCItemIO_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCItemIO_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCSyncIO2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCSyncIO2_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCAsyncIO3_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCAsyncIO3_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOPCGroupStateMgt2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOPCGroupStateMgt2_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const opcda_MIDL_PROC_FORMAT_STRING opcda__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure AddGroup */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x68 ),	/* X64 Stack size/offset = 104 */
/* 10 */	NdrFcShort( 0x9c ),	/* 156 */
/* 12 */	NdrFcShort( 0x40 ),	/* 64 */
/* 14 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xc,		/* 12 */
/* 16 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 18 */	NdrFcShort( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 26 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 28 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter bActive */

/* 32 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwRequestedUpdateRate */

/* 38 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 40 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hClientGroup */

/* 44 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 46 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 48 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTimeBias */

/* 50 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 52 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 54 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pPercentDeadband */

/* 56 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 58 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 60 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter dwLCID */

/* 62 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 64 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 66 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServerGroup */

/* 68 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 70 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 72 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRevisedUpdateRate */

/* 74 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 76 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 78 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 80 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 82 */	NdrFcShort( 0x50 ),	/* X64 Stack size/offset = 80 */
/* 84 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppUnk */

/* 86 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 88 */	NdrFcShort( 0x58 ),	/* X64 Stack size/offset = 88 */
/* 90 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 92 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 94 */	NdrFcShort( 0x60 ),	/* X64 Stack size/offset = 96 */
/* 96 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetErrorString */

/* 98 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x4 ),	/* 4 */
/* 106 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 108 */	NdrFcShort( 0x10 ),	/* 16 */
/* 110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 112 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 114 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwError */

/* 124 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 126 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwLocale */

/* 130 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 132 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppString */

/* 136 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 138 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 140 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 144 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGroupByName */

/* 148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x5 ),	/* 5 */
/* 156 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 158 */	NdrFcShort( 0x44 ),	/* 68 */
/* 160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 162 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 164 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 166 */	NdrFcShort( 0x1 ),	/* 1 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 174 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 176 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 178 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter riid */

/* 180 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 182 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 184 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppUnk */

/* 186 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 188 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 190 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 194 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStatus */

/* 198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x6 ),	/* 6 */
/* 206 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 212 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 214 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppServerStatus */

/* 224 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 226 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 228 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Return value */

/* 230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 232 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveGroup */

/* 236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x7 ),	/* 7 */
/* 244 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 246 */	NdrFcShort( 0x10 ),	/* 16 */
/* 248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 250 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 252 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hServerGroup */

/* 262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 264 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bForce */

/* 268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 270 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 276 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateGroupEnumerator */

/* 280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 288 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 290 */	NdrFcShort( 0x4a ),	/* 74 */
/* 292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 294 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 296 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 298 */	NdrFcShort( 0x1 ),	/* 1 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwScope */

/* 306 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 308 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 310 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter riid */

/* 312 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 314 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 316 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppUnk */

/* 318 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 320 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 322 */	NdrFcShort( 0x7a ),	/* Type Offset=122 */

	/* Return value */

/* 324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 326 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPublicGroupByName */

/* 330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x3 ),	/* 3 */
/* 338 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 340 */	NdrFcShort( 0x44 ),	/* 68 */
/* 342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 344 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 346 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 348 */	NdrFcShort( 0x1 ),	/* 1 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 356 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 358 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 360 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter riid */

/* 362 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 364 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 366 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppUnk */

/* 368 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 370 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 372 */	NdrFcShort( 0x86 ),	/* Type Offset=134 */

	/* Return value */

/* 374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 376 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemovePublicGroup */

/* 380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x4 ),	/* 4 */
/* 388 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 390 */	NdrFcShort( 0x10 ),	/* 16 */
/* 392 */	NdrFcShort( 0x8 ),	/* 8 */
/* 394 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 396 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hServerGroup */

/* 406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 408 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bForce */

/* 412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 414 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 420 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryOrganization */

/* 424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x3 ),	/* 3 */
/* 432 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x22 ),	/* 34 */
/* 438 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 440 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNameSpaceType */

/* 450 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 452 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 454 */	NdrFcShort( 0x92 ),	/* Type Offset=146 */

	/* Return value */

/* 456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 458 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeBrowsePosition */

/* 462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x4 ),	/* 4 */
/* 470 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 472 */	NdrFcShort( 0x6 ),	/* 6 */
/* 474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 476 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 478 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwBrowseDirection */

/* 488 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 490 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 492 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter szString */

/* 494 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 496 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 498 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 502 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BrowseOPCItemIDs */

/* 506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x5 ),	/* 5 */
/* 514 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 516 */	NdrFcShort( 0x14 ),	/* 20 */
/* 518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 520 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwBrowseFilterType */

/* 532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 534 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 536 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter szFilterCriteria */

/* 538 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 540 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 542 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter vtDataTypeFilter */

/* 544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 546 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 548 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter dwAccessRightsFilter */

/* 550 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 552 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIEnumString */

/* 556 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 558 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 560 */	NdrFcShort( 0x96 ),	/* Type Offset=150 */

	/* Return value */

/* 562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 564 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetItemID */

/* 568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x6 ),	/* 6 */
/* 576 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 582 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 584 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szItemDataID */

/* 594 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 596 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 598 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter szItemID */

/* 600 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 602 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 604 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 608 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BrowseAccessPaths */

/* 612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x7 ),	/* 7 */
/* 620 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 628 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szItemID */

/* 638 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 640 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 642 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter ppIEnumString */

/* 644 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 646 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 648 */	NdrFcShort( 0x96 ),	/* Type Offset=150 */

	/* Return value */

/* 650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 652 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 656 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x3 ),	/* 3 */
/* 664 */	NdrFcShort( 0x50 ),	/* X64 Stack size/offset = 80 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0xcc ),	/* 204 */
/* 670 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x9,		/* 9 */
/* 672 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUpdateRate */

/* 682 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 684 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pActive */

/* 688 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 690 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppName */

/* 694 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 696 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 698 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter pTimeBias */

/* 700 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 702 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPercentDeadband */

/* 706 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 708 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 710 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter pLCID */

/* 712 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 714 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phClientGroup */

/* 718 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 720 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServerGroup */

/* 724 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 726 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 732 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetState */

/* 736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x4 ),	/* 4 */
/* 744 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 746 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 748 */	NdrFcShort( 0x24 ),	/* 36 */
/* 750 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x8,		/* 8 */
/* 752 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRequestedUpdateRate */

/* 762 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 764 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 766 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pRevisedUpdateRate */

/* 768 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 770 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pActive */

/* 774 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 776 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 778 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pTimeBias */

/* 780 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 782 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 784 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pPercentDeadband */

/* 786 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 788 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 790 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter pLCID */

/* 792 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 794 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 796 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter phClientGroup */

/* 798 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 800 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 802 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 806 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x5 ),	/* 5 */
/* 818 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 824 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 826 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 836 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 838 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 840 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 844 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloneGroup */

/* 848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0x6 ),	/* 6 */
/* 856 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 858 */	NdrFcShort( 0x44 ),	/* 68 */
/* 860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 862 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 864 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 866 */	NdrFcShort( 0x1 ),	/* 1 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 874 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 876 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 878 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter riid */

/* 880 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 882 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 884 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppUnk */

/* 886 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 888 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 890 */	NdrFcShort( 0xb0 ),	/* Type Offset=176 */

	/* Return value */

/* 892 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 894 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 898 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x3 ),	/* 3 */
/* 906 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x24 ),	/* 36 */
/* 912 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 914 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPublic */

/* 924 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 926 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 932 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveToPublic */

/* 936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x4 ),	/* 4 */
/* 944 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 950 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 952 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 964 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Read */

/* 968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x3 ),	/* 3 */
/* 976 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 978 */	NdrFcShort( 0xe ),	/* 14 */
/* 980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 982 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 984 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 986 */	NdrFcShort( 0x1 ),	/* 1 */
/* 988 */	NdrFcShort( 0x1 ),	/* 1 */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwSource */

/* 994 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 996 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 998 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter dwCount */

/* 1000 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1002 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 1006 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1008 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1010 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Parameter ppItemValues */

/* 1012 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1014 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1016 */	NdrFcShort( 0xcc ),	/* Type Offset=204 */

	/* Parameter ppErrors */

/* 1018 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1020 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1022 */	NdrFcShort( 0x4ba ),	/* Type Offset=1210 */

	/* Return value */

/* 1024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1026 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 1030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1038 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1046 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1048 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1050 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 1056 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1058 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 1062 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1064 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1066 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pItemValues */

/* 1068 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1070 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1072 */	NdrFcShort( 0x4e4 ),	/* Type Offset=1252 */

	/* Parameter ppErrors */

/* 1074 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1076 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1078 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 1080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1082 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Read */

/* 1086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1094 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 1096 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1098 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1100 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1102 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1104 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1106 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwConnection */

/* 1112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1114 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwSource */

/* 1118 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1120 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1122 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter dwCount */

/* 1124 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1126 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 1130 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1132 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1134 */	NdrFcShort( 0x506 ),	/* Type Offset=1286 */

	/* Parameter pTransactionID */

/* 1136 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1138 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppErrors */

/* 1142 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1144 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1146 */	NdrFcShort( 0x512 ),	/* Type Offset=1298 */

	/* Return value */

/* 1148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1150 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 1152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 1154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1162 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 1164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1166 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1168 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1170 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1172 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1174 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwConnection */

/* 1180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1182 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwCount */

/* 1186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1188 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 1192 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1194 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1196 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Parameter pItemValues */

/* 1198 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1200 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1202 */	NdrFcShort( 0x51e ),	/* Type Offset=1310 */

	/* Parameter pTransactionID */

/* 1204 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1206 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppErrors */

/* 1210 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1212 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1214 */	NdrFcShort( 0x4ba ),	/* Type Offset=1210 */

	/* Return value */

/* 1216 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1218 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 1220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Refresh */

/* 1222 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1224 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1230 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1232 */	NdrFcShort( 0xe ),	/* 14 */
/* 1234 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1236 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1238 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwConnection */

/* 1248 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1250 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwSource */

/* 1254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1256 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1258 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pTransactionID */

/* 1260 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1262 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1268 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel2 */


	/* Procedure Cancel */

/* 1272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1278 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1280 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1286 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1288 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCancelID */


	/* Parameter dwTransactionID */

/* 1298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1300 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1306 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddItems */

/* 1310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1316 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1318 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1324 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1326 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1330 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 1336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1338 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pItemArray */

/* 1342 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1344 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1346 */	NdrFcShort( 0x564 ),	/* Type Offset=1380 */

	/* Parameter ppAddResults */

/* 1348 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1350 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1352 */	NdrFcShort( 0x57a ),	/* Type Offset=1402 */

	/* Parameter ppErrors */

/* 1354 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1356 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1358 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 1360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1362 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ValidateItems */

/* 1366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1374 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 1376 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1380 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1382 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1384 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1386 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 1392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1394 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pItemArray */

/* 1398 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1400 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1402 */	NdrFcShort( 0x564 ),	/* Type Offset=1380 */

	/* Parameter bBlobUpdate */

/* 1404 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1406 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppValidationResults */

/* 1410 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1412 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1414 */	NdrFcShort( 0x57a ),	/* Type Offset=1402 */

	/* Parameter ppErrors */

/* 1416 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1418 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1420 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 1422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1424 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearItemSamplingRate */


	/* Procedure ClearItemDeadband */


	/* Procedure RemoveItems */

/* 1428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1436 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1442 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1444 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1446 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1448 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */


	/* Parameter dwCount */


	/* Parameter dwCount */

/* 1454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1456 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */


	/* Parameter phServer */


	/* Parameter phServer */

/* 1460 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1462 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1464 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppErrors */


	/* Parameter ppErrors */


	/* Parameter ppErrors */

/* 1466 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1468 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1470 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1474 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetActiveState */

/* 1478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1484 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1486 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1488 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1492 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1494 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1496 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1498 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 1504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1506 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 1510 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1512 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1514 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter bActive */

/* 1516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1518 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppErrors */

/* 1522 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1524 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1526 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 1528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1530 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetClientHandles */

/* 1534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1542 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1548 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1550 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1552 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1554 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 1560 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1562 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 1566 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1568 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1570 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter phClient */

/* 1572 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1574 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1576 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppErrors */

/* 1578 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1580 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1582 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1586 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDatatypes */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1598 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1604 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1606 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1608 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1610 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 1616 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1618 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 1622 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1624 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1626 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pRequestedDatatypes */

/* 1628 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1630 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1632 */	NdrFcShort( 0x5bc ),	/* Type Offset=1468 */

	/* Parameter ppErrors */

/* 1634 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1636 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1638 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 1640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1642 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateEnumerator */

/* 1646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1654 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1656 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1660 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1662 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1664 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 1672 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1674 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1676 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppUnk */

/* 1678 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1680 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1682 */	NdrFcShort( 0x5c8 ),	/* Type Offset=1480 */

	/* Return value */

/* 1684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1686 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 1690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1696 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1698 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1702 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1704 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1706 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1708 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 1716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1718 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppItemArray */

/* 1722 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1724 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1726 */	NdrFcShort( 0x5d4 ),	/* Type Offset=1492 */

	/* Parameter pceltFetched */

/* 1728 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1730 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1748 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1756 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 1766 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1768 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1774 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 1778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1784 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1786 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1792 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1794 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1806 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1816 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1818 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1824 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1826 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnumItemAttributes */

/* 1836 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1838 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1840 */	NdrFcShort( 0x624 ),	/* Type Offset=1572 */

	/* Return value */

/* 1842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1844 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnDataChange */

/* 1848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1856 */	NdrFcShort( 0x60 ),	/* X64 Stack size/offset = 96 */
/* 1858 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1862 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 1864 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwTransid */

/* 1874 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1876 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hGroup */

/* 1880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1882 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hrMasterquality */

/* 1886 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1888 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hrMastererror */

/* 1892 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1894 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwCount */

/* 1898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1900 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phClientItems */

/* 1904 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1906 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1908 */	NdrFcShort( 0x63e ),	/* Type Offset=1598 */

	/* Parameter pvValues */

/* 1910 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1912 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 1914 */	NdrFcShort( 0x64e ),	/* Type Offset=1614 */

	/* Parameter pwQualities */

/* 1916 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1918 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 1920 */	NdrFcShort( 0x668 ),	/* Type Offset=1640 */

	/* Parameter pftTimeStamps */

/* 1922 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1924 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 1926 */	NdrFcShort( 0x678 ),	/* Type Offset=1656 */

	/* Parameter pErrors */

/* 1928 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1930 */	NdrFcShort( 0x50 ),	/* X64 Stack size/offset = 80 */
/* 1932 */	NdrFcShort( 0x63e ),	/* Type Offset=1598 */

	/* Return value */

/* 1934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1936 */	NdrFcShort( 0x58 ),	/* X64 Stack size/offset = 88 */
/* 1938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnReadComplete */

/* 1940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1948 */	NdrFcShort( 0x60 ),	/* X64 Stack size/offset = 96 */
/* 1950 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1954 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 1956 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwTransid */

/* 1966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1968 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hGroup */

/* 1972 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1974 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hrMasterquality */

/* 1978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1980 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hrMastererror */

/* 1984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1986 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwCount */

/* 1990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1992 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phClientItems */

/* 1996 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1998 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2000 */	NdrFcShort( 0x63e ),	/* Type Offset=1598 */

	/* Parameter pvValues */

/* 2002 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2004 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2006 */	NdrFcShort( 0x64e ),	/* Type Offset=1614 */

	/* Parameter pwQualities */

/* 2008 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2010 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 2012 */	NdrFcShort( 0x668 ),	/* Type Offset=1640 */

	/* Parameter pftTimeStamps */

/* 2014 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2016 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 2018 */	NdrFcShort( 0x678 ),	/* Type Offset=1656 */

	/* Parameter pErrors */

/* 2020 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2022 */	NdrFcShort( 0x50 ),	/* X64 Stack size/offset = 80 */
/* 2024 */	NdrFcShort( 0x63e ),	/* Type Offset=1598 */

	/* Return value */

/* 2026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2028 */	NdrFcShort( 0x58 ),	/* X64 Stack size/offset = 88 */
/* 2030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnWriteComplete */

/* 2032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2038 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2040 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 2042 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2046 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2048 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwTransid */

/* 2058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2060 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hGroup */

/* 2064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2066 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hrMastererr */

/* 2070 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2072 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwCount */

/* 2076 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2078 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pClienthandles */

/* 2082 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2084 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2086 */	NdrFcShort( 0x692 ),	/* Type Offset=1682 */

	/* Parameter pErrors */

/* 2088 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2090 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2092 */	NdrFcShort( 0x692 ),	/* Type Offset=1682 */

	/* Return value */

/* 2094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2096 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnCancelComplete */

/* 2100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2106 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2108 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2110 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2112 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2114 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2116 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwTransid */

/* 2126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2128 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hGroup */

/* 2132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2134 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2140 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Read */

/* 2144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2152 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2154 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2156 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2158 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2160 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2162 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2164 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2172 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2176 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2178 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2180 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter dwTransactionID */

/* 2182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2184 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwCancelID */

/* 2188 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2190 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppErrors */

/* 2194 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2196 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2198 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2202 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 2206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2214 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 2216 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2218 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2220 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2222 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2224 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2226 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2234 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2238 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2240 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2242 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pItemValues */

/* 2244 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2246 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2248 */	NdrFcShort( 0x4e4 ),	/* Type Offset=1252 */

	/* Parameter dwTransactionID */

/* 2250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2252 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwCancelID */

/* 2256 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2258 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppErrors */

/* 2262 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2264 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2266 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2270 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Refresh2 */

/* 2274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2280 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2282 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2284 */	NdrFcShort( 0xe ),	/* 14 */
/* 2286 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2288 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2290 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwSource */

/* 2300 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2302 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2304 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter dwTransactionID */

/* 2306 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2308 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwCancelID */

/* 2312 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2314 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2320 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEnable */

/* 2324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2330 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2332 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2340 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bEnable */

/* 2350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2352 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2358 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetKeepAlive */


	/* Procedure GetEnable */

/* 2362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2370 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2374 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2378 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdwKeepAliveTime */


	/* Parameter pbEnable */

/* 2388 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2390 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2396 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryAvailableProperties */

/* 2400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2408 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2412 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2414 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2416 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2418 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szItemID */

/* 2426 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2428 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2430 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pdwCount */

/* 2432 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2434 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppPropertyIDs */

/* 2438 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2440 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2442 */	NdrFcShort( 0x69e ),	/* Type Offset=1694 */

	/* Parameter ppDescriptions */

/* 2444 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2446 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2448 */	NdrFcShort( 0x6b2 ),	/* Type Offset=1714 */

	/* Parameter ppvtDataTypes */

/* 2450 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2452 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2454 */	NdrFcShort( 0x6d0 ),	/* Type Offset=1744 */

	/* Return value */

/* 2456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2458 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetItemProperties */

/* 2462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2468 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2470 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2472 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2476 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2478 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2480 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2482 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szItemID */

/* 2488 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2490 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2492 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter dwCount */

/* 2494 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2496 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwPropertyIDs */

/* 2500 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2502 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2504 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Parameter ppvData */

/* 2506 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2508 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2510 */	NdrFcShort( 0x6e4 ),	/* Type Offset=1764 */

	/* Parameter ppErrors */

/* 2512 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2514 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2516 */	NdrFcShort( 0x4ba ),	/* Type Offset=1210 */

	/* Return value */

/* 2518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2520 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LookupItemIDs */

/* 2524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2530 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2532 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2538 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2540 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2542 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2544 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szItemID */

/* 2550 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2552 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2554 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter dwCount */

/* 2556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2558 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwPropertyIDs */

/* 2562 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2564 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2566 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Parameter ppszNewItemIDs */

/* 2568 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2570 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2572 */	NdrFcShort( 0x702 ),	/* Type Offset=1794 */

	/* Parameter ppErrors */

/* 2574 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2576 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2578 */	NdrFcShort( 0x4ba ),	/* Type Offset=1210 */

	/* Return value */

/* 2580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2582 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetItemDeadband */

/* 2586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2592 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2594 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2600 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2602 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2606 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2614 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2618 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2620 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2622 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pPercentDeadband */

/* 2624 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2626 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2628 */	NdrFcShort( 0x724 ),	/* Type Offset=1828 */

	/* Parameter ppErrors */

/* 2630 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2632 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2634 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2638 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetItemDeadband */

/* 2642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2650 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2656 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2658 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2660 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2662 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2666 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2670 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2674 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2676 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2678 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppPercentDeadband */

/* 2680 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2682 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2684 */	NdrFcShort( 0x730 ),	/* Type Offset=1840 */

	/* Parameter ppErrors */

/* 2686 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2688 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2690 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2694 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetItemSamplingRate */

/* 2698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2704 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2706 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2712 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2714 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2716 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2718 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2724 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2726 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2730 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2732 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2734 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pdwRequestedSamplingRate */

/* 2736 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2738 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2740 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppdwRevisedSamplingRate */

/* 2742 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2744 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2746 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Parameter ppErrors */

/* 2748 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2750 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2752 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2756 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetItemSamplingRate */

/* 2760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2766 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2768 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2774 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2776 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2778 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2780 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2788 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2792 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2794 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2796 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppdwSamplingRate */

/* 2798 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2800 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2802 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Parameter ppErrors */

/* 2804 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2806 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2808 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2812 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetItemBufferEnable */

/* 2816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2824 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2830 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2832 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2834 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2836 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2842 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2844 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2848 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2850 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2852 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pbEnable */

/* 2854 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2856 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2858 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppErrors */

/* 2860 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2862 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2864 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2866 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2868 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetItemBufferEnable */

/* 2872 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2874 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2878 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2880 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2886 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2888 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2890 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2892 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 2898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2900 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 2904 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2906 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2908 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppbEnable */

/* 2910 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2912 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2914 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Parameter ppErrors */

/* 2916 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2918 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2920 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 2922 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2924 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetProperties */

/* 2928 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2934 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2936 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 2938 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2942 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2944 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2946 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2948 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwItemCount */

/* 2954 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2956 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pszItemIDs */

/* 2960 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2962 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2964 */	NdrFcShort( 0x73c ),	/* Type Offset=1852 */

	/* Parameter bReturnPropertyValues */

/* 2966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2968 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwPropertyCount */

/* 2972 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2974 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwPropertyIDs */

/* 2978 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2980 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 2982 */	NdrFcShort( 0x692 ),	/* Type Offset=1682 */

	/* Parameter ppItemProperties */

/* 2984 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2986 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 2988 */	NdrFcShort( 0x752 ),	/* Type Offset=1874 */

	/* Return value */

/* 2990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2992 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 2994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Browse */

/* 2996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3002 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3004 */	NdrFcShort( 0x78 ),	/* X64 Stack size/offset = 120 */
/* 3006 */	NdrFcShort( 0x26 ),	/* 38 */
/* 3008 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3010 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xe,		/* 14 */
/* 3012 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3016 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szItemID */

/* 3022 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3024 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3026 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pszContinuationPoint */

/* 3028 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3030 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3032 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter dwMaxElementsReturned */

/* 3034 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3036 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwBrowseFilter */

/* 3040 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3042 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3044 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter szElementNameFilter */

/* 3046 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3048 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3050 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter szVendorFilter */

/* 3052 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3054 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3056 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter bReturnAllProperties */

/* 3058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3060 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 3062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bReturnPropertyValues */

/* 3064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3066 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 3068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwPropertyCount */

/* 3070 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3072 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 3074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwPropertyIDs */

/* 3076 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3078 */	NdrFcShort( 0x50 ),	/* X64 Stack size/offset = 80 */
/* 3080 */	NdrFcShort( 0x7b8 ),	/* Type Offset=1976 */

	/* Parameter pbMoreElements */

/* 3082 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3084 */	NdrFcShort( 0x58 ),	/* X64 Stack size/offset = 88 */
/* 3086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwCount */

/* 3088 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3090 */	NdrFcShort( 0x60 ),	/* X64 Stack size/offset = 96 */
/* 3092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppBrowseElements */

/* 3094 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3096 */	NdrFcShort( 0x68 ),	/* X64 Stack size/offset = 104 */
/* 3098 */	NdrFcShort( 0x7c4 ),	/* Type Offset=1988 */

	/* Return value */

/* 3100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3102 */	NdrFcShort( 0x70 ),	/* X64 Stack size/offset = 112 */
/* 3104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Read */

/* 3106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3112 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3114 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 3116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3120 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3122 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3124 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3126 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 3132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3134 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pszItemIDs */

/* 3138 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3140 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3142 */	NdrFcShort( 0x73c ),	/* Type Offset=1852 */

	/* Parameter pdwMaxAge */

/* 3144 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3146 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3148 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppvValues */

/* 3150 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3152 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3154 */	NdrFcShort( 0x7fc ),	/* Type Offset=2044 */

	/* Parameter ppwQualities */

/* 3156 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3158 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3160 */	NdrFcShort( 0x81a ),	/* Type Offset=2074 */

	/* Parameter ppftTimeStamps */

/* 3162 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3164 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3166 */	NdrFcShort( 0x822 ),	/* Type Offset=2082 */

	/* Parameter ppErrors */

/* 3168 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3170 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 3172 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 3174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3176 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 3178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteVQT */

/* 3180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3186 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3188 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3194 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3196 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3198 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3200 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 3206 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3208 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pszItemIDs */

/* 3212 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3214 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3216 */	NdrFcShort( 0x73c ),	/* Type Offset=1852 */

	/* Parameter pItemVQT */

/* 3218 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3220 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3222 */	NdrFcShort( 0x85a ),	/* Type Offset=2138 */

	/* Parameter ppErrors */

/* 3224 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3226 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3228 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 3230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3232 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadMaxAge */

/* 3236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3242 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3244 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 3246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3250 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3252 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3256 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 3262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3264 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 3268 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3270 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3272 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pdwMaxAge */

/* 3274 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3276 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3278 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter ppvValues */

/* 3280 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3282 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3284 */	NdrFcShort( 0x7fc ),	/* Type Offset=2044 */

	/* Parameter ppwQualities */

/* 3286 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3288 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3290 */	NdrFcShort( 0x81a ),	/* Type Offset=2074 */

	/* Parameter ppftTimeStamps */

/* 3292 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3294 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3296 */	NdrFcShort( 0x822 ),	/* Type Offset=2082 */

	/* Parameter ppErrors */

/* 3298 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3300 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 3302 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 3304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3306 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 3308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteVQT */

/* 3310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3316 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3318 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3324 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3326 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3330 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 3336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3338 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 3342 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3344 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3346 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pItemVQT */

/* 3348 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3350 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3352 */	NdrFcShort( 0x85a ),	/* Type Offset=2138 */

	/* Parameter ppErrors */

/* 3354 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3356 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3358 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 3360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3362 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadMaxAge */

/* 3366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3374 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 3376 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3378 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3380 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3382 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3384 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3386 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 3392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3394 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 3398 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3400 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3402 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pdwMaxAge */

/* 3404 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3406 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3408 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter dwTransactionID */

/* 3410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3412 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwCancelID */

/* 3416 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3418 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppErrors */

/* 3422 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3424 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3426 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 3428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3430 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 3432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteVQT */

/* 3434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3440 */	NdrFcShort( 0xa ),	/* 10 */
/* 3442 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 3444 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3446 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3448 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3450 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3452 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3454 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwCount */

/* 3460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3462 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phServer */

/* 3466 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3468 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3470 */	NdrFcShort( 0x4c6 ),	/* Type Offset=1222 */

	/* Parameter pItemVQT */

/* 3472 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3474 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3476 */	NdrFcShort( 0x85a ),	/* Type Offset=2138 */

	/* Parameter dwTransactionID */

/* 3478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3480 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwCancelID */

/* 3484 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3486 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppErrors */

/* 3490 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3492 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3494 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 3496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3498 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 3500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RefreshMaxAge */

/* 3502 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3508 */	NdrFcShort( 0xb ),	/* 11 */
/* 3510 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3512 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3514 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3516 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 3518 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwMaxAge */

/* 3528 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3530 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwTransactionID */

/* 3534 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3536 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwCancelID */

/* 3540 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3542 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3548 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetKeepAlive */

/* 3552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3558 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3560 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3564 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3566 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3568 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwKeepAliveTime */

/* 3578 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3580 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwRevisedKeepAliveTime */

/* 3584 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3586 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3592 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const opcda_MIDL_TYPE_FORMAT_STRING opcda__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/*  8 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 12 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 16 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 18 */	
			0x11, 0x0,	/* FC_RP */
/* 20 */	NdrFcShort( 0x8 ),	/* Offset= 8 (28) */
/* 22 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 24 */	NdrFcShort( 0x8 ),	/* 8 */
/* 26 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 28 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 30 */	NdrFcShort( 0x10 ),	/* 16 */
/* 32 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 34 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 36 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (22) */
			0x5b,		/* FC_END */
/* 40 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 42 */	NdrFcShort( 0x2 ),	/* Offset= 2 (44) */
/* 44 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 46 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 48 */	NdrFcShort( 0x50 ),	/* X64 Stack size/offset = 80 */
/* 50 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 52 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 54 */	NdrFcShort( 0x2 ),	/* Offset= 2 (56) */
/* 56 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 58 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 60 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 62 */	NdrFcShort( 0x2 ),	/* Offset= 2 (64) */
/* 64 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 66 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 68 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 70 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 72 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 74 */	NdrFcShort( 0x2 ),	/* Offset= 2 (76) */
/* 76 */	
			0x13, 0x0,	/* FC_OP */
/* 78 */	NdrFcShort( 0xa ),	/* Offset= 10 (88) */
/* 80 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 82 */	NdrFcShort( 0x8 ),	/* 8 */
/* 84 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 86 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 88 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 90 */	NdrFcShort( 0x38 ),	/* 56 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x18 ),	/* Offset= 24 (118) */
/* 96 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 98 */	NdrFcShort( 0xffee ),	/* Offset= -18 (80) */
/* 100 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 102 */	NdrFcShort( 0xffea ),	/* Offset= -22 (80) */
/* 104 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 106 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (80) */
/* 108 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 110 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 112 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 114 */	0x6,		/* FC_SHORT */
			0x40,		/* FC_STRUCTPAD4 */
/* 116 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 118 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 120 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 122 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 124 */	NdrFcShort( 0x2 ),	/* Offset= 2 (126) */
/* 126 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 128 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 130 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 132 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 134 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 136 */	NdrFcShort( 0x2 ),	/* Offset= 2 (138) */
/* 138 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 140 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 142 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 144 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 146 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 148 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 150 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 152 */	NdrFcShort( 0x2 ),	/* Offset= 2 (154) */
/* 154 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 156 */	NdrFcLong( 0x101 ),	/* 257 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 166 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 168 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 170 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 172 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 174 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 176 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 178 */	NdrFcShort( 0x2 ),	/* Offset= 2 (180) */
/* 180 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 182 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 184 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 186 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 188 */	
			0x11, 0x0,	/* FC_RP */
/* 190 */	NdrFcShort( 0x2 ),	/* Offset= 2 (192) */
/* 192 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 194 */	NdrFcShort( 0x4 ),	/* 4 */
/* 196 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 198 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 200 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 202 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 204 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 206 */	NdrFcShort( 0x2 ),	/* Offset= 2 (208) */
/* 208 */	
			0x13, 0x0,	/* FC_OP */
/* 210 */	NdrFcShort( 0x3d2 ),	/* Offset= 978 (1188) */
/* 212 */	
			0x13, 0x0,	/* FC_OP */
/* 214 */	NdrFcShort( 0x39c ),	/* Offset= 924 (1138) */
/* 216 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 218 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 220 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 222 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 224 */	NdrFcShort( 0x2 ),	/* Offset= 2 (226) */
/* 226 */	NdrFcShort( 0x10 ),	/* 16 */
/* 228 */	NdrFcShort( 0x2f ),	/* 47 */
/* 230 */	NdrFcLong( 0x14 ),	/* 20 */
/* 234 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 236 */	NdrFcLong( 0x3 ),	/* 3 */
/* 240 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 242 */	NdrFcLong( 0x11 ),	/* 17 */
/* 246 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 248 */	NdrFcLong( 0x2 ),	/* 2 */
/* 252 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 254 */	NdrFcLong( 0x4 ),	/* 4 */
/* 258 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 260 */	NdrFcLong( 0x5 ),	/* 5 */
/* 264 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 266 */	NdrFcLong( 0xb ),	/* 11 */
/* 270 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 272 */	NdrFcLong( 0xa ),	/* 10 */
/* 276 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 278 */	NdrFcLong( 0x6 ),	/* 6 */
/* 282 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (514) */
/* 284 */	NdrFcLong( 0x7 ),	/* 7 */
/* 288 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 290 */	NdrFcLong( 0x8 ),	/* 8 */
/* 294 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (520) */
/* 296 */	NdrFcLong( 0xd ),	/* 13 */
/* 300 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (546) */
/* 302 */	NdrFcLong( 0x9 ),	/* 9 */
/* 306 */	NdrFcShort( 0x102 ),	/* Offset= 258 (564) */
/* 308 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 312 */	NdrFcShort( 0x10e ),	/* Offset= 270 (582) */
/* 314 */	NdrFcLong( 0x24 ),	/* 36 */
/* 318 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (1064) */
/* 320 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 324 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (1064) */
/* 326 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 330 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (1068) */
/* 332 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 336 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (1072) */
/* 338 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 342 */	NdrFcShort( 0x2de ),	/* Offset= 734 (1076) */
/* 344 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 348 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (1080) */
/* 350 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 354 */	NdrFcShort( 0x2da ),	/* Offset= 730 (1084) */
/* 356 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 360 */	NdrFcShort( 0x2d8 ),	/* Offset= 728 (1088) */
/* 362 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 366 */	NdrFcShort( 0x2c2 ),	/* Offset= 706 (1072) */
/* 368 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 372 */	NdrFcShort( 0x2c0 ),	/* Offset= 704 (1076) */
/* 374 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 378 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (1092) */
/* 380 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 384 */	NdrFcShort( 0x2c0 ),	/* Offset= 704 (1088) */
/* 386 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 390 */	NdrFcShort( 0x2c2 ),	/* Offset= 706 (1096) */
/* 392 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 396 */	NdrFcShort( 0x2c0 ),	/* Offset= 704 (1100) */
/* 398 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 402 */	NdrFcShort( 0x2be ),	/* Offset= 702 (1104) */
/* 404 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 408 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (1108) */
/* 410 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 414 */	NdrFcShort( 0x2ba ),	/* Offset= 698 (1112) */
/* 416 */	NdrFcLong( 0x10 ),	/* 16 */
/* 420 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 422 */	NdrFcLong( 0x12 ),	/* 18 */
/* 426 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 428 */	NdrFcLong( 0x13 ),	/* 19 */
/* 432 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 434 */	NdrFcLong( 0x15 ),	/* 21 */
/* 438 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 440 */	NdrFcLong( 0x16 ),	/* 22 */
/* 444 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 446 */	NdrFcLong( 0x17 ),	/* 23 */
/* 450 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 452 */	NdrFcLong( 0xe ),	/* 14 */
/* 456 */	NdrFcShort( 0x298 ),	/* Offset= 664 (1120) */
/* 458 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 462 */	NdrFcShort( 0x29c ),	/* Offset= 668 (1130) */
/* 464 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 468 */	NdrFcShort( 0x29a ),	/* Offset= 666 (1134) */
/* 470 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 474 */	NdrFcShort( 0x256 ),	/* Offset= 598 (1072) */
/* 476 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 480 */	NdrFcShort( 0x254 ),	/* Offset= 596 (1076) */
/* 482 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 486 */	NdrFcShort( 0x252 ),	/* Offset= 594 (1080) */
/* 488 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 492 */	NdrFcShort( 0x248 ),	/* Offset= 584 (1076) */
/* 494 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 498 */	NdrFcShort( 0x242 ),	/* Offset= 578 (1076) */
/* 500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x0 ),	/* Offset= 0 (504) */
/* 506 */	NdrFcLong( 0x1 ),	/* 1 */
/* 510 */	NdrFcShort( 0x0 ),	/* Offset= 0 (510) */
/* 512 */	NdrFcShort( 0xffff ),	/* Offset= -1 (511) */
/* 514 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 520 */	
			0x13, 0x0,	/* FC_OP */
/* 522 */	NdrFcShort( 0xe ),	/* Offset= 14 (536) */
/* 524 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 526 */	NdrFcShort( 0x2 ),	/* 2 */
/* 528 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 530 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 532 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 534 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 536 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 540 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (524) */
/* 542 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 544 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 546 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 558 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 560 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 562 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 564 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 566 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 576 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 578 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 580 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 582 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 584 */	NdrFcShort( 0x2 ),	/* Offset= 2 (586) */
/* 586 */	
			0x13, 0x0,	/* FC_OP */
/* 588 */	NdrFcShort( 0x1ca ),	/* Offset= 458 (1046) */
/* 590 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 592 */	NdrFcShort( 0x20 ),	/* 32 */
/* 594 */	NdrFcShort( 0xa ),	/* 10 */
/* 596 */	NdrFcLong( 0x8 ),	/* 8 */
/* 600 */	NdrFcShort( 0x50 ),	/* Offset= 80 (680) */
/* 602 */	NdrFcLong( 0xd ),	/* 13 */
/* 606 */	NdrFcShort( 0x70 ),	/* Offset= 112 (718) */
/* 608 */	NdrFcLong( 0x9 ),	/* 9 */
/* 612 */	NdrFcShort( 0x90 ),	/* Offset= 144 (756) */
/* 614 */	NdrFcLong( 0xc ),	/* 12 */
/* 618 */	NdrFcShort( 0xb0 ),	/* Offset= 176 (794) */
/* 620 */	NdrFcLong( 0x24 ),	/* 36 */
/* 624 */	NdrFcShort( 0x102 ),	/* Offset= 258 (882) */
/* 626 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 630 */	NdrFcShort( 0x10c ),	/* Offset= 268 (898) */
/* 632 */	NdrFcLong( 0x10 ),	/* 16 */
/* 636 */	NdrFcShort( 0x126 ),	/* Offset= 294 (930) */
/* 638 */	NdrFcLong( 0x2 ),	/* 2 */
/* 642 */	NdrFcShort( 0x13c ),	/* Offset= 316 (958) */
/* 644 */	NdrFcLong( 0x3 ),	/* 3 */
/* 648 */	NdrFcShort( 0x152 ),	/* Offset= 338 (986) */
/* 650 */	NdrFcLong( 0x14 ),	/* 20 */
/* 654 */	NdrFcShort( 0x168 ),	/* Offset= 360 (1014) */
/* 656 */	NdrFcShort( 0xffff ),	/* Offset= -1 (655) */
/* 658 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 668 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 672 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 674 */	
			0x13, 0x0,	/* FC_OP */
/* 676 */	NdrFcShort( 0xff74 ),	/* Offset= -140 (536) */
/* 678 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 680 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 682 */	NdrFcShort( 0x10 ),	/* 16 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x6 ),	/* Offset= 6 (692) */
/* 688 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 690 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 692 */	
			0x11, 0x0,	/* FC_RP */
/* 694 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (658) */
/* 696 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 706 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 710 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 712 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 714 */	NdrFcShort( 0xff58 ),	/* Offset= -168 (546) */
/* 716 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 718 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 720 */	NdrFcShort( 0x10 ),	/* 16 */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	NdrFcShort( 0x6 ),	/* Offset= 6 (730) */
/* 726 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 728 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 730 */	
			0x11, 0x0,	/* FC_RP */
/* 732 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (696) */
/* 734 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 744 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 748 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 750 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 752 */	NdrFcShort( 0xff44 ),	/* Offset= -188 (564) */
/* 754 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 756 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 758 */	NdrFcShort( 0x10 ),	/* 16 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x6 ),	/* Offset= 6 (768) */
/* 764 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 766 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 768 */	
			0x11, 0x0,	/* FC_RP */
/* 770 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (734) */
/* 772 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 782 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 786 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 788 */	
			0x13, 0x0,	/* FC_OP */
/* 790 */	NdrFcShort( 0x15c ),	/* Offset= 348 (1138) */
/* 792 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 794 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 796 */	NdrFcShort( 0x10 ),	/* 16 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x6 ),	/* Offset= 6 (806) */
/* 802 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 804 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 806 */	
			0x11, 0x0,	/* FC_RP */
/* 808 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (772) */
/* 810 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 812 */	NdrFcLong( 0x2f ),	/* 47 */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 822 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 824 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 826 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 828 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 830 */	NdrFcShort( 0x1 ),	/* 1 */
/* 832 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 834 */	NdrFcShort( 0x4 ),	/* 4 */
/* 836 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 838 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 840 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 842 */	NdrFcShort( 0x18 ),	/* 24 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0xa ),	/* Offset= 10 (856) */
/* 848 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 850 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 852 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (810) */
/* 854 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 856 */	
			0x13, 0x0,	/* FC_OP */
/* 858 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (828) */
/* 860 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 870 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 874 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 876 */	
			0x13, 0x0,	/* FC_OP */
/* 878 */	NdrFcShort( 0xffda ),	/* Offset= -38 (840) */
/* 880 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 882 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 884 */	NdrFcShort( 0x10 ),	/* 16 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x6 ),	/* Offset= 6 (894) */
/* 890 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 892 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 894 */	
			0x11, 0x0,	/* FC_RP */
/* 896 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (860) */
/* 898 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 900 */	NdrFcShort( 0x20 ),	/* 32 */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0xa ),	/* Offset= 10 (914) */
/* 906 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 908 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 910 */	0x0,		/* 0 */
			NdrFcShort( 0xfc8d ),	/* Offset= -883 (28) */
			0x5b,		/* FC_END */
/* 914 */	
			0x11, 0x0,	/* FC_RP */
/* 916 */	NdrFcShort( 0xff24 ),	/* Offset= -220 (696) */
/* 918 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 920 */	NdrFcShort( 0x1 ),	/* 1 */
/* 922 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 928 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 930 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 932 */	NdrFcShort( 0x10 ),	/* 16 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x6 ),	/* Offset= 6 (942) */
/* 938 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 940 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 942 */	
			0x13, 0x0,	/* FC_OP */
/* 944 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (918) */
/* 946 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 948 */	NdrFcShort( 0x2 ),	/* 2 */
/* 950 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 956 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 958 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 960 */	NdrFcShort( 0x10 ),	/* 16 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x6 ),	/* Offset= 6 (970) */
/* 966 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 968 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 970 */	
			0x13, 0x0,	/* FC_OP */
/* 972 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (946) */
/* 974 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 976 */	NdrFcShort( 0x4 ),	/* 4 */
/* 978 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 984 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 986 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 988 */	NdrFcShort( 0x10 ),	/* 16 */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	NdrFcShort( 0x6 ),	/* Offset= 6 (998) */
/* 994 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 996 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 998 */	
			0x13, 0x0,	/* FC_OP */
/* 1000 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (974) */
/* 1002 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1006 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1012 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1014 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1016 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1026) */
/* 1022 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1024 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1026 */	
			0x13, 0x0,	/* FC_OP */
/* 1028 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1002) */
/* 1030 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1034 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1036 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 1038 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1040 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1042 */	NdrFcShort( 0xfc3e ),	/* Offset= -962 (80) */
/* 1044 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1046 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1048 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1050 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1030) */
/* 1052 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1052) */
/* 1054 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1056 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1058 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1060 */	0x0,		/* 0 */
			NdrFcShort( 0xfe29 ),	/* Offset= -471 (590) */
			0x5b,		/* FC_END */
/* 1064 */	
			0x13, 0x0,	/* FC_OP */
/* 1066 */	NdrFcShort( 0xff1e ),	/* Offset= -226 (840) */
/* 1068 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1070 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1072 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1074 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1076 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1078 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1080 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1082 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1084 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1086 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1088 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1090 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1092 */	
			0x13, 0x0,	/* FC_OP */
/* 1094 */	NdrFcShort( 0xfdbc ),	/* Offset= -580 (514) */
/* 1096 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1098 */	NdrFcShort( 0xfdbe ),	/* Offset= -578 (520) */
/* 1100 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1102 */	NdrFcShort( 0xfdd4 ),	/* Offset= -556 (546) */
/* 1104 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1106 */	NdrFcShort( 0xfde2 ),	/* Offset= -542 (564) */
/* 1108 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1110 */	NdrFcShort( 0xfdf0 ),	/* Offset= -528 (582) */
/* 1112 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1114 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1116) */
/* 1116 */	
			0x13, 0x0,	/* FC_OP */
/* 1118 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1138) */
/* 1120 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1122 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1124 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1126 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1128 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1130 */	
			0x13, 0x0,	/* FC_OP */
/* 1132 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1120) */
/* 1134 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1136 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1138 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1140 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1144) */
/* 1146 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1148 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1150 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1152 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1154 */	NdrFcShort( 0xfc56 ),	/* Offset= -938 (216) */
/* 1156 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1158 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0xfc46 ),	/* Offset= -954 (212) */
/* 1168 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1170 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1174 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1174) */
/* 1176 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1178 */	0x0,		/* 0 */
			NdrFcShort( 0xfbb5 ),	/* Offset= -1099 (80) */
			0x6,		/* FC_SHORT */
/* 1182 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1184 */	0x0,		/* 0 */
			NdrFcShort( 0xffe5 ),	/* Offset= -27 (1158) */
			0x5b,		/* FC_END */
/* 1188 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1194 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1196 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1198 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1202 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1204 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1206 */	NdrFcShort( 0xffda ),	/* Offset= -38 (1168) */
/* 1208 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1210 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1212 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1214) */
/* 1214 */	
			0x13, 0x0,	/* FC_OP */
/* 1216 */	NdrFcShort( 0xfc00 ),	/* Offset= -1024 (192) */
/* 1218 */	
			0x11, 0x0,	/* FC_RP */
/* 1220 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1222) */
/* 1222 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1224 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1226 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1228 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1230 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1232 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1234 */	
			0x11, 0x0,	/* FC_RP */
/* 1236 */	NdrFcShort( 0x10 ),	/* Offset= 16 (1252) */
/* 1238 */	
			0x12, 0x0,	/* FC_UP */
/* 1240 */	NdrFcShort( 0xff9a ),	/* Offset= -102 (1138) */
/* 1242 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1250 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1238) */
/* 1252 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1256 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1258 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1260 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1262 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1266 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1268 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1270 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (1242) */
/* 1272 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1274 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1276 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1278) */
/* 1278 */	
			0x13, 0x0,	/* FC_OP */
/* 1280 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1222) */
/* 1282 */	
			0x11, 0x0,	/* FC_RP */
/* 1284 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1286) */
/* 1286 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1288 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1290 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1292 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1294 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1296 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1298 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1300 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1302) */
/* 1302 */	
			0x13, 0x0,	/* FC_OP */
/* 1304 */	NdrFcShort( 0xffee ),	/* Offset= -18 (1286) */
/* 1306 */	
			0x11, 0x0,	/* FC_RP */
/* 1308 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1310) */
/* 1310 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1316 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1318 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1320 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1324 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1326 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1328 */	NdrFcShort( 0xffaa ),	/* Offset= -86 (1242) */
/* 1330 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1332 */	
			0x11, 0x0,	/* FC_RP */
/* 1334 */	NdrFcShort( 0x2e ),	/* Offset= 46 (1380) */
/* 1336 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1338 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1340 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1342 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1344 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1346 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1348 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1350 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0xe ),	/* Offset= 14 (1368) */
/* 1356 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1358 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1360 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1362 */	0x36,		/* FC_POINTER */
			0x6,		/* FC_SHORT */
/* 1364 */	0x6,		/* FC_SHORT */
			0x40,		/* FC_STRUCTPAD4 */
/* 1366 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1368 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1370 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1372 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1374 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1376 */	
			0x12, 0x0,	/* FC_UP */
/* 1378 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (1336) */
/* 1380 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1386 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1388 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1390 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1394 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1396 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1398 */	NdrFcShort( 0xffce ),	/* Offset= -50 (1348) */
/* 1400 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1402 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1404 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1406) */
/* 1406 */	
			0x13, 0x0,	/* FC_OP */
/* 1408 */	NdrFcShort( 0x22 ),	/* Offset= 34 (1442) */
/* 1410 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1412 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1414 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1416 */	NdrFcShort( 0xc ),	/* 12 */
/* 1418 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1420 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1422 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1424 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0xa ),	/* Offset= 10 (1438) */
/* 1430 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 1432 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 1434 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1436 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1438 */	
			0x13, 0x0,	/* FC_OP */
/* 1440 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1410) */
/* 1442 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1446 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1448 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1450 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1452 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1456 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1458 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1460 */	NdrFcShort( 0xffda ),	/* Offset= -38 (1422) */
/* 1462 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1464 */	
			0x11, 0x0,	/* FC_RP */
/* 1466 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1468) */
/* 1468 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1470 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1472 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1474 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1476 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1478 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1480 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1482 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1484) */
/* 1484 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 1486 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 1488 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1490 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 1492 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1494 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1496) */
/* 1496 */	
			0x13, 0x0,	/* FC_OP */
/* 1498 */	NdrFcShort( 0x34 ),	/* Offset= 52 (1550) */
/* 1500 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1502 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1504 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1506 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1508 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1510 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1512 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1514 */	NdrFcShort( 0x50 ),	/* 80 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1538) */
/* 1520 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1522 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1524 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1526 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1528 */	0x36,		/* FC_POINTER */
			0x6,		/* FC_SHORT */
/* 1530 */	0x6,		/* FC_SHORT */
			0xd,		/* FC_ENUM16 */
/* 1532 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1534 */	NdrFcShort( 0xfe88 ),	/* Offset= -376 (1158) */
/* 1536 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1538 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1540 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1542 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1544 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1546 */	
			0x13, 0x0,	/* FC_OP */
/* 1548 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (1500) */
/* 1550 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1554 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1556 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1558 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1560 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1564 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1566 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1568 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1512) */
/* 1570 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1572 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1574 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1576) */
/* 1576 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1578 */	NdrFcLong( 0x39c13a55 ),	/* 968964693 */
/* 1582 */	NdrFcShort( 0x11e ),	/* 286 */
/* 1584 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 1586 */	0x96,		/* 150 */
			0x75,		/* 117 */
/* 1588 */	0x0,		/* 0 */
			0x20,		/* 32 */
/* 1590 */	0xaf,		/* 175 */
			0xd8,		/* 216 */
/* 1592 */	0xad,		/* 173 */
			0xb3,		/* 179 */
/* 1594 */	
			0x11, 0x0,	/* FC_RP */
/* 1596 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1598) */
/* 1598 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1600 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1602 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1604 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1606 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1608 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1610 */	
			0x11, 0x0,	/* FC_RP */
/* 1612 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1614) */
/* 1614 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1620 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1622 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1624 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1628 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1630 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1632 */	NdrFcShort( 0xfe7a ),	/* Offset= -390 (1242) */
/* 1634 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1636 */	
			0x11, 0x0,	/* FC_RP */
/* 1638 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1640) */
/* 1640 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1642 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1644 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1646 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1648 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1650 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1652 */	
			0x11, 0x0,	/* FC_RP */
/* 1654 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1656) */
/* 1656 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1660 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1662 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1664 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1666 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1670 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1672 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1674 */	NdrFcShort( 0xf9c6 ),	/* Offset= -1594 (80) */
/* 1676 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1678 */	
			0x11, 0x0,	/* FC_RP */
/* 1680 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1682) */
/* 1682 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1684 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1686 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1688 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1690 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1692 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1694 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1696 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1698) */
/* 1698 */	
			0x13, 0x0,	/* FC_OP */
/* 1700 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1702) */
/* 1702 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1704 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1706 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1708 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1710 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1712 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1714 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1716 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1718) */
/* 1718 */	
			0x13, 0x0,	/* FC_OP */
/* 1720 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1722) */
/* 1722 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1728 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1730 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1732 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1736 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1738 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1740 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1742 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1744 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1746 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1748) */
/* 1748 */	
			0x13, 0x0,	/* FC_OP */
/* 1750 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1752) */
/* 1752 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1754 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1756 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1758 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1760 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1762 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1764 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1766 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1768) */
/* 1768 */	
			0x13, 0x0,	/* FC_OP */
/* 1770 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1772) */
/* 1772 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1776 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1778 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1780 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1782 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1786 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1788 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1790 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (1158) */
/* 1792 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1794 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1796 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1798) */
/* 1798 */	
			0x13, 0x0,	/* FC_OP */
/* 1800 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1802) */
/* 1802 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1806 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1808 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1810 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1812 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1816 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1818 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1820 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1822 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1824 */	
			0x11, 0x0,	/* FC_RP */
/* 1826 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1828) */
/* 1828 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1830 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1832 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1834 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1836 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1838 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 1840 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1842 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1844) */
/* 1844 */	
			0x13, 0x0,	/* FC_OP */
/* 1846 */	NdrFcShort( 0xffee ),	/* Offset= -18 (1828) */
/* 1848 */	
			0x11, 0x0,	/* FC_RP */
/* 1850 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1852) */
/* 1852 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1856 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1858 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1860 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1862 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1866 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1868 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1870 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1872 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1874 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1876 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1878) */
/* 1878 */	
			0x13, 0x0,	/* FC_OP */
/* 1880 */	NdrFcShort( 0x46 ),	/* Offset= 70 (1950) */
/* 1882 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1884 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1888 */	NdrFcShort( 0xe ),	/* Offset= 14 (1902) */
/* 1890 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1892 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1894 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1896 */	0x0,		/* 0 */
			NdrFcShort( 0xfd1d ),	/* Offset= -739 (1158) */
			0x8,		/* FC_LONG */
/* 1900 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1902 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1904 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1906 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1908 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1910 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1914 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1916 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1918 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1920 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1924 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1926 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1928 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1882) */
/* 1930 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1932 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1934 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x8 ),	/* Offset= 8 (1946) */
/* 1940 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1942 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1944 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 1946 */	
			0x13, 0x0,	/* FC_OP */
/* 1948 */	NdrFcShort( 0xffda ),	/* Offset= -38 (1910) */
/* 1950 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1954 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1956 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1958 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1960 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1964 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1966 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1968 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1932) */
/* 1970 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1972 */	
			0x11, 0x0,	/* FC_RP */
/* 1974 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1976) */
/* 1976 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1978 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1980 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1982 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 1984 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1986 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1988 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1990 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1992) */
/* 1992 */	
			0x13, 0x0,	/* FC_OP */
/* 1994 */	NdrFcShort( 0x1c ),	/* Offset= 28 (2022) */
/* 1996 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1998 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2002 */	NdrFcShort( 0xc ),	/* Offset= 12 (2014) */
/* 2004 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 2006 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2008 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2010 */	NdrFcShort( 0xffb2 ),	/* Offset= -78 (1932) */
/* 2012 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2014 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 2016 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 2018 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 2020 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 2022 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2026 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 2028 */	NdrFcShort( 0x60 ),	/* X64 Stack size/offset = 96 */
/* 2030 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2032 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2036 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2038 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2040 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (1996) */
/* 2042 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2044 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2046 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2048) */
/* 2048 */	
			0x13, 0x0,	/* FC_OP */
/* 2050 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2052) */
/* 2052 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2056 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2058 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2060 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2062 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2066 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2068 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2070 */	NdrFcShort( 0xfc70 ),	/* Offset= -912 (1158) */
/* 2072 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2074 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2076 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2078) */
/* 2078 */	
			0x13, 0x0,	/* FC_OP */
/* 2080 */	NdrFcShort( 0xfd9c ),	/* Offset= -612 (1468) */
/* 2082 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2084 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2086) */
/* 2086 */	
			0x13, 0x0,	/* FC_OP */
/* 2088 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2090) */
/* 2090 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2094 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2096 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2098 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2100 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2104 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2106 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2108 */	NdrFcShort( 0xf814 ),	/* Offset= -2028 (80) */
/* 2110 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2112 */	
			0x11, 0x0,	/* FC_RP */
/* 2114 */	NdrFcShort( 0x18 ),	/* Offset= 24 (2138) */
/* 2116 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2118 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2122 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2122) */
/* 2124 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2126 */	NdrFcShort( 0xfc8c ),	/* Offset= -884 (1242) */
/* 2128 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 2130 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 2132 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2134 */	0x0,		/* 0 */
			NdrFcShort( 0xf7f9 ),	/* Offset= -2055 (80) */
			0x5b,		/* FC_END */
/* 2138 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2142 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2144 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2146 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2148 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2152 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2154 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2156 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (2116) */
/* 2158 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: CATID_OPCDAServer10, ver. 0.0,
   GUID={0x63D5F430,0xCFE4,0x11d1,{0xB2,0xC8,0x00,0x60,0x08,0x3B,0xA1,0xFB}} */

#pragma code_seg(".orpc")
static const unsigned short CATID_OPCDAServer10_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO CATID_OPCDAServer10_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_OPCDAServer10_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO CATID_OPCDAServer10_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_OPCDAServer10_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _CATID_OPCDAServer10ProxyVtbl = 
{
    0,
    &IID_CATID_OPCDAServer10,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _CATID_OPCDAServer10StubVtbl =
{
    &IID_CATID_OPCDAServer10,
    &CATID_OPCDAServer10_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: CATID_OPCDAServer20, ver. 0.0,
   GUID={0x63D5F432,0xCFE4,0x11d1,{0xB2,0xC8,0x00,0x60,0x08,0x3B,0xA1,0xFB}} */

#pragma code_seg(".orpc")
static const unsigned short CATID_OPCDAServer20_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO CATID_OPCDAServer20_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_OPCDAServer20_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO CATID_OPCDAServer20_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_OPCDAServer20_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _CATID_OPCDAServer20ProxyVtbl = 
{
    0,
    &IID_CATID_OPCDAServer20,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _CATID_OPCDAServer20StubVtbl =
{
    &IID_CATID_OPCDAServer20,
    &CATID_OPCDAServer20_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: CATID_OPCDAServer30, ver. 0.0,
   GUID={0xCC603642,0x66D7,0x48f1,{0xB6,0x9A,0xB6,0x25,0xE7,0x36,0x52,0xD7}} */

#pragma code_seg(".orpc")
static const unsigned short CATID_OPCDAServer30_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO CATID_OPCDAServer30_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_OPCDAServer30_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO CATID_OPCDAServer30_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_OPCDAServer30_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _CATID_OPCDAServer30ProxyVtbl = 
{
    0,
    &IID_CATID_OPCDAServer30,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _CATID_OPCDAServer30StubVtbl =
{
    &IID_CATID_OPCDAServer30,
    &CATID_OPCDAServer30_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: CATID_XMLDAServer10, ver. 0.0,
   GUID={0x3098EDA4,0xA006,0x48b2,{0xA2,0x7F,0x24,0x74,0x53,0x95,0x94,0x08}} */

#pragma code_seg(".orpc")
static const unsigned short CATID_XMLDAServer10_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO CATID_XMLDAServer10_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_XMLDAServer10_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO CATID_XMLDAServer10_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &CATID_XMLDAServer10_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _CATID_XMLDAServer10ProxyVtbl = 
{
    0,
    &IID_CATID_XMLDAServer10,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _CATID_XMLDAServer10StubVtbl =
{
    &IID_CATID_XMLDAServer10,
    &CATID_XMLDAServer10_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_opcda_0000_0004, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IOPCServer, ver. 0.0,
   GUID={0x39c13a4d,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCServer_FormatStringOffsetTable[] =
    {
    0,
    98,
    148,
    198,
    236,
    280
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCServer_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOPCServerProxyVtbl = 
{
    &IOPCServer_ProxyInfo,
    &IID_IOPCServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCServer::AddGroup */ ,
    (void *) (INT_PTR) -1 /* IOPCServer::GetErrorString */ ,
    (void *) (INT_PTR) -1 /* IOPCServer::GetGroupByName */ ,
    (void *) (INT_PTR) -1 /* IOPCServer::GetStatus */ ,
    (void *) (INT_PTR) -1 /* IOPCServer::RemoveGroup */ ,
    (void *) (INT_PTR) -1 /* IOPCServer::CreateGroupEnumerator */
};

const CInterfaceStubVtbl _IOPCServerStubVtbl =
{
    &IID_IOPCServer,
    &IOPCServer_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCServerPublicGroups, ver. 0.0,
   GUID={0x39c13a4e,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCServerPublicGroups_FormatStringOffsetTable[] =
    {
    330,
    380
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCServerPublicGroups_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCServerPublicGroups_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCServerPublicGroups_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCServerPublicGroups_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOPCServerPublicGroupsProxyVtbl = 
{
    &IOPCServerPublicGroups_ProxyInfo,
    &IID_IOPCServerPublicGroups,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCServerPublicGroups::GetPublicGroupByName */ ,
    (void *) (INT_PTR) -1 /* IOPCServerPublicGroups::RemovePublicGroup */
};

const CInterfaceStubVtbl _IOPCServerPublicGroupsStubVtbl =
{
    &IID_IOPCServerPublicGroups,
    &IOPCServerPublicGroups_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCBrowseServerAddressSpace, ver. 0.0,
   GUID={0x39c13a4f,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCBrowseServerAddressSpace_FormatStringOffsetTable[] =
    {
    424,
    462,
    506,
    568,
    612
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCBrowseServerAddressSpace_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCBrowseServerAddressSpace_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCBrowseServerAddressSpace_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCBrowseServerAddressSpace_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IOPCBrowseServerAddressSpaceProxyVtbl = 
{
    &IOPCBrowseServerAddressSpace_ProxyInfo,
    &IID_IOPCBrowseServerAddressSpace,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCBrowseServerAddressSpace::QueryOrganization */ ,
    (void *) (INT_PTR) -1 /* IOPCBrowseServerAddressSpace::ChangeBrowsePosition */ ,
    (void *) (INT_PTR) -1 /* IOPCBrowseServerAddressSpace::BrowseOPCItemIDs */ ,
    (void *) (INT_PTR) -1 /* IOPCBrowseServerAddressSpace::GetItemID */ ,
    (void *) (INT_PTR) -1 /* IOPCBrowseServerAddressSpace::BrowseAccessPaths */
};

const CInterfaceStubVtbl _IOPCBrowseServerAddressSpaceStubVtbl =
{
    &IID_IOPCBrowseServerAddressSpace,
    &IOPCBrowseServerAddressSpace_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCGroupStateMgt, ver. 0.0,
   GUID={0x39c13a50,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCGroupStateMgt_FormatStringOffsetTable[] =
    {
    656,
    736,
    810,
    848
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCGroupStateMgt_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCGroupStateMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCGroupStateMgt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCGroupStateMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IOPCGroupStateMgtProxyVtbl = 
{
    &IOPCGroupStateMgt_ProxyInfo,
    &IID_IOPCGroupStateMgt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::GetState */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::SetState */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::SetName */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::CloneGroup */
};

const CInterfaceStubVtbl _IOPCGroupStateMgtStubVtbl =
{
    &IID_IOPCGroupStateMgt,
    &IOPCGroupStateMgt_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCPublicGroupStateMgt, ver. 0.0,
   GUID={0x39c13a51,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCPublicGroupStateMgt_FormatStringOffsetTable[] =
    {
    898,
    936
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCPublicGroupStateMgt_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCPublicGroupStateMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCPublicGroupStateMgt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCPublicGroupStateMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOPCPublicGroupStateMgtProxyVtbl = 
{
    &IOPCPublicGroupStateMgt_ProxyInfo,
    &IID_IOPCPublicGroupStateMgt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCPublicGroupStateMgt::GetState */ ,
    (void *) (INT_PTR) -1 /* IOPCPublicGroupStateMgt::MoveToPublic */
};

const CInterfaceStubVtbl _IOPCPublicGroupStateMgtStubVtbl =
{
    &IID_IOPCPublicGroupStateMgt,
    &IOPCPublicGroupStateMgt_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCSyncIO, ver. 0.0,
   GUID={0x39c13a52,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCSyncIO_FormatStringOffsetTable[] =
    {
    968,
    1030
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCSyncIO_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCSyncIO_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCSyncIO_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCSyncIO_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOPCSyncIOProxyVtbl = 
{
    &IOPCSyncIO_ProxyInfo,
    &IID_IOPCSyncIO,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCSyncIO::Read */ ,
    (void *) (INT_PTR) -1 /* IOPCSyncIO::Write */
};

const CInterfaceStubVtbl _IOPCSyncIOStubVtbl =
{
    &IID_IOPCSyncIO,
    &IOPCSyncIO_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCAsyncIO, ver. 0.0,
   GUID={0x39c13a53,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCAsyncIO_FormatStringOffsetTable[] =
    {
    1086,
    1154,
    1222,
    1272
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCAsyncIO_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCAsyncIO_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCAsyncIO_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCAsyncIO_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IOPCAsyncIOProxyVtbl = 
{
    &IOPCAsyncIO_ProxyInfo,
    &IID_IOPCAsyncIO,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO::Read */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO::Write */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO::Refresh */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO::Cancel */
};

const CInterfaceStubVtbl _IOPCAsyncIOStubVtbl =
{
    &IID_IOPCAsyncIO,
    &IOPCAsyncIO_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCItemMgt, ver. 0.0,
   GUID={0x39c13a54,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCItemMgt_FormatStringOffsetTable[] =
    {
    1310,
    1366,
    1428,
    1478,
    1534,
    1590,
    1646
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCItemMgt_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCItemMgt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IOPCItemMgtProxyVtbl = 
{
    &IOPCItemMgt_ProxyInfo,
    &IID_IOPCItemMgt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCItemMgt::AddItems */ ,
    (void *) (INT_PTR) -1 /* IOPCItemMgt::ValidateItems */ ,
    (void *) (INT_PTR) -1 /* IOPCItemMgt::RemoveItems */ ,
    (void *) (INT_PTR) -1 /* IOPCItemMgt::SetActiveState */ ,
    (void *) (INT_PTR) -1 /* IOPCItemMgt::SetClientHandles */ ,
    (void *) (INT_PTR) -1 /* IOPCItemMgt::SetDatatypes */ ,
    (void *) (INT_PTR) -1 /* IOPCItemMgt::CreateEnumerator */
};

const CInterfaceStubVtbl _IOPCItemMgtStubVtbl =
{
    &IID_IOPCItemMgt,
    &IOPCItemMgt_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumOPCItemAttributes, ver. 0.0,
   GUID={0x39c13a55,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumOPCItemAttributes_FormatStringOffsetTable[] =
    {
    1690,
    1740,
    1778,
    1810
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumOPCItemAttributes_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IEnumOPCItemAttributes_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IEnumOPCItemAttributes_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IEnumOPCItemAttributes_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumOPCItemAttributesProxyVtbl = 
{
    &IEnumOPCItemAttributes_ProxyInfo,
    &IID_IEnumOPCItemAttributes,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumOPCItemAttributes::Next */ ,
    (void *) (INT_PTR) -1 /* IEnumOPCItemAttributes::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumOPCItemAttributes::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumOPCItemAttributes::Clone */
};

const CInterfaceStubVtbl _IEnumOPCItemAttributesStubVtbl =
{
    &IID_IEnumOPCItemAttributes,
    &IEnumOPCItemAttributes_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCDataCallback, ver. 0.0,
   GUID={0x39c13a70,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCDataCallback_FormatStringOffsetTable[] =
    {
    1848,
    1940,
    2032,
    2100
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCDataCallback_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCDataCallback_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCDataCallback_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCDataCallback_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IOPCDataCallbackProxyVtbl = 
{
    &IOPCDataCallback_ProxyInfo,
    &IID_IOPCDataCallback,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCDataCallback::OnDataChange */ ,
    (void *) (INT_PTR) -1 /* IOPCDataCallback::OnReadComplete */ ,
    (void *) (INT_PTR) -1 /* IOPCDataCallback::OnWriteComplete */ ,
    (void *) (INT_PTR) -1 /* IOPCDataCallback::OnCancelComplete */
};

const CInterfaceStubVtbl _IOPCDataCallbackStubVtbl =
{
    &IID_IOPCDataCallback,
    &IOPCDataCallback_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCAsyncIO2, ver. 0.0,
   GUID={0x39c13a71,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCAsyncIO2_FormatStringOffsetTable[] =
    {
    2144,
    2206,
    2274,
    1272,
    2324,
    2362
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCAsyncIO2_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCAsyncIO2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCAsyncIO2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCAsyncIO2_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOPCAsyncIO2ProxyVtbl = 
{
    &IOPCAsyncIO2_ProxyInfo,
    &IID_IOPCAsyncIO2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Read */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Write */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Refresh2 */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Cancel2 */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::SetEnable */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::GetEnable */
};

const CInterfaceStubVtbl _IOPCAsyncIO2StubVtbl =
{
    &IID_IOPCAsyncIO2,
    &IOPCAsyncIO2_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCItemProperties, ver. 0.0,
   GUID={0x39c13a72,0x011e,0x11d0,{0x96,0x75,0x00,0x20,0xaf,0xd8,0xad,0xb3}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCItemProperties_FormatStringOffsetTable[] =
    {
    2400,
    2462,
    2524
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCItemProperties_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCItemProperties_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IOPCItemPropertiesProxyVtbl = 
{
    &IOPCItemProperties_ProxyInfo,
    &IID_IOPCItemProperties,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCItemProperties::QueryAvailableProperties */ ,
    (void *) (INT_PTR) -1 /* IOPCItemProperties::GetItemProperties */ ,
    (void *) (INT_PTR) -1 /* IOPCItemProperties::LookupItemIDs */
};

const CInterfaceStubVtbl _IOPCItemPropertiesStubVtbl =
{
    &IID_IOPCItemProperties,
    &IOPCItemProperties_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCItemDeadbandMgt, ver. 0.0,
   GUID={0x5946DA93,0x8B39,0x4ec8,{0xAB,0x3D,0xAA,0x73,0xDF,0x5B,0xC8,0x6F}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCItemDeadbandMgt_FormatStringOffsetTable[] =
    {
    2586,
    2642,
    1428
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCItemDeadbandMgt_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemDeadbandMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCItemDeadbandMgt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemDeadbandMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IOPCItemDeadbandMgtProxyVtbl = 
{
    &IOPCItemDeadbandMgt_ProxyInfo,
    &IID_IOPCItemDeadbandMgt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCItemDeadbandMgt::SetItemDeadband */ ,
    (void *) (INT_PTR) -1 /* IOPCItemDeadbandMgt::GetItemDeadband */ ,
    (void *) (INT_PTR) -1 /* IOPCItemDeadbandMgt::ClearItemDeadband */
};

const CInterfaceStubVtbl _IOPCItemDeadbandMgtStubVtbl =
{
    &IID_IOPCItemDeadbandMgt,
    &IOPCItemDeadbandMgt_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCItemSamplingMgt, ver. 0.0,
   GUID={0x3E22D313,0xF08B,0x41a5,{0x86,0xC8,0x95,0xE9,0x5C,0xB4,0x9F,0xFC}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCItemSamplingMgt_FormatStringOffsetTable[] =
    {
    2698,
    2760,
    1428,
    2816,
    2872
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCItemSamplingMgt_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemSamplingMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCItemSamplingMgt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemSamplingMgt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IOPCItemSamplingMgtProxyVtbl = 
{
    &IOPCItemSamplingMgt_ProxyInfo,
    &IID_IOPCItemSamplingMgt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCItemSamplingMgt::SetItemSamplingRate */ ,
    (void *) (INT_PTR) -1 /* IOPCItemSamplingMgt::GetItemSamplingRate */ ,
    (void *) (INT_PTR) -1 /* IOPCItemSamplingMgt::ClearItemSamplingRate */ ,
    (void *) (INT_PTR) -1 /* IOPCItemSamplingMgt::SetItemBufferEnable */ ,
    (void *) (INT_PTR) -1 /* IOPCItemSamplingMgt::GetItemBufferEnable */
};

const CInterfaceStubVtbl _IOPCItemSamplingMgtStubVtbl =
{
    &IID_IOPCItemSamplingMgt,
    &IOPCItemSamplingMgt_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCBrowse, ver. 0.0,
   GUID={0x39227004,0xA18F,0x4b57,{0x8B,0x0A,0x52,0x35,0x67,0x0F,0x44,0x68}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCBrowse_FormatStringOffsetTable[] =
    {
    2928,
    2996
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCBrowse_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCBrowse_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCBrowse_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCBrowse_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOPCBrowseProxyVtbl = 
{
    &IOPCBrowse_ProxyInfo,
    &IID_IOPCBrowse,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCBrowse::GetProperties */ ,
    (void *) (INT_PTR) -1 /* IOPCBrowse::Browse */
};

const CInterfaceStubVtbl _IOPCBrowseStubVtbl =
{
    &IID_IOPCBrowse,
    &IOPCBrowse_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCItemIO, ver. 0.0,
   GUID={0x85C0B427,0x2893,0x4cbc,{0xBD,0x78,0xE5,0xFC,0x51,0x46,0xF0,0x8F}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCItemIO_FormatStringOffsetTable[] =
    {
    3106,
    3180
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCItemIO_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemIO_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCItemIO_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCItemIO_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOPCItemIOProxyVtbl = 
{
    &IOPCItemIO_ProxyInfo,
    &IID_IOPCItemIO,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCItemIO::Read */ ,
    (void *) (INT_PTR) -1 /* IOPCItemIO::WriteVQT */
};

const CInterfaceStubVtbl _IOPCItemIOStubVtbl =
{
    &IID_IOPCItemIO,
    &IOPCItemIO_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCSyncIO2, ver. 0.0,
   GUID={0x730F5F0F,0x55B1,0x4c81,{0x9E,0x18,0xFF,0x8A,0x09,0x04,0xE1,0xFA}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCSyncIO2_FormatStringOffsetTable[] =
    {
    968,
    1030,
    3236,
    3310
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCSyncIO2_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCSyncIO2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCSyncIO2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCSyncIO2_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IOPCSyncIO2ProxyVtbl = 
{
    &IOPCSyncIO2_ProxyInfo,
    &IID_IOPCSyncIO2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCSyncIO::Read */ ,
    (void *) (INT_PTR) -1 /* IOPCSyncIO::Write */ ,
    (void *) (INT_PTR) -1 /* IOPCSyncIO2::ReadMaxAge */ ,
    (void *) (INT_PTR) -1 /* IOPCSyncIO2::WriteVQT */
};

const CInterfaceStubVtbl _IOPCSyncIO2StubVtbl =
{
    &IID_IOPCSyncIO2,
    &IOPCSyncIO2_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCAsyncIO3, ver. 0.0,
   GUID={0x0967B97B,0x36EF,0x423e,{0xB6,0xF8,0x6B,0xFF,0x1E,0x40,0xD3,0x9D}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCAsyncIO3_FormatStringOffsetTable[] =
    {
    2144,
    2206,
    2274,
    1272,
    2324,
    2362,
    3366,
    3434,
    3502
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCAsyncIO3_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCAsyncIO3_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCAsyncIO3_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCAsyncIO3_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IOPCAsyncIO3ProxyVtbl = 
{
    &IOPCAsyncIO3_ProxyInfo,
    &IID_IOPCAsyncIO3,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Read */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Write */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Refresh2 */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::Cancel2 */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::SetEnable */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO2::GetEnable */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO3::ReadMaxAge */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO3::WriteVQT */ ,
    (void *) (INT_PTR) -1 /* IOPCAsyncIO3::RefreshMaxAge */
};

const CInterfaceStubVtbl _IOPCAsyncIO3StubVtbl =
{
    &IID_IOPCAsyncIO3,
    &IOPCAsyncIO3_ServerInfo,
    12,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOPCGroupStateMgt2, ver. 0.0,
   GUID={0x8E368666,0xD72E,0x4f78,{0x87,0xED,0x64,0x76,0x11,0xC6,0x1C,0x9F}} */

#pragma code_seg(".orpc")
static const unsigned short IOPCGroupStateMgt2_FormatStringOffsetTable[] =
    {
    656,
    736,
    810,
    848,
    3552,
    2362
    };

static const MIDL_STUBLESS_PROXY_INFO IOPCGroupStateMgt2_ProxyInfo =
    {
    &Object_StubDesc,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCGroupStateMgt2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOPCGroupStateMgt2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    opcda__MIDL_ProcFormatString.Format,
    &IOPCGroupStateMgt2_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOPCGroupStateMgt2ProxyVtbl = 
{
    &IOPCGroupStateMgt2_ProxyInfo,
    &IID_IOPCGroupStateMgt2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::GetState */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::SetState */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::SetName */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt::CloneGroup */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt2::SetKeepAlive */ ,
    (void *) (INT_PTR) -1 /* IOPCGroupStateMgt2::GetKeepAlive */
};

const CInterfaceStubVtbl _IOPCGroupStateMgt2StubVtbl =
{
    &IID_IOPCGroupStateMgt2,
    &IOPCGroupStateMgt2_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    opcda__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _opcda_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IOPCBrowseProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCSyncIO2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCItemSamplingMgtProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCItemIOProxyVtbl,
    ( CInterfaceProxyVtbl *) &_CATID_OPCDAServer10ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_CATID_OPCDAServer20ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_CATID_OPCDAServer30ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCServerPublicGroupsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCBrowseServerAddressSpaceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCGroupStateMgtProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCPublicGroupStateMgtProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCSyncIOProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCAsyncIOProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCItemMgtProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumOPCItemAttributesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCGroupStateMgt2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCDataCallbackProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCAsyncIO2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCItemPropertiesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCAsyncIO3ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOPCItemDeadbandMgtProxyVtbl,
    ( CInterfaceProxyVtbl *) &_CATID_XMLDAServer10ProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _opcda_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IOPCBrowseStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCSyncIO2StubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCItemSamplingMgtStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCItemIOStubVtbl,
    ( CInterfaceStubVtbl *) &_CATID_OPCDAServer10StubVtbl,
    ( CInterfaceStubVtbl *) &_CATID_OPCDAServer20StubVtbl,
    ( CInterfaceStubVtbl *) &_CATID_OPCDAServer30StubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCServerPublicGroupsStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCBrowseServerAddressSpaceStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCGroupStateMgtStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCPublicGroupStateMgtStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCSyncIOStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCAsyncIOStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCItemMgtStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumOPCItemAttributesStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCGroupStateMgt2StubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCDataCallbackStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCAsyncIO2StubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCItemPropertiesStubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCAsyncIO3StubVtbl,
    ( CInterfaceStubVtbl *) &_IOPCItemDeadbandMgtStubVtbl,
    ( CInterfaceStubVtbl *) &_CATID_XMLDAServer10StubVtbl,
    0
};

PCInterfaceName const _opcda_InterfaceNamesList[] = 
{
    "IOPCBrowse",
    "IOPCSyncIO2",
    "IOPCItemSamplingMgt",
    "IOPCItemIO",
    "CATID_OPCDAServer10",
    "CATID_OPCDAServer20",
    "CATID_OPCDAServer30",
    "IOPCServer",
    "IOPCServerPublicGroups",
    "IOPCBrowseServerAddressSpace",
    "IOPCGroupStateMgt",
    "IOPCPublicGroupStateMgt",
    "IOPCSyncIO",
    "IOPCAsyncIO",
    "IOPCItemMgt",
    "IEnumOPCItemAttributes",
    "IOPCGroupStateMgt2",
    "IOPCDataCallback",
    "IOPCAsyncIO2",
    "IOPCItemProperties",
    "IOPCAsyncIO3",
    "IOPCItemDeadbandMgt",
    "CATID_XMLDAServer10",
    0
};


#define _opcda_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _opcda, pIID, n)

int __stdcall _opcda_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _opcda, 23, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _opcda, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _opcda, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _opcda, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _opcda, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _opcda, 23, *pIndex )
    
}

const ExtendedProxyFileInfo opcda_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _opcda_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _opcda_StubVtblList,
    (const PCInterfaceName * ) & _opcda_InterfaceNamesList,
    0, /* no delegation */
    & _opcda_IID_Lookup, 
    23,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

