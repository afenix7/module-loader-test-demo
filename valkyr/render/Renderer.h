#pragma once

#include "../engine/IRenderPlugin.h"
#include "sol/sol.hpp"

namespace valkyr
{
class Renderer
{
public:
	Renderer() {}
	virtual ~Renderer() {}
	virtual vint initGraphics(sol::table config, vhwnd hwnd) = 0;
	//virtual vint loadRes() = 0;
	//virtual void generateRenderList() = 0;
	virtual void preRender() = 0;
	virtual void render() = 0;
	//virtual void drawScenePass() = 0;
	//virtual void drawLightPass() = 0;
	//virtual void drawCompositionPass() = 0;
	//virtual void drawPostFX() = 0;
	virtual void destroy() = 0;
	//virtual void createWindow() = 0;
};
} // namespace valkyr