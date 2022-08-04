#pragma once
#include "MiniEngine/Core/Window.h"
#include <GLFW/glfw3.h>

namespace MiniEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const char* title, unsigned int width, unsigned int height);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return width; }
		inline unsigned int GetHeight() const override { return height; }
	
	private:
		unsigned int width, height;
		const char* title;

		GLFWwindow* window;
	};
}