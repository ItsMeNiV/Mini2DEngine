IncludeDir = {}
    IncludeDir["GLFW"] =		"%{wks.location}/Mini2DEngine/vendor/GLFW/include"
    IncludeDir["Glad"] =		"%{wks.location}/Mini2DEngine/vendor/Glad/include"
	IncludeDir["glm"] =			"%{wks.location}/Mini2DEngine/vendor/glm"
	IncludeDir["stbimage"] =	"%{wks.location}/Mini2DEngine/vendor/stb_image"

project "Mini2DEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "mepch.h"
	pchsource "src/mepch.cpp"

	files { "src/**.h", "src/**.cpp", "vendor/glm/glm/**.hpp", "vendor/glm/glm/**.inl", "vendor/stb_image/**.h", "vendor/stb_image/**.cpp", }

	defines { "GLFW_INCLUDE_NONE" }

	includedirs { "src", "%{IncludeDir.GLFW}", "%{IncludeDir.Glad}", "%{IncludeDir.glm}", "%{IncludeDir.stbimage}" }

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