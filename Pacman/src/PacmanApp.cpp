#include "PacmanApp.h"

#include <MiniEngine/Core/EntryPoint.h>

MiniEngine::Application* MiniEngine::CreateApplication()
{
    AppDefinitions appDef{ "Pacman", 800, 600, false };
    return new PacmanGame::PacmanApp(appDef);
}