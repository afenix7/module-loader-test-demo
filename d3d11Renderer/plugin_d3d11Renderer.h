#pragma once

#include "D3d11Renderer.h"
#include "../valkyr/engine/Engine.h"

using namespace valkyr;

static vptr<D3d11Renderer> g_renderer;

void d3d11RendererStart(){
    g_renderer = vmake_ptr<D3d11Renderer>();
    sol::table config = Engine::getSingletonPtr()->getConfig()["gfx"];
    g_renderer->initGraphics(config, Engine::getSingletonPtr()->getHwnd());
    if (Engine::getSingletonPtr()->setRenderer(g_renderer) == VOK){
		Engine::getSingletonPtr()->getLogMgr()->log("Render","Render plugin start successful",LogLevel::standard);
		std::cout << "render plugin start" << std::endl;
	}
	else
	{
		Engine::getSingletonPtr()->getLogMgr()->log("Error", "Render plugin start error",  LogLevel::error);
	}
}

void d3d11RendererStop(){
    g_renderer->destroy();
}


