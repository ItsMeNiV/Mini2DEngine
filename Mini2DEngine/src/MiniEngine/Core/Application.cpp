#include "mepch.h"
#include "Application.h"

#include "MiniEngine/Event/WindowEvents.h"

#include "MiniEngine/Rendering/Renderer2D.h"

#include "MiniEngine/Utils/PlatformUtils.h"

namespace MiniEngine
{
	Application* Application::app = nullptr;

	Application::Application(AppDefinitions& appDef)
	{
		window = std::unique_ptr<Window>(Window::Create(appDef.appName, appDef.windowWidth, appDef.windowHeight));

		window->SetEventCallback([this](Event& e) { OnEvent(e); });

		Renderer2D::Init();

		app = this;
	}

	Application::~Application()
	{
		Renderer2D::Shutdown();
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
			WindowResizeEvent& e = static_cast<WindowResizeEvent&>(event);
			Renderer2D::OnWindowResize(e.GetWidth(), e.GetHeight());
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