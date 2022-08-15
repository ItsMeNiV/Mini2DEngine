#include "MiniEngine.h"
#include "MiniEngine/Core/EntryPoint.h"
#include "PacmanGameLayer.h"

namespace PacmanGame
{
    class PacmanApp : public MiniEngine::Application
    {
    public:
        PacmanApp(MiniEngine::AppDefinitions& appDef) : Application(appDef)
        {
            this->PushLayer(new PacmanGameLayer());
        }

        ~PacmanApp()
        {

        }
    };
}

MiniEngine::Application* MiniEngine::CreateApplication()
{
    AppDefinitions appDef{ "Pacman", 800, 600, false };
    return new PacmanGame::PacmanApp(appDef);
}