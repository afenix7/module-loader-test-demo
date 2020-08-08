#pragma once

#include "../core/vcommon.h"
#include "../core/vstring.h"

namespace valkyr
{
	class LogMgr
	{

	public:
		enum class LogLevel
		{
			standard,
			warn,
			error
		};

		LogMgr() {};
		virtual ~LogMgr() {};
		virtual void log(vstring title, vstring content, LogLevel level) = 0;
	};

}