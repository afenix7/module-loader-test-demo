// d3d11Renderer.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "plugin_d3d11Renderer.h"

#pragma comment(lib,"valkyr.lib")

extern"C" __declspec(dllexport) void dllStartPlugin(){
	d3d11RendererStart();
}

extern"C" __declspec(dllexport) void dllStopPlugin(){
	d3d11RendererStop();
}


