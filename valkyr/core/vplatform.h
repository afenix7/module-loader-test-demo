#pragma once

//#define _WINDOWS
#define _WIN10
//#define LINUX

#if defined _WINDOWS
//#include "../targetver.h"
#define WIN32_LEAN_AND_MEAN 
//#include <afx.h>
//need work for all windows configs, so afx will be discarded
//#include <assert.h>
//#include <iostream>
#include <windows.h>

typedef unsigned int vsize;
typedef UINT vint;
typedef BOOL vbool;
typedef BYTE vbyte;
typedef double vdouble;
#define vtrue TRUE
#define vfalse FALSE
#define VOK 1
#define VERR 0

#define vstr LPTSTR
#define vcstr LPCTSTR
//ANSI constant string
#define vconst_ansi_str LPCSTR 

#define vhwnd HWND
#define vhdll HINSTANCE
#define vhandle HINSTANCE

//#define vwindow(hinstance,classname,title,w,h) CreateWindow(classname,title,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT,w,h,NULL,NULL,hinstance,NULL);
#define vloadlib( filename ) LoadLibraryEx( filename, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#define vgetsym( hdll, funcname ) GetProcAddress( hdll, funcname )
#define vfreelib( hdll ) FreeLibrary( hdll )

#elif defined _LINUX
#include <dlfcn.h>
#include <string>
#include <iostream>

#define CALLBACK _stdcall
typedef unsigned int vint;
typedef bool vbool;
typedef unsigned char vbyte;
#define vtrue true
#define vfalse false
#define VOK 1
#define VERR 0

typedef std::string vstring;
#define vstr char*
#define vcstr const char*
//ANSI constant string
#define vcastr const char*

#define vhwnd void*
#define vhdll void*
#define vhandle int

#define vloadlib( filename ) dlopen(filename,RTLD_LAZY)
#define vgetsym (hdll,funcname) dlsym(hdll,funcname)
#define vfreelib(hdll) dlclose(hdll)


#endif

