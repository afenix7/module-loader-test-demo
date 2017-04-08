// valkyr.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "valkyr.h"

using namespace valkyr;
//Engine* g_pEngine = new Engine();

extern"C" VALKYR_API bool game_init()
{
	return Engine::getSingletonPtr()->init();
}

extern"C" VALKYR_API bool game_setclientwindow(int width, int height)
{
	if (width > 0 && height > 0)
	{
		Engine::getSingletonPtr()->setHeight(height);
		Engine::getSingletonPtr()->setWidth(width);
		return true;
	}
	else return false;
}

extern"C" VALKYR_API int game_getwidth()
{
	return Engine::getSingletonPtr()->getWidth();
}

extern "C" VALKYR_API int game_getheight()
{
	return Engine::getSingletonPtr()->getHeight();
}

extern"C" VALKYR_API bool game_start(HWND hwnd)
{
	Engine::getSingletonPtr()->setHwnd(hwnd);
	return Engine::getSingletonPtr()->start();
}

extern"C" VALKYR_API void game_update(){
	Engine::getSingletonPtr()->update();
}

extern"C" VALKYR_API void game_render(){
	Engine::getSingletonPtr()->render();
}

extern"C" VALKYR_API bool game_stop(){
	return Engine::getSingletonPtr()->stop();
}