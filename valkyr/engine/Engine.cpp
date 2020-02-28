//#include "stdafx.h"
#include "./Engine.h"
#include "assert.h"
#ifdef MODULE_EMBED
#include "modules_gen.h"
#endif

using namespace valkyr;

Engine *Engine::mSingleton = nullptr;

Engine::Engine() : mLogMgr(nullptr), mRenderer(nullptr), mConfig(new Bundle()), mWidth(800), mHeight(600), mHwnd(HWND())
{
}

Engine::~Engine()
{
}

void Engine::initConfig()
{
	lua.open_libraries(sol::lib::base);
	lua.script_file("valkyr.lua");
	mConfig = lua["config"];
	mWidth = mConfig["width"].get_or(0);
	mHeight = mConfig["height"].get_or(0);
	mModuleNames = lua["modules"];
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
	vforeach(mModuleNames.begin(), mModuleNames.end(), [](vstring &moduleName) {
		loadModule(moduleName.c_str());
	});
}

vint Engine::loadModule(vlcstr name)
{
	vhdll hdll = vloadlib(name);
	if (hdll == NULL)
	{
		return VERR;
	}
	//LPFNStartFunc lpstartfunc = (LPFNStartFunc)GetProcAddress(hdll, "dllStartPlugin");
	LPFNStartFunc lpstartfunc = (LPFNStartFunc)vgetsym(hdll, "dllStartPlugin");
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

vint Engine::unloadModules()
{
	for (auto hdll : mModuleList)
	{
		LPFNStopFunc lpstopfunc = (LPFNStopFunc)vgetsym(hdll, "dllStopPlugin");
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