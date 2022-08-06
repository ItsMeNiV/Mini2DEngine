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

		inline unsigned int GetWidth() const override { return data.width; }
		inline unsigned int GetHeight() const override { return data.height; }
		inline void* GetNativeWindow() const { return window; }
		void Resize(WindowResizeEvent& resizeEvent);

		void SetEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }
	
	private:
		GLFWwindow* window;

		struct WindowData
		{
			unsigned int width, height;
			const char* title;

			EventCallbackFn eventCallback;
		};
		WindowData data;
	};
}