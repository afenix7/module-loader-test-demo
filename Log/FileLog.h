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
	void setFilePath(vstring filePath);
	virtual void log(vstring title, vstring content, LogLevel level);

private:
	vstring mFilePath;
};

