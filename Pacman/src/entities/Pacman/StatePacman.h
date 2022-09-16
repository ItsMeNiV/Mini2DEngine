#pragma once
#include <MiniEngine.h>
#include "Entities/Pacman/Pacman.h"

namespace PacmanGame
{
    class Pacman;

    class StatePacman : public MiniEngine::StateBase
    {
    public:
        StatePacman(std::string&& name) : StateBase(std::move(name)) {}

        virtual bool PowerUpCollected() { return false; }

        virtual void OnUpdate() { return; }
    };
}