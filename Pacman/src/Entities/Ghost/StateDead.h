#pragma once
#include "Entities/Ghost/StateGhost.h"

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
            context->SetSpeed(150.0f);
        }

        virtual void ExitActions()
        {
            Ghost* context = ((Ghost*)GetContext());
            context->SetTexture(context->GetNormalTexture());
            context->SetSpeed(100.0f);

            Cell* ghostSpawnCell = ((Ghost*)GetContext())->GetLevelRef()->GetGhostSpawnCell();
            glm::vec2& pos = ((Ghost*)GetContext())->GetPosition();
            pos.x = (ghostSpawnCell->x * 20.0f) + 10;
            pos.y = (ghostSpawnCell->y * 20.0f) + 10;
        }

        virtual void OnUpdate(float deltaTime)
        {
            Ghost* context = ((Ghost*)GetContext());
            context->UpdatePathTo(context->GetLevelRef()->GetCellsByCellType(CellType::MazeEntrance)[0]);

            int posX = context->GetPosition().x - 10;
            int posY = context->GetPosition().y - 10;
            Cell& myCurrentCell = context->GetLevelRef()->GetLevelCellsPtrBase()[40 * ((int)posY / 20) + (int)posX / 20];
            if (myCurrentCell.type == CellType::MazeEntrance)
                context->Reset();
        }

    };
}