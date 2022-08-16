#pragma once

namespace PacmanGame
{
    enum class CellType
    {
        Empty, Wall, Coin, PowerUp, GhostSpawn, PacmanSpawn
    };
    struct Cell
    {
        CellType type;
    };

	class Level
	{
	public:
		Level();

	private:
		Cell levelCells[30 * 40] = {}; //30 * 40 cells at 20px*20px = 800*600
	};
}
