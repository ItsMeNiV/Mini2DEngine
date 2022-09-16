#include "mepch.h"
#include "MiniEngine/Utils/PlatformUtils.h"

#include "GLFW/glfw3.h"

namespace MiniEngine
{
	float Time::GetTime()
	{
		return glfwGetTime();
	}
}