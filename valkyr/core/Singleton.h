#pragma once

#include "vptr.h"

template <class T> class Singleton
{

public:
	Singleton(void)
	{
		//assert(!ms_Singleton);
		ms_Singleton = static_cast<T*>(this);
	}
	~Singleton(void)
	{
		//assert(ms_Singleton);  
		//ms_Singleton = 0;
	}
	static T& getSingleton(void)
	{
		//assert(ms_Singleton);  
		return (*ms_Singleton);
	}
	static vptr<T> getSingletonPtr(void)
	{
		return ms_Singleton;
	}

protected:
	static vptr<T> ms_Singleton;
};
