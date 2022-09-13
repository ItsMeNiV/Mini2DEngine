#pragma once
#include "Ghost.h"

namespace PacmanGame
{
	class BlinkyGhost : public Ghost
	{
	public:
		BlinkyGhost(float x, float y) : Ghost("Blinky", x, y, MiniEngine::Texture::Create("assets/pictures/blinky.png")) {}

	private:

	};
}