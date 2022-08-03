#include "MiniEngine.h"

class Sandbox : public MiniEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

MiniEngine::Application* MiniEngine::CreateApplication()
{
	return new Sandbox();
}