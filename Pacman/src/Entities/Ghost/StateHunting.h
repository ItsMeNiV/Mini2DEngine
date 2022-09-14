#pragma once
#include "StateGhost.h"
#include "../../Pathfinding/Pathfinder.h"

namespace PacmanGame
{
	class StateHunting : public StateGhost
	{
	public:
		StateHunting() : StateGhost("StateHunting") {}

		virtual void EntryActions() //Move from Spawn field to maze (TODO: Think of another solution instead of teleporting)
		{
			Cell* mazeEntranceCell = ((Ghost*)GetContext())->GetLevelRef()->GetCellsByCellType(CellType::MazeEntrance)[0];
			glm::vec2& pos = ((Ghost*)GetContext())->GetPosition();
			pos.x = (mazeEntranceCell->x * 20.0f) + 10;
			pos.y = (mazeEntranceCell->y * 20.0f) + 10;
		}

		virtual void OnUpdate(float deltaTime)
		{
			Ghost* context = ((Ghost*)GetContext());
			context->UpdatePathTo(context->GetTargetCell());
		}

		virtual void ExitActions() { return; }
	};
}