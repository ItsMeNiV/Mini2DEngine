#include "mepch.h"
#include "MiniEngine/Core/Input.h"

#include "MiniEngine/Core/Application.h"
#include "GLFW/glfw3.h"

namespace MiniEngine
{
	bool Input::IsKeyPressed(KeyCode keyCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		return glfwGetKey(window, keyCode) == GLFW_PRESS;
	}
}