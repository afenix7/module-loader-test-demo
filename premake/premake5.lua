-- premake5.lua
workspace "walkyrie"
	startproject "vapp"
	configurations { "Debug", "Release", "DebugDLL", "ReleaseDLL","DebugLib","ReleaseLib"}
	platforms { "Win32", "Win64",}
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
		system "windows"
		architecture "x32"
		defines {"_WINDOWS","WIN32"}

	filter { "platforms:Win64" }
		system "windows"
		defines {"_WINDOWS","WIN64"}
		architecture "x64"
	filter { "platforms:Linux32" }
		system "linux"
		defines {"_LINUX"}
		architecture "x32"
	filter { "platforms:Linux64" }
		system "linux"
		defines {"_LINUX"}
		architecture "x64"
	filter { "platforms:Mac64" }
		system "macosx"
		defines {"_MACOSX"}
		architecture "x64"


	
project "valkyr"
	configurations {"DebugDLL","ReleaseDLL"}
	kind "SharedLib"
	location "../build"
	language "C++"
	libdirs {"../extern/lua/lib/%{cfg.platform}_%{cfg.buildcfg}"}
	links {"lua"}
	includedirs {"../extern/sol2/include","../extern/lua/include","../extern/hlslpp"}
	cppdialect "C++17"
	files {
		"../valkyr/**.h","../valkyr/**.cpp"
	}

project "Log"
	configurations {"DebugDLL","ReleaseDLL"}
	kind "SharedLib"
	location "../build"
	language "C++"
	links "valkyr"
	cppdialect "C++17"
	files {"../Log/**.h","../Log/**.cpp"}

project "d3d11Renderer"
	configurations {"DebugDLL","ReleaseDLL"}
	kind "SharedLib"
	location "../build"
	language "C++"
	cppdialect "C++17"
	links { "valkyr","d3d11","dxgi","d3dcompiler","lua"}
	libdirs {"../extern/lua/lib/%{cfg.platform}_%{cfg.buildcfg}"}
	includedirs {"../extern/sol2/include","../extern/lua/include","../extern/hlslpp"}
	files {"../d3d11Renderer/**.h","../d3d11Renderer/**.cpp"}


project "d3d12Renderer"
	configurations {"DebugDLL","ReleaseDLL"}
	kind "SharedLib"
	location "../build"
	language "C++"
	cppdialect "C++17"
	libdirs {"../extern/lua/lib/%{cfg.platform}_%{cfg.buildcfg}"}
	includedirs {"../extern/sol2/include","../extern/lua/include","../extern/hlslpp"}
	files {"../d3d12Renderer/**.h","../d3d12Renderer/**.cpp"}
	links { "valkyr","d3d12","dxgi","d3dcompiler","lua"}

-- should remove mainCRTxxxx as entry point of the generated project, or will face entry error
project "vapp"
	kind "WindowedApp"
	configurations {"Debug","Release"}
	location "../build"
	language "C++"
	files {"../vapp/**.h","../vapp/**.cpp","../vapp/*.rc","../vapp/*.ico"}

project "vtest"
	kind "ConsoleApp"
	configurations {"Debug","Release"}
	location "../build"
	language "C++"
	files {"../vtest/**.h","../vtest/**.cpp"}
	-- links {"valkyr"}



