#include "MiniEngine.h"

class Sandbox : public MiniEngine::Application
{
public:
	Sandbox(MiniEngine::AppDefinitions& appDef) : Application(appDef)
	{

	}

	~Sandbox()
	{

	}
};

MiniEngine::Application* MiniEngine::CreateApplication()
{
	AppDefinitions appDef;
	appDef.appName = "Sandbox";
	appDef.windowHeight = 720;
	appDef.windowWidth = 1280;
	return new Sandbox(appDef);
}