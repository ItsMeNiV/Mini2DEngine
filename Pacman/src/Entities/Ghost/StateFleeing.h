#pragma once
#include <cstdlib>
#include "Entities/Ghost/StateGhost.h"

namespace PacmanGame
{
    class StateFleeing : public StateGhost
    {
    public:
        StateFleeing(uint16_t fleeingTimeMs) : StateGhost("StateFleeing"), timer(fleeingTimeMs, timerOver) {}

        virtual void EntryActions()
        {
            Ghost* context = ((Ghost*)GetContext());
            context->SetTexture(context->GetFleeingTexture());

            context->UpdatePathTo(GetRandomNonWallCell());

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
            uint16_t ghostX = (uint16_t)context->GetPosition().x / 20;
            uint16_t ghostY = (uint16_t)context->GetPosition().y / 20;
            Cell* currentCell = &context->GetLevelRef()->GetLevelCellsPtrBase()[ghostY * 40 + ghostX];
            if (currentCell->id == context->GetTargetCell()->id)
            {
                context->UpdatePathTo(GetRandomNonWallCell());
            }

            if (timerOver)
            {
                context->StartHunting();
                timerOver = false;
            }
        }

        Cell* GetRandomNonWallCell()
        {
            Ghost* context = ((Ghost*)GetContext());
            Cell* returnCell = nullptr;
            do
            {
                uint16_t randNum = std::rand() / ((RAND_MAX + 1u) / context->GetLevelRef()->GetLevelSize());
                returnCell = &context->GetLevelRef()->GetLevelCellsPtrBase()[randNum];
            } while (returnCell->type == CellType::Wall);
            return returnCell;
        }

    private:
        MiniEngine::Timer timer;
        std::atomic_bool timerOver = false;
    };
}