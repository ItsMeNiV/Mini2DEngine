workspace "Mini2DEngine"
	architecture "x64"

	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Mini2DEngine/vendor/GLFW/include"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	includedirs { "Mini2DEngine/src", "Mini2DEngine/vendor" }

	links { "Mini2DEngine" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "ME_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines "ME_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ME_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		optimize "On"

include "Mini2DEngine/vendor/GLFW"

project "Mini2DEngine"
	location "Mini2DEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "mepch.h"
	pchsource "Mini2DEngine/src/mepch.cpp"

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	defines { "GLFW_INCLUDE_NONE" }

	includedirs { "%{prj.name}/src", "%{IncludeDir.GLFW}" }

	links { "GLFW", "opengl32.lib" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "ME_PLATFORM_WINDOWS", "ME_BUILD_DLL" }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ME_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ME_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		optimize "On"