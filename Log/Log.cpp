// Log.cpp : Defines the exported functions for the DLL application.
//
//#include "stdafx.h"
#include "Log.h"
#include <iostream>

#pragma comment(lib,"valkyr.lib")

using namespace valkyr;

static vptr<FileLog> g_logMgr;
//static vptr<FileLog> g_logMgr;

extern"C" __declspec(dllexport) void dllStartPlugin(){
	g_logMgr = vmake_ptr<FileLog>();
	g_logMgr->setFilePath("../bin/vlog.txt");
	if (Engine::getSingletonPtr()->setLogMgr(g_logMgr) == VOK) {
		std::cout << "plugin start" << std::endl;
	}
	else
	{

	}
}

extern"C" __declspec(dllexport) void dllStopPlugin(){
}


