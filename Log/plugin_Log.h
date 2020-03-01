#pragma once

//#include "vcommon.h"
#include "../valkyr/engine/Engine.h"
#include "FileLog.h"
#include <iostream>

using namespace valkyr;

static vptr<FileLog> g_logMgr;

inline void LogStart(){
    g_logMgr = vmake_ptr<FileLog>();
	g_logMgr->setFilePath("../bin/vlog.txt");
	if (Engine::getSingletonPtr()->setLogMgr(g_logMgr) == VOK) {
		std::cout << "log start" << std::endl;
	}
}

inline void LogStop(){

}