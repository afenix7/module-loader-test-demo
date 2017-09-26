#pragma once

#include "vptr.h"
#include "./vplatform.h"
//#include "./vmath.h"

#define VALKYR_EXPORTS

#ifdef VALKYR_EXPORTS
#define VALKYR_API __declspec(dllexport)
#else
#define VALKYR_API __declspec(dllimport)
#endif

template <typename T> class Singleton
{

public:
	/*
	Singleton(void)
	{
		//assert(!ms_Singleton);
		ms_Singleton = static_cast<T*>(this);
	}
	*/

	~Singleton(void)
	{
		//assert(ms_Singleton);  
		ms_Singleton.reset();
	}
	
	/*
	static T& getSingleton(void)
	{
		//assert(ms_Singleton);  
		return (*ms_Singleton);
	}
	*/

	static vptr<T> getInstance(void)
	{
		return (ms_Singleton);
	}

protected:
	static vptr<T> ms_Singleton;

	Singleton(void)
	{
		//assert(!ms_Singleton);
		//ms_Singleton = static_cast<T*>(this);
		vnew_ptr<T>(ms_Singleton);
	}
};

