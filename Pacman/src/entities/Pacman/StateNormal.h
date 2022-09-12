#pragma once
#include "MiniEngine.h"
#include "StatePacman.h"

namespace PacmanGame
{
    class StateNormal : public StatePacman
    {
    public:
        StateNormal() : StatePacman("StateNormal") {}

        virtual void EntryActions() { return; }
        virtual void ExitActions() { return; }

        virtual bool PowerUpCollected()
        {
            ((Pacman*)GetContext())->NormalToPoweredUp();
            return false;
        }

        virtual void OnUpdate()
        {
            std::cout << "Normal update" << std::endl;
        }
    };
}