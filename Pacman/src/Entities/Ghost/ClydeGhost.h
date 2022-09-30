#pragma once
#include <cmath>

#include "Entities/Ghost/Ghost.h"
#include "Entities/Ghost/StateIdle.h"

namespace PacmanGame
{
	class ClydeGhost : public Ghost
	{
	public:
		ClydeGhost(float x, float y, MiniEngine::Ref<Level> levelRef) : Ghost("Clyde", x, y, MiniEngine::Texture::Create("assets/pictures/clyde.png"), levelRef, new StateIdle(10000)) {}

		virtual Cell* GetTargetCell()
		{
			Cell* targetCell = GetPacmanCell();
			float distance = abs(sqrt(pow(GetPacmanCell()->x - GetPosition().x, 2) + pow(GetPacmanCell()->y - GetPosition().y, 2)));

			if (distance < 40)
				targetCell = GetTargetScatterCell();

			return targetCell;
		}
		virtual Cell* GetTargetScatterCell()
		{
			return &GetLevelRef()->GetLevelCellsPtrBase()[41];
		}

	private:

	};
}