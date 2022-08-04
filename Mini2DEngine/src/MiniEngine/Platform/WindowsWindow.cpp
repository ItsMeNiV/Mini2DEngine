#include "mepch.h"
#include "WindowsWindow.h"

#include <GLFW/glfw3.h>

namespace MiniEngine
{

	static bool IsGLFWInitialized = false;

	Window* Window::Create(const char* title, unsigned int width, unsigned int height)
	{
		return new WindowsWindow(title, width, height);
	}

	WindowsWindow::WindowsWindow(const char* title, unsigned int width, unsigned int height)
	{
		this->title = title;
		this->width = width;
		this->height = height;

		if (!IsGLFWInitialized)
		{
			if (glfwInit())
			{
				IsGLFWInitialized = true;
			}
		}
		window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
