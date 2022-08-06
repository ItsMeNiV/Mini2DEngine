#include <MiniEngine.h>

class Sandbox : public MiniEngine::Layer
{
public:
	Sandbox() : Layer("Sandbox layer") {};
	virtual ~Sandbox() = default;

	virtual void OnAttach() override
	{
		std::cout << "Layer attached" << std::endl;
	}

	virtual void OnDetach() override
	{
		std::cout << "Layer detached" << std::endl;
	}

	void OnUpdate(float deltaTime) override
	{
		//std::cout << "Sandbox Layer updated with deltaTime: " << deltaTime << std::endl;
	}
};


class SandboxApp : public MiniEngine::Application
{
public:
	SandboxApp(MiniEngine::AppDefinitions& appDef) : Application(appDef)
	{
		this->PushLayer(new Sandbox());
	}

	~SandboxApp()
	{

	}
};

MiniEngine::Application* MiniEngine::CreateApplication()
{
	AppDefinitions appDef;
	appDef.appName = "Sandbox";
	appDef.windowHeight = 720;
	appDef.windowWidth = 1280;
	return new SandboxApp(appDef);
}