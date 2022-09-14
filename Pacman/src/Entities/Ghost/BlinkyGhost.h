#pragma once
#include "Ghost.h"

namespace PacmanGame
{
	class BlinkyGhost : public Ghost
	{
	public:
		BlinkyGhost(float x, float y, MiniEngine::Ref<Level> levelRef) : Ghost("Blinky", x, y, MiniEngine::Texture::Create("assets/pictures/blinky.png"), MiniEngine::Texture::Create("assets/pictures/ghost_dead.png"), levelRef) {}

		virtual Cell* GetTargetCell()
		{
			return GetPacmanCell();
		}
		virtual Cell* GetTargetScatterCell()
		{
			return &GetLevelRef()->GetLevelCellsPtrBase()[78];
		}

	private:

	};
}