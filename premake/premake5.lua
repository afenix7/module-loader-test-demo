-- premake5.lua
workspace "walkyrie"
	startproject "vapp"
	configurations { "Debug", "Release", "DebugDLL", "ReleaseDLL","DebugLib","ReleaseLib"}
	platforms { "Win32", "Win64"}
	location "../build"
	
	filter "configurations:Debug*"
		defines { "DEBUG" }
		flags { "MultiProcessorCompile" }
		symbols "On"
		warnings "Extra"
		libdirs {"../lib/%{cfg.platform}_%{cfg.buildcfg}","../bin/%{cfg.platform}_%{cfg.buildcfg}"}
		targetdir "../bin/%{cfg.platform}_%{cfg.buildcfg}"
		objdir "../obj/%{cfg.platform}_%{cfg.buildcfg}"

	filter "configurations:Release*"
		defines { "NDEBUG" }
		flags { "MultiProcessorCompile" }
		symbols "Off"
		optimize "On"
		libdirs {"../lib/%{cfg.platform}_%{cfg.buildcfg}","../bin/%{cfg.platform}_%{cfg.buildcfg}"}
		targetdir "../bin/%{cfg.platform}_%{cfg.buildcfg}"
		objdir "../obj/%{cfg.platform}_%{cfg.buildcfg}"
		
	filter "configurations:*DLL"
		kind "SharedLib"
		defines { "VALKYR_EXPORTS","_USRDLL" }
		
	filter "configurations:*Lib"
		kind "StaticLib"
	
	filter { "platforms:Win32" }
		system "Windows"
		architecture "x32"
		defines {"_WINDOWS","WIN32"}

	filter { "platforms:Win64" }
		system "Windows"
		defines {"_WINDOWS","WIN64"}
		architecture "x86_64"

	
project "valkyr"
	configurations {"DebugDLL","ReleaseDLL"}
	kind "SharedLib"
	location "../build"
	--defines {"_WINDLL"}
	--DirectXMath seems not need config anything here
	language "C++"
	--maybe ../valkyr/**.h can work
	files {"../valkyr/*.h","../valkyr/*.cpp","../valkyr/core/*.h","../valkyr/log/*.h","../valkyr/net/*.h","../valkyr/physics/*.h","../valkyr/script/*.h","../valkyr/render/*.h","../valkyr/engine/*.h","../valkyr/engine/*.cpp"}

project "Log"
    --should change AFX to std::string
	configurations {"DebugDLL","ReleaseDLL"}
	kind "SharedLib"
	location "../build"
	language "C++"
	links "valkyr"
	files {"../Log/*.h","../Log/*.cpp"}

project "d3d11Renderer"
	configurations {"DebugDLL","ReleaseDLL"}
	kind "SharedLib"
	location "../build"
	language "C++"
	files {"../d3d11Renderer/*.h","../d3d11Renderer/*.cpp"}
	links { "valkyr","d3d11","dxgi","d3dcompiler"}

-- should remove mainCRTxxxx as entry point of the generated project, or will face entry error
project "vapp"
	kind "WindowedApp"
	configurations {"Debug","Release"}
	location "../build"
	language "C++"
	files {"../vapp/*.h","../vapp/*.cpp","../vapp/*.rc","../vapp/*.ico"}

project "vtest"
	kind "ConsoleApp"
	configurations {"Debug","Release"}
	location "../build"
	language "C++"
	files {"../vtest/*.h","../vtest/*.cpp"}

