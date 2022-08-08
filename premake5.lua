workspace "Mini2DEngine"
	architecture "x64"

	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Sandbox"

group "Dependencies"
	include "Mini2DEngine/vendor/GLFW"
	include "Mini2DEngine/vendor/Glad"
group ""

include "Mini2DEngine"