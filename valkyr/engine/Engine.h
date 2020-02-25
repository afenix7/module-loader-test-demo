#pragma once

#include <iostream>
#include "../core/vcommon.h"
#include "../core/vmodule.h"
#include "../container/vec.h"
#include "../container/algorithm.h"
#include "../log/LogMgr.h"
#include "../engine/IFramePlugin.h "
#include "../render/Renderer.h"
#include "../../extern/sol/sol.hpp"

#define VALKYR_EXPORTS

#ifdef VALKYR_EXPORTS
#define VALKYR_API __declspec(dllexport)
#else
#define VALKYR_API __declspec(dllimport)
#endif

typedef void(CALLBACK *LPFNStartFunc)();
typedef void(CALLBACK *LPFNStopFunc)();

namespace valkyr
{

class VALKYR_API Engine
{
public:
	~Engine();
	static Engine &getSingleton(void)
	{
		return (*mSingleton);
	}
	static Engine *getSingletonPtr(void)
	{
		if (!mSingleton)
		{
			mSingleton = new Engine();
		}
		return mSingleton;
	}

	inline void setHwnd(vhwnd hwnd)
	{
		mHwnd = hwnd;
	}
	inline vhwnd getHwnd()
	{
		return mHwnd;
	}
	inline void setWidth(vint width)
	{
		mWidth = width;
	}
	inline vint getWidth()
	{
		return mWidth;
	}
	inline void setHeight(vint height)
	{
		mHeight = height;
	}
	inline vint getHeight()
	{
		return mHeight;
	}
	inline sol::table getConfig()
	{
		return mConfig;
	}
	vptr<LogMgr> getLogMgr()
	{
		return mLogMgr;
	}
	int setLogMgr(vptr<LogMgr> logMgr)
	{
		mLogMgr = logMgr;
		if (!mLogMgr)
			return VERR;
		else
			return VOK;
	}
	vptr<Renderer> getRenderer()
	{
		return mRenderer;
	}

	int setRenderer(vptr<Renderer> renderer)
	{
		mRenderer = renderer;
		if (!mRenderer)
			return VERR;
		else
			return VOK;
	}

	//bool loadConfig();
	//void createWindow(vhwnd hwnd,vint width,vint height);
	bool init();
	bool start();
	void update();
	void render();
	bool stop();
	vint loadModules();
	vint loadModule(vlcstr name);
	//template <class T> vint installPlugin(T plugin);
	//template <IFramePlugin> vint installPlugin()
	//int unloadPlugin(vcstr name);
	vint unloadModules();

private:
	Engine();
	void initConfig();

	//vuni_ptr not suitable for singleton
	//not need use shared_ptr, or will face "can not visit private member"
	static Engine *mSingleton;
	vhwnd mHwnd;
	vint mWidth, mHeight;
	vptr<LogMgr> mLogMgr;
	vptr<Renderer> mRenderer;
	vec<vstring> mModuleNames;
	vec<vhdll> mModuleList;
	sol::table mConfig;
	sol::state lua;
};

} // namespace valkyr
