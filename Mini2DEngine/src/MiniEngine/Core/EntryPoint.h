#pragma once
#include "MiniEngine/Core/Application.h"

#ifdef ME_PLATFORM_WINDOWS

extern MiniEngine::Application* MiniEngine::CreateApplication();

int main(int argc, char** argv)
{
	MiniEngine::Application* app = MiniEngine::CreateApplication();

	app->Run();

	delete app;
}

#endif // ME_PLATFORM_WINDOWS