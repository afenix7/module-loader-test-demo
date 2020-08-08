#pragma once

#include "../engine/IPlugin.h"

namespace valkyr {


	class IRenderPlugin : public IPlugin
	{
	public:
		IRenderPlugin() {};
		virtual ~IRenderPlugin() {};

		virtual void preRender() = 0;
		virtual void render() = 0;
	};

};
