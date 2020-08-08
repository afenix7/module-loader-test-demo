#pragma once

#include "../core/vcommon.h"

namespace valkyr {

	class IPlugin
	{
	public:
		IPlugin() {}
		virtual ~IPlugin() {}
		virtual void start() = 0;
		virtual void stop() = 0;
	};

};