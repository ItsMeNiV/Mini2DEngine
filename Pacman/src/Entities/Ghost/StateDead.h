#pragma once
#include "StateGhost.h"

namespace PacmanGame
{
    class StateDead : public StateGhost
    {
    public:
        StateDead() : StateGhost("StateDead") {}

        virtual void EntryActions()
        {
            Ghost* context = ((Ghost*)GetContext());
            context->SetTexture(context->GetDeadTexture());
            context->SetSpeed(200.0f);
        }

        virtual void ExitActions()
        {
            Ghost* context = ((Ghost*)GetContext());
            context->SetTexture(context->GetNormalTexture());
            context->SetSpeed(100.0f);
        }

        virtual void OnUpdate(float deltaTime)
        {
            Ghost* context = ((Ghost*)GetContext());
            context->UpdatePathTo(context->GetLevelRef()->GetCellsByCellType(CellType::MazeEntrance)[0]);

            int posX = context->GetPosition().x - 10;
            int posY = context->GetPosition().y - 10;
            Cell& myCurrentCell = context->GetLevelRef()->GetLevelCellsPtrBase()[40 * ((int)posY / 20) + (int)posX / 20];
            if (myCurrentCell.type == CellType::MazeEntrance)
                context->Reset((myCurrentCell.x * 20) + 10, (myCurrentCell.y * 20) + 10);
        }

    };
}