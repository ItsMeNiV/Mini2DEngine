#pragma once
#include "Entities/Ghost/Ghost.h"
#include "Entities/Ghost/StateIdle.h"

namespace PacmanGame
{
	class PinkyGhost : public Ghost
	{
	public:
		PinkyGhost(float x, float y, MiniEngine::Ref<Level> levelRef) : Ghost("Pinky", x, y, MiniEngine::Texture::Create("assets/pictures/pinky.png"), levelRef, new StateIdle(500)) {}

		virtual Cell* GetTargetCell()
		{
			uint8_t targetX = GetPacmanCell()->x + (4 * GetPacmanDirection().x);
			uint8_t targetY = GetPacmanCell()->y + (4 * GetPacmanDirection().y);
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
			return &GetLevelRef()->GetLevelCellsPtrBase()[1121];
		}

	private:

	};
}