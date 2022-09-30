#pragma once
#include "Entities/Ghost/Ghost.h"
#include "Entities/Ghost/StateScatter.h"

namespace PacmanGame
{
	class BlinkyGhost : public Ghost
	{
	public:
		BlinkyGhost(float x, float y, MiniEngine::Ref<Level> levelRef) : Ghost("Blinky", x, y, MiniEngine::Texture::Create("assets/pictures/blinky.png"), levelRef, new StateScatter(6000)) {}

		virtual Cell* GetTargetCell()
		{
			return GetPacmanCell();
		}
		virtual Cell* GetTargetScatterCell()
		{
			return &GetLevelRef()->GetLevelCellsPtrBase()[1158];
		}

	private:

	};
}