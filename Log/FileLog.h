#pragma once

#include "../valkyr/core/vcommon.h"
#include "../valkyr/log/LogMgr.h"
#include <time.h> 
#include <fstream>
//#include <locale>

using namespace valkyr;

class FileLog:public LogMgr
{
public:
	FileLog();
	//static FileLog& getSingleton(void);
	//static FileLog* getSingletonPtr(void);
	virtual ~FileLog(); 
	void setFilePath(vstr filePath);
	virtual void log(vstr content, vstr title, LogLevel level);

private:
	vstr mFilePath;
};

