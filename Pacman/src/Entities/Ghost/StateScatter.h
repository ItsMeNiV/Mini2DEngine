#pragma once
#include "Entities/Ghost/StateGhost.h"

namespace PacmanGame
{
	class StateScatter : public StateGhost
	{
	public:
		StateScatter(uint16_t scatterTimeMs, bool useScatterTexture) : StateGhost("StateScatter"), timer(scatterTimeMs, timerOver), useScatterTexture(useScatterTexture) {}

        virtual void EntryActions()
        {
            Ghost* context = ((Ghost*)GetContext());
            if(useScatterTexture)
                context->SetTexture(context->GetScatterTexture());
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
        bool useScatterTexture;
        MiniEngine::Timer timer;
        std::atomic_bool timerOver = false;
	};
}