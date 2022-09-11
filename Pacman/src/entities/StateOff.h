#pragma once
#include "MiniEngine.h"
#include "StatePacman.h"

namespace PacmanGame
{
    class StateOff : public StatePacman
    {
    public:
        StateOff() : StatePacman("StateOff") {}

        virtual void EntryActions() { std::cout << "Entering StateOff" << std::endl; }
        virtual void ExitActions() { std::cout << "Exiting StateOff" << std::endl; }

        virtual bool On()
        {
            ((Pacman*)GetContext())->OffToOn();
            return true;
        }
    };
}