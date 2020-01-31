#pragma once

#include "../core/vcommon.h"
#include "../core/vstring.h"

namespace valkyr
{

	enum class LogLevel
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
		virtual void log(vstring title, vstring content, LogLevel level)=0;
	};

}