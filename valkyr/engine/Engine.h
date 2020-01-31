#pragma once

#include <vector>
#include <iostream>
#include "../core/vcommon.h"
#include "../core/vplatform.h"
#include "../core/vptr.h"
#include "../core/Config.h"
#include "../log/LogMgr.h"
#include "../engine/IFramePlugin.h"
#include "../render/Renderer.h"

typedef void (CALLBACK* LPFNStartFunc)();
typedef void (CALLBACK* LPFNStopFunc)();

namespace valkyr
{
	class VALKYR_API Engine
	{
	public:		
		~Engine();
		static Engine& getSingleton(void);
		static Engine* getSingletonPtr(void);
		//Engine& getSingleton(void);

		void setHwnd(vhwnd hwnd);
		vhwnd getHwnd();
		void setWidth(vint width);
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
		vint loadModule(vcstr name);
		//template <class T> vint installPlugin(T plugin);
		//template <IFramePlugin> vint installPlugin()
		//int unloadPlugin(vcstr name);
		vint unloadModules();
		vptr<LogMgr> getLogMgr();
		int setLogMgr(vptr<LogMgr> logMgr);
		vptr<Renderer> getRenderer();
		int setRenderer(vptr<Renderer> renderer);
		vptr<Config> getConfig();

	private:
		Engine();

		//vuni_ptr not suitable for singleton
		//not need use shared_ptr, or will face "can not visit private member"
		static Engine* mSingleton;
		vhwnd mHwnd;
		vint mWidth, mHeight;
		vptr<LogMgr> mLogMgr;
		vptr<Renderer> mRenderer;
		//std::map<vcstr,vhdll> mPluginMap;
		std::vector<vhdll> mModuleList;
		vptr<Config> mConfig;
	};

}
