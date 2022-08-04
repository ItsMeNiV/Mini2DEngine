#include "mepch.h"
#include "Application.h"

namespace MiniEngine
{
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
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