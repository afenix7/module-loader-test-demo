#pragma once
namespace valkyr
{
using vcstr = const char *;

#if defined _WINDOWS

#ifndef _WIN_H
#include <windows.h>
#define WIN32_LEAN_AND_MEAN
#define _WIN_H
#endif

#define vlstr LPTSTR
#define vlcstr LPCTSTR
//ANSI constant string
#define vlcastr LPCSTR

#else

#define vlstr char *
#define vlcstr const char *
//ANSI constant string
#define vlcastr const char *

#endif
} // namespace valkyr