#include "mepch.h"
#include "Application.h"

namespace MiniEngine
{
	Application::Application(AppDefinitions& appDef)
	{
		window = std::unique_ptr<Window>(Window::Create(appDef.appName, appDef.windowWidth, appDef.windowHeight));

		window->SetEventCallback([this](Event& e) { OnEvent(e); });
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
	void Application::OnEvent(Event& event)
	{
		if (event.GetEventCategory() == EventCategory::WindowCloseEventCategory)
		{
			running = false;
		}
	}
}