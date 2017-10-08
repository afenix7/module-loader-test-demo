#pragma once

#include "../engine/IPlugin.h"

namespace valkyr{

	class IFramePlugin : public IPlugin
	{
	public:
		IFramePlugin(){}
		virtual ~IFramePlugin(){}

		virtual void frameUpdate() = 0;

		virtual void fixedUpdate() = 0;
	};

}