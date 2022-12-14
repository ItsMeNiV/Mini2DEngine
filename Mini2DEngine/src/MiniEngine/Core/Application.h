#pragma once
#include "MiniEngine/Core/Core.h"
#include "MiniEngine/Core/Window.h"
#include "MiniEngine/Core/LayerStack.h"

namespace MiniEngine
{
	struct AppDefinitions
	{
		const char* appName;
		unsigned int windowWidth;
		unsigned int windowHeight;
		bool resizable;
	};

	class Application
	{
	public:
		Application(AppDefinitions& appDef);
		virtual ~Application();

		static Application& GetInstance() { return *app; }

		void Run();
		void OnEvent(Event& event);
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		Window& GetWindow() { return *window.get(); }

	private:
		static Application* app;
		bool running = true;
		std::unique_ptr<Window> window;
		LayerStack layerStack;
		float lastFrameTime = 0;
	};

	Application* CreateApplication();
}