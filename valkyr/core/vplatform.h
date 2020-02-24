#pragma once

namespace valkyr
{
using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using imax = std::intmax_t;
using umax = std::uintmax_t;
using vsize = std::size_t;
using vint = unsigned int;
#define VOK 1
#define VERR 0
} // namespace valkyr

//#define _WINDOWS
#define _WIN10

//#define LINUX
#if defined _WINDOWS
//#include "../targetver.h"
//#include <afx.h>
//need work for all windows configs, so afx will be discarded
//#include <assert.h>
//#include <iostream>
#ifndef _WIN_H
#include <windows.h>
#define WIN32_LEAN_AND_MEAN
#define _WIN_H
#endif

#define vhwnd HWND
#define vhdll HINSTANCE
#define vhandle HINSTANCE

//#define vwindow(hinstance,classname,title,w,h) CreateWindow(classname,title,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT,w,h,NULL,NULL,hinstance,NULL);

#else

#define CALLBACK _stdcall
#define NULL 0

#define vhwnd void *
#define vhdll void *
#define vhandle int

#endif
