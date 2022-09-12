#pragma once
#include "MiniEngine.h"
#include "StatePacman.h"

namespace PacmanGame
{
    class StatePoweredUp : public StatePacman
    {
    public:
        StatePoweredUp() : StatePacman("StatePoweredUp"), timer(6000, std::bind(&StatePoweredUp::timerElapsed, this)) {}

        virtual void EntryActions() { timer.StartTimer(); }
        virtual void ExitActions() { timer.CancelTimer(); }

        virtual bool PowerUpCollected()
        {
            return false;
        }

        virtual void OnUpdate()
        {
            std::cout << "PoweredUp update" << std::endl;
        }

    private:
        MiniEngine::Timer timer;

        void timerElapsed()
        {
            ((Pacman*)GetContext())->PoweredUpToNormal();
        }
    };
}