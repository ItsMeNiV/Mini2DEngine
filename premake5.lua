workspace "Mini2DEngine"
	architecture "x64"

	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Sandbox"
include "Pacman"

group "Dependencies"
	include "Mini2DEngine/vendor/GLFW"
	include "Mini2DEngine/vendor/Glad"
	include "Mini2DEngine/vendor/box2d"
group ""

include "Mini2DEngine"