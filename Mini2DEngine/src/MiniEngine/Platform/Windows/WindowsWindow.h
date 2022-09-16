#pragma once
#include "GLFW/glfw3.h"
#include "MiniEngine/Core/Window.h"
#include "MiniEngine/Rendering/GraphicsContext.h"
#include "MiniEngine/Rendering/OrthographicCamera.h"

namespace MiniEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const char* title, unsigned int width, unsigned int height, bool resizable);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return data.width; }
		inline unsigned int GetHeight() const override { return data.height; }
		inline void* GetNativeWindow() const { return window; }

		void SetEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }
	
	private:
		GLFWwindow* window;
		Scope<GraphicsContext> context;

		struct WindowData
		{
			unsigned int width, height = 0;
			const char* title;

			EventCallbackFn eventCallback;
		};
		WindowData data;
	};
}