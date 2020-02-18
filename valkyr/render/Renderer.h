#pragma once

#include "../core/Config.h"
#include "../engine/IRenderPlugin.h"

namespace valkyr
{
	/*
	struct GraphicsConfig
	{
		vint width;
		vint height;
		vint refreshRate;
		vint MSAACount;
		vint MSAAQuality;
		vbool windowed;
		vhwnd hWnd;
	}
	*/
#define CONFIG_WIDTH 0
#define CONFIG_HEIGHT 1
#define CONFIG_REFRESH_RATE 2
#define CONFIG_MSAACOUNT 3
#define CONFIG_MSAAQUALITY 4
#define CONFIG_WINDOWED 5
#define CONFIG_HWND 6

	class Renderer
	{
	public:
		Renderer(){}
		virtual ~Renderer() {}
		virtual vint initGraphics(vptr<Bundle> pConfig,vhwnd hwnd) = 0;
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
}