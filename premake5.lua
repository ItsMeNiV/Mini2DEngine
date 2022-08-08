workspace "Mini2DEngine"
	architecture "x64"

	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Mini2DEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "Mini2DEngine/vendor/Glad/include"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	includedirs { "Mini2DEngine/src", "Mini2DEngine/vendor" }

	links { "Mini2DEngine" }

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines { "ME_PLATFORM_WINDOWS" }

		filter "configurations:Debug"
		defines "ME_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ME_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ME_DIST"
		runtime "Release"
		optimize "on"

include "Mini2DEngine/vendor/GLFW"
include "Mini2DEngine/vendor/Glad"

project "Mini2DEngine"
	location "Mini2DEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "mepch.h"
	pchsource "Mini2DEngine/src/mepch.cpp"

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	defines { "GLFW_INCLUDE_NONE" }

	includedirs { "%{prj.name}/src", "%{IncludeDir.GLFW}", "%{IncludeDir.Glad}" }

	links { "Glad", "GLFW", "opengl32.lib" }

	filter "system:windows"
		systemversion "latest"

		defines { "ME_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines "ME_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ME_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ME_DIST"
		runtime "Release"
		optimize "on"