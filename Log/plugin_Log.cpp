// Log.cpp : Defines the exported functions for the DLL application.
//
//#include "stdafx.h"
#include "plugin_Log.h"

#pragma comment(lib,"valkyr.lib")

extern"C" __declspec(dllexport) void dllStartPlugin(){
	LogStart();
}

extern"C" __declspec(dllexport) void dllStopPlugin(){
	LogStop();
}


