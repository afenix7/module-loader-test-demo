#include "engine/Engine.h"

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the VALKYR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// VALKYR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

//VALKYR_API int fnvalkyr(void);
extern"C" VALKYR_API bool game_init();
extern"C" VALKYR_API bool game_setclientwindow(int width, int height);
extern "C" VALKYR_API int game_getwidth();
extern "C" VALKYR_API int game_getheight();
extern"C" VALKYR_API bool game_start(HWND hwnd);
extern"C" VALKYR_API void game_update(void);
extern"C" VALKYR_API void game_render(void);
extern"C" VALKYR_API bool game_stop(void);