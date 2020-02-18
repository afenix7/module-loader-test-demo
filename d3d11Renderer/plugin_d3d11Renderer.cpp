// d3d11Renderer.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "D3d11Renderer.h"
#include "../valkyr/engine/Engine.h"

#pragma comment(lib,"valkyr.lib")

using namespace valkyr;

static vptr<D3d11Renderer> g_renderer;

extern"C" __declspec(dllexport) void dllStartPlugin(){
	g_renderer = vmake_ptr<D3d11Renderer>();
	//g_renderer = vmake_ptr<D3d11Renderer>();
	/*
	GraphicsConfig config;
	config.width = Engine::getSingletonPtr()->getWidth();
	config.height = Engine::getSingletonPtr()->getHeight();
	config.MSAACount = 1;
	config.MSAAQuality = 0;
	config.refreshRate = 60;
	config.windowed = true;
	config.hWnd = Engine::getSingletonPtr()->getHwnd();
	*/
	vptr<Bundle> config = vmake_ptr<Bundle>();
	config->putInt(CONFIG_WIDTH, Engine::getSingletonPtr()->getWidth());
	config->putInt(CONFIG_HEIGHT, Engine::getSingletonPtr()->getHeight());
	config->putInt(CONFIG_REFRESH_RATE,60);
	config->putInt(CONFIG_WINDOWED, 1);
	config->putInt(CONFIG_MSAACOUNT,8);
	g_renderer->initGraphics(config, Engine::getSingletonPtr()->getHwnd());
	
	//g_renderer->loadRes();
	if (Engine::getSingletonPtr()->setRenderer(g_renderer) == VOK){
	//if (Engine::getSingletonPtr()->installPlugin<D3d11Renderer>(g_renderer) == VOK){
		Engine::getSingletonPtr()->getLogMgr()->log("Render","Render plugin start successful",LogLevel::standard);
		std::cout << "render plugin start" << std::endl;
	}
	else
	{
		Engine::getSingletonPtr()->getLogMgr()->log("Error", "render plugin start error",  LogLevel::error);
	}
}

extern"C" __declspec(dllexport) void dllStopPlugin(){
	g_renderer->destroy();
	//g_renderer.reset();
	//delete g_renderer;
}


