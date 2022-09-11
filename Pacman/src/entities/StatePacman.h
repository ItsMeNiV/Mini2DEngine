#pragma once
#include "MiniEngine.h"

namespace PacmanGame
{
    class Pacman;

    class StatePacman : public MiniEngine::StateBase
    {
    public:
        StatePacman(std::string&& name) : StateBase(std::move(name)) {}

        virtual bool On() { return false; }
        virtual bool Off() { return false; }

        Pacman* GetMyContext()
        {
            return (Pacman*)GetContext();
        }
    };
}