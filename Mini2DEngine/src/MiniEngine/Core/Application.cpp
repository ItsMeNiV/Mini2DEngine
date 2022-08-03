#include "mepch.h"
#include "Application.h"

namespace MiniEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Hello from the engine" << std::endl;
		while (true);
	}
}