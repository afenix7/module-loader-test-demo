#pragma once

#include "../core/vcommon.h"
#include "Config.h"

namespace valkyr{

	class IPlugin
	{
	public:
		IPlugin(){}
		virtual ~IPlugin(){}
		virtual void start(vptr<Config> config) = 0;
		virtual void stop() = 0;
	};

}