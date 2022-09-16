#include "mepch.h"
#include "MiniEngine/Platform/Windows/WindowsWindow.h"

#include "GLFW/glfw3.h"
#include "MiniEngine/Event/WindowEvents.h"
#include "MiniEngine/Event/KeyEvents.h"

namespace MiniEngine
{

	static bool IsGLFWInitialized = false;

	Window* Window::Create(const char* title, unsigned int width, unsigned int height, bool resizable)
	{
		return new WindowsWindow(title, width, height, resizable);
	}

	WindowsWindow::WindowsWindow(const char* title, unsigned int width, unsigned int height, bool resizable)
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
		//TODO Set resizable
		window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		context = GraphicsContext::Create(window);
		context->Init();

		glfwSetWindowUserPointer(window, &data);
		glfwSwapInterval(1);

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.eventCallback(event);
			});

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;
				WindowResizeEvent event(width, height);
				data.eventCallback(event);
			});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int modifiers)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				if (action == GLFW_PRESS)
				{
					KeyPressedEvent event(key);
					data.eventCallback(event);
				}
				else if (action == GLFW_RELEASE)
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
				}

			});
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		context->SwapBuffers();
	}
}
