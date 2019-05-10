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
 
// Server.test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <objbase.h>

#include <math.h>
#include <atlsafe.h>
#include <atlstr.h>
#include <ATLComTime.h>

#include "..\Server.dll\ag_Clocker.h"
#include "..\Server.dll\OPCServerObject.h"

/// Object received all values, changed inside OPC server 
class dataReceiver :
	public COPCReceiveData
{
public:

	virtual void newData(LPCTSTR name, FILETIME &time, VARIANT &value)
	{
		double v;
		CComVariant val = value;
		switch( val.vt ) {
			case VT_I2:
			case VT_I4:
			case VT_INT:		v = val.intVal; break;
			case VT_FILETIME:	break;
			case VT_R4:			v = val.fltVal; break;
			case VT_R8:			v = val.dblVal; break;
			case VT_EMPTY:
				v = -1.999999; break;
			default:
				v = 1.999999; break;
		};
		printf("Param changed [%s] value=%f\n", name, v );	
	}
};

GUID CLSID_OPCServerEXE = { 0x4ea2713d, 0xca07, 0x11d4, {0xbe, 0xf5, 0x0, 0x0, 0x21, 0x20, 0xdb, 0x5E} };

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *pfFile;

	AllocConsole();
	freopen_s(&pfFile,"conout$","w+",stdout);    //打开控制台   

	if(argc > 2)
	{
		printf("Usage:%s", argv[0]);
		printf("      %s /r", argv[0]);
		printf("      %s /u", argv[0]);
		printf("  : start opc server\r\n");
		printf("/r: regist opc server\r\n");
		printf("/u: unregist opc server\r\n");

		fclose(pfFile); 
		FreeConsole();

		return -1;
	}

	char str[1024] = {0};

	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	// define server object 
	COPCServerObject server;
	// define data event receiver 
	dataReceiver receiver;

	// set server name and clsid
	server.setServerProgID( _T("OPC.myTestServer") );
	server.setServerCLSID( CLSID_OPCServerEXE );

	// set delimeter for params name 
	server.SetDelimeter( "." );

	if(argc == 2)
	{
		if(strstr(argv[1], "/r"))
		{
			// register server as COM/DCOM object 
			server.RegisterServer();

			fclose(pfFile); 
			FreeConsole();

			return 0;
		}
		else if(strstr(argv[1], "/u"))
		{
			server.UnregisterServer();

			getchar();

			fclose(pfFile); 
			FreeConsole();

			return 0;
		}
	}
	

	// define server values tree
	server.AddTag("Values.int1", VT_I4 );
	server.AddTag("Values.int2", VT_I4 );
	server.AddTag("Values.fltArray2", VT_ARRAY|VT_R4 );
	server.AddTag("Values.fltArray2.In", VT_I4, false );

	{
		CAG_Clocker cl("Create 10000 tags",false);

		for(int i=0;i<10000;++i) {
			sprintf(str,"RandomValues.int%d",i+1);
			server.AddTag( str ,VT_I4 );
		}
	}

	// setup object will be received add values change 
	server.setDataReceiver( &receiver );
	
	// create COM class factory and register it 
	server.StartServer();

	printf("\t waiting return\n");
	gets(str);

	// write initial values to OPC params
	for( double x =0.;  x< 50.;x+=.1 ) {
		server.WriteValue( "Values.int1", FILETIME_NULL, 192, CComVariant( sin(x) ) );
		server.WriteValue( "Values.int2", FILETIME_NULL, 192, CComVariant( cos(x) ) );
		Sleep(100);
	}

	srand( (unsigned)time( NULL ) );

	for(int i=0;i<10000;++i) {
		sprintf(str,"RandomValues.int%d",i+1);
		server.WriteValue( str , FILETIME_NULL, 192, CComVariant( rand() ) );
	}

	printf("\t waiting return for close server \n");
	gets(str);

	server.StopServer();
	

	CoUninitialize();

	fclose(pfFile); 
	FreeConsole();

	return 0;
}

