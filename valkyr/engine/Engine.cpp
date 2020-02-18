//#include "stdafx.h"
#include "./Engine.h"
#include "assert.h"

using namespace valkyr;

Engine *Engine::mSingleton = nullptr;

Engine::Engine() : mLogMgr(nullptr), mRenderer(nullptr), mConfig(new Bundle()), mWidth(800), mHeight(600), mHwnd(HWND())
{
	L = luaL_newstate();
	luaL_openlibs(L);
}

Engine::~Engine()
{
}

Engine &Engine::getSingleton()
{
	assert(mSingleton);
	return (*mSingleton);
}

Engine *Engine::getSingletonPtr()
{
	if (!mSingleton)
	{
		mSingleton = new Engine();
	}
	return mSingleton;
}

inline void Engine::setHwnd(vhwnd hwnd)
{
	mHwnd = hwnd;
}

inline vhwnd Engine::getHwnd()
{
	return mHwnd;
}

//todo: store in a Config class
inline vint Engine::getHeight() { return mHeight; }

inline void Engine::setHeight(vint height)
{
	mHeight = height;
}

inline vint Engine::getWidth() { return mWidth; }

inline void Engine::setWidth(vint width)
{
	mWidth = width;
}

bool Engine::init()
{
	auto ret = Engine::getSingletonPtr()->loadModule(TEXT("Log.dll"));
	if (ret == VERR)
		return false;

	if (mLogMgr)
	{
		mLogMgr->log("Engine launch", "Engine init successful", LogLevel::standard);
	}
	return true;
	//mWidth = 1024;
	//mHeight = 768;
}

bool Engine::start()
{
	auto ret = Engine::getSingletonPtr()->loadModule(TEXT("d3d11Renderer.dll"));
	if (ret == VERR)
		return false;
	if (mLogMgr)
	{
		if (mRenderer)
			mLogMgr->log("Engine launch", "Engine start successful", LogLevel::standard);
		else
			mLogMgr->log("Engine launch error", "Engine start error", LogLevel::error);
	}

	return true;
}

bool Engine::stop()
{
	//if (this->unloadPlugin(TEXT("Log.dll")) == VOK)
	if (this->unloadModules() == VOK)
	{
		return true;
	}
	else
		return false;
}

void Engine::update()
{
	std::cout << "engine update" << std::endl;
}

void Engine::render()
{
	if (mRenderer)
	{
		mRenderer->render();
		//std::cout << "engine render" << std::endl;
	}
}

vint Engine::loadModules()
{
}

vint Engine::loadModule(vlcstr name)
{
	vhdll hdll = vloadlib(name);
	if (hdll == NULL)
	{
		return VERR;
	}
	LPFNStartFunc lpstartfunc = (LPFNStartFunc)GetProcAddress(hdll, "dllStartPlugin");
	if (lpstartfunc == NULL)
	{
		vfreelib(hdll);
		return VERR;
	}
	//mPluginMap.insert(std::make_pair(name, hdll));
	//mPluginMap.insert(decltype(mPluginMap.))
	mModuleList.push_back(hdll);
	lpstartfunc();
	return VOK;
}

/*
int Engine::unloadPlugin(vlcstr name)
{
	vhdll hdll = mPluginMap[name];
	if (hdll == NULL){
		return VERR;
	}
	LPFNStopFunc lpstopfunc = (LPFNStopFunc)GetProcAddress(hdll, "dllStopPlugin");
	if (lpstopfunc){
		lpstopfunc();
		vfreelib(hdll);
		return VOK;
	}
	else
	{
		return VERR;
	}
}
*/

vint Engine::unloadModules()
{
	for (auto hdll : mModuleList)
	{
		LPFNStopFunc lpstopfunc = (LPFNStopFunc)GetProcAddress(hdll, "dllStopPlugin");
		if (lpstopfunc)
		{
			lpstopfunc();
			vfreelib(hdll);
		}
		else
			return VERR;
	}
	mModuleList.clear();
	return VOK;
}

vptr<LogMgr> Engine::getLogMgr()
{
	return mLogMgr;
}

int Engine::setLogMgr(vptr<LogMgr> logMgr)
{
	mLogMgr = logMgr;
	if (!mLogMgr)
		return VERR;
	else
		return VOK;
}

vptr<Renderer> Engine::getRenderer()
{
	return mRenderer;
}

int Engine::setRenderer(vptr<Renderer> renderer)
{
	mRenderer = renderer;
	if (!mRenderer)
		return VERR;
	else
		return VOK;
}

vptr<Config> valkyr::Engine::getConfig()
{
	return mConfig;
}
