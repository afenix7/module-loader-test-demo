#include "valkyr.h"

//Engine* g_pEngine = new Engine();

extern"C" VALKYR_API bool game_init()
{
	return valkyr::Engine::getSingletonPtr()->init();
}

extern"C" VALKYR_API bool game_setclientwindow(int width, int height)
{
	if (width > 0 && height > 0)
	{
		valkyr::Engine::getSingletonPtr()->setHeight(height);
		valkyr::Engine::getSingletonPtr()->setWidth(width);
		return true;
	}
	else return false;
}

extern"C" VALKYR_API int game_getwidth()
{
	return valkyr::Engine::getSingletonPtr()->getWidth();
}

extern "C" VALKYR_API int game_getheight()
{
	return valkyr::Engine::getSingletonPtr()->getHeight();
}

extern"C" VALKYR_API bool game_start(HWND hwnd)
{
	valkyr::Engine::getSingletonPtr()->setHwnd(hwnd);
	return valkyr::Engine::getSingletonPtr()->start();
}

extern"C" VALKYR_API void game_update(){
	valkyr::Engine::getSingletonPtr()->update();
}

extern"C" VALKYR_API void game_render(){
	valkyr::Engine::getSingletonPtr()->render();
}

extern"C" VALKYR_API bool game_stop(){
	return valkyr::Engine::getSingletonPtr()->stop();
}