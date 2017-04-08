// Log.cpp : Defines the exported functions for the DLL application.
//
//#include "stdafx.h"
#include "Log.h"

#pragma comment(lib,"valkyr.lib")

using namespace valkyr;

static FileLog* g_logMgr;
//static vptr<FileLog> g_logMgr;

extern"C" __declspec(dllexport) void dllStartPlugin(){
	g_logMgr = new FileLog();
	g_logMgr->setFilePath(TEXT("vallog.txt"));
	if (Engine::getSingletonPtr()->setLogMgr(g_logMgr) == VOK) {
		std::cout << "plugin start" << std::endl;
	}
	else
	{

	}
}

extern"C" __declspec(dllexport) void dllStopPlugin(){
	delete g_logMgr;
}


