#pragma once

#if defined _WINDOWS
#ifndef _WIN_H
#include <windows.h>
#define WIN32_LEAN_AND_MEAN
#define _WIN_H
#endif

#define vloadlib(filename) LoadLibraryEx(filename, NULL, LOAD_WITH_ALTERED_SEARCH_PATH)
#define vgetsym(hdll, funcname) GetProcAddress(hdll, funcname)
#define vfreelib(hdll) FreeLibrary(hdll)

#else
#include <dlfcn.h>

#define vloadlib(filename) dlopen(filename, RTLD_LAZY)
#define vgetsym (hdll, funcname) dlsym(hdll, funcname)
#define vfreelib(hdll) dlclose(hdll)

#endif