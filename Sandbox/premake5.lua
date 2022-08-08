project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin/int/" .. outputdir .. "/%{prj.name}")

	files { "src/**.h", "src/**.cpp" }

	includedirs { "%{wks.location}/Mini2DEngine/src", "%{wks.location}/Mini2DEngine/vendor" }

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