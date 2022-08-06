#include "mepch.h"
#include "Application.h"

#include "MiniEngine/Event/WindowEvents.h"

#include "MiniEngine/Utils/PlatformUtils.h"

namespace MiniEngine
{
	Application* Application::app = nullptr;

	Application::Application(AppDefinitions& appDef)
	{
		window = std::unique_ptr<Window>(Window::Create(appDef.appName, appDef.windowWidth, appDef.windowHeight));

		window->SetEventCallback([this](Event& e) { OnEvent(e); });

		app = this;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Hello from the engine" << std::endl;
		while (running)
		{
			float time = Time::GetTime();
			float deltaTime = time - lastFrameTime;
			lastFrameTime = time;

			for (Layer* layer : layerStack)
			{
				layer->OnUpdate(deltaTime);
			}
			window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& event)
	{
		if (event.GetEventCategory() == EventCategory::WindowCloseEventCategory)
		{
			running = false;
		}
		else if (event.GetEventCategory() == EventCategory::WindowResizeEventCategory)
		{
			std::cout << "Resizing window.." << std::endl;
		}
	}
	void Application::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
	}

	void Application::PopLayer(Layer* layer)
	{
		layerStack.PopLayer(layer);
	}
}