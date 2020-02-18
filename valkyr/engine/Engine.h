#pragma once

#include <vector>
#include <map>
#include <iostream>
#include "../core/vcommon.h"
#include "../log/LogMgr.h"
#include "../engine/IFramePlugin.h"
#include "../render/Renderer.h"

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

const vstr struct Config
{
};

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
	inline void setWidth(vint width){
		
	}
	vint getWidth();
	void setHeight(vint height);
	vint getHeight();
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
	vptr<LogMgr> getLogMgr();
	int setLogMgr(vptr<LogMgr> logMgr);
	vptr<Renderer> getRenderer();
	int setRenderer(vptr<Renderer> renderer);
	inline vptr<Config> getConfig()
	{
	}

private:
	Engine();

	//vuni_ptr not suitable for singleton
	//not need use shared_ptr, or will face "can not visit private member"
	static Engine *mSingleton;
	vhwnd mHwnd;
	vint mWidth, mHeight;
	vptr<LogMgr> mLogMgr;
	vptr<Renderer> mRenderer;
	std::map<vcstr, vhdll> mModuleMap;
	std::vector<vhdll> mModuleList;
	Config mConfig;
	lua_State *L = nullptr;
};

} // namespace valkyr
