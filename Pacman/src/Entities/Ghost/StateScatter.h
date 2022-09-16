#pragma once
#include "Entities/Ghost/StateGhost.h"

namespace PacmanGame
{
	class StateScatter : public StateGhost
	{
	public:
		StateScatter(uint16_t scatterTimeMs) : StateGhost("StateScatter"), timer(scatterTimeMs, timerOver) {}

        virtual void EntryActions()
        {
            Ghost* context = ((Ghost*)GetContext());
            timer.StartTimer();
        }

		virtual void ExitActions()
        {
            Ghost* context = ((Ghost*)GetContext());
            context->SetTexture(context->GetNormalTexture());
            timer.CancelTimer();
        }

        virtual void OnUpdate(float deltaTime)
        {
            Ghost* context = ((Ghost*)GetContext());
            context->UpdatePathTo(context->GetTargetScatterCell());

            if (timerOver)
            {
                ((Ghost*)GetContext())->StartHunting();
                timerOver = false;
            }
        }

	private:
        MiniEngine::Timer timer;
        std::atomic_bool timerOver = false;
	};
}