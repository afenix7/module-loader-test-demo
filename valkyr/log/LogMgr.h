#pragma once

#include "../core/vcommon.h"

namespace valkyr
{

	enum LogLevel
	{
		standard,
		warn,
		error
	};

	class LogMgr
	{
	public:
		LogMgr(){};
		virtual ~LogMgr() {};
		virtual void log(vstr content, vstr title, LogLevel level)=0;
	};

}