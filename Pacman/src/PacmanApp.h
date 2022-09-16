#pragma once
#include <MiniEngine.h>

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