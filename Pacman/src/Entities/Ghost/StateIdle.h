#pragma once
#include "Entities/Ghost/StateGhost.h"

namespace PacmanGame
{
	class StateIdle : public StateGhost
	{
	public:
		StateIdle(uint16_t idleTimeMs) : StateGhost("StateIdle"), timer(idleTimeMs, timerOver) {}

		virtual void EntryActions()
		{ 
			timer.StartTimer();
		}

		virtual void ExitActions() //Move from Spawn field to maze (TODO: Think of another solution instead of teleporting)
		{
            Cell* mazeEntranceCell = ((Ghost*)GetContext())->GetLevelRef()->GetCellsByCellType(CellType::MazeEntrance)[0];
            glm::vec2& pos = ((Ghost*)GetContext())->GetPosition();
            pos.x = (mazeEntranceCell->x * 20.0f) + 10;
            pos.y = (mazeEntranceCell->y * 20.0f) + 10;
		}

		virtual void OnUpdate(float deltaTime)
		{
			if (timerOver)
			{
                ((Ghost*)GetContext())->StartScattering();
                timerOver = false;
			}
		}

	private:
		MiniEngine::Timer timer;
		std::atomic_bool timerOver = false;
	};
}