#include "mepch.h"
#include "Application.h"

namespace MiniEngine
{
	Application::Application(AppDefinitions& appDef)
	{
		window = std::unique_ptr<Window>(Window::Create(appDef.appName, appDef.windowWidth, appDef.windowHeight));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Hello from the engine" << std::endl;
		while (running)
		{
			window->OnUpdate();
		}
	}
}