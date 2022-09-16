#pragma once
#include <MiniEngine.h>
#include "Entities/Pacman/StatePacman.h"

namespace PacmanGame
{
    class StatePoweredUp : public StatePacman
    {
    public:
        StatePoweredUp() : StatePacman("StatePoweredUp"), timer(6000, timerOver) {}

        virtual void EntryActions() { timer.StartTimer();  }
        virtual void ExitActions()  { timer.CancelTimer(); }

        virtual bool PowerUpCollected()
        {
            timer.RestartTimer();
            return true;
        }

        virtual void OnUpdate()
        {
            if (timerOver)
            {
                ((Pacman*)GetContext())->PoweredUpToNormal();
                timerOver = false;
            }
        }

    private:
        MiniEngine::Timer timer;
        std::atomic_bool timerOver;

    };
}