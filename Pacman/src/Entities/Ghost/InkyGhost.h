#pragma once
#include "Entities/Ghost/Ghost.h"
#include "Entities/Ghost/StateIdle.h"

namespace PacmanGame
{
	class InkyGhost : public Ghost
	{
	public:
		InkyGhost(float x, float y, MiniEngine::Ref<Level> levelRef) : Ghost("Inky", x, y, MiniEngine::Texture::Create("assets/pictures/inky.png"), levelRef, new StateIdle(5000)) {}

		virtual Cell* GetTargetCell()
		{
			uint8_t targetX = GetPacmanCell()->x + (3 * GetPacmanDirection().x) + 2;
			uint8_t targetY = GetPacmanCell()->y + (3 * GetPacmanDirection().y) + 2;
			Cell* targetCell = &GetLevelRef()->GetLevelCellsPtrBase()[40 * targetY + targetX];
			while (targetCell->type == CellType::Wall || targetCell->type == CellType::GhostSpawn)
			{
				if (targetX != GetPacmanCell()->x)
					targetX--;
				if (targetY != GetPacmanCell()->y)
					targetY--;
				targetCell = &(GetLevelRef()->GetLevelCellsPtrBase()[40 * targetY + targetX]);
			}

			return targetCell;
		}
		virtual Cell* GetTargetScatterCell()
		{
			return &GetLevelRef()->GetLevelCellsPtrBase()[78];
		}

	private:

	};
}