#pragma once

//#include "./vplatform.h"
//#include "./vmath.h"

#define VALKYR_EXPORTS

#ifdef VALKYR_EXPORTS
#define VALKYR_API __declspec(dllexport)
#else
#define VALKYR_API __declspec(dllimport)
#endif



