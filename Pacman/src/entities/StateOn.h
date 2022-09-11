#pragma once
#include "MiniEngine.h"
#include "StatePacman.h"

namespace PacmanGame
{
    class StateOn : public StatePacman
    {
    public:
        StateOn() : StatePacman("StateOn") {}

        virtual void EntryActions() { std::cout << "Entering StateOn" << std::endl; }
        virtual void ExitActions() { std::cout << "Exiting StateOn" << std::endl; }

        virtual bool Off()
        {
            ((Pacman*)GetContext())->OnToOff();
            return true;
        }
    };
}