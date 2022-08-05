#pragma once

#include "Core.h"
#include <MiniEngine/Core/Window.h>

namespace MiniEngine
{
	struct AppDefinitions
	{
		const char* appName;
		unsigned int windowWidth;
		unsigned int windowHeight;
	};

	class ME_API Application
	{
	public:
		Application(AppDefinitions& appDef);
		virtual ~Application();

		void Run();
		void OnEvent(Event& event);

	private:
		bool running = true;
		std::unique_ptr<Window> window;
	};

	Application* CreateApplication();
}