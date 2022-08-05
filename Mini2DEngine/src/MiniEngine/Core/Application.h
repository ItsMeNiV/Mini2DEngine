#pragma once

#include "Core.h"
#include <MiniEngine/Core/Window.h>

namespace MiniEngine
{
	class ME_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		bool running = true;
		std::unique_ptr<Window> window;
	};

	Application* CreateApplication();
}