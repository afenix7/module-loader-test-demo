#pragma once

//#include <vector>
#include "../core/vcommon.h"
#include "../core/vlist.h"
#include "../engine/Config.h"
#include "../log/LogMgr.h"
#include "../engine/FramePlugin.h"
#include "../render/Renderer.h"

typedef void (CALLBACK* LPFNStartFunc)();
typedef void (CALLBACK* LPFNStopFunc)();

namespace valkyr
{
	class VALKYR_API Engine : Singleton<Engine>
	{
	public:		
		~Engine();
		//static Engine& getSingleton(void);
		//static Engine* getSingletonPtr(void);
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
		vbool init(Config config);
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

		static vptr<Engine> mSingleton;
		vhwnd mHwnd;
		vint mWidth, mHeight;
		vptr<LogMgr> mLogMgr;
		vptr<Renderer> mRenderer;
		//std::map<vcstr,vhdll> mPluginMap;
		//vlist<vhdll> mModuleList;
		vlist<Plugin> mPluginList;
		vptr<Config> mConfig;
	};

}
