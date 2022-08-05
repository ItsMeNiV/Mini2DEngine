#include "mepch.h"
#include "WindowsWindow.h"

#include "MiniEngine/Event/WindowEvents.h"

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
		data.title = title;
		data.width = width;
		data.height = height;

		if (!IsGLFWInitialized)
		{
			if (glfwInit())
			{
				IsGLFWInitialized = true;
			}
		}
		window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		glfwSwapInterval(1);

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
		{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.eventCallback(event);
		});
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
