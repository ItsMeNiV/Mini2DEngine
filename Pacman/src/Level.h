#pragma once
#include <MiniEngine.h>
#include "entities/Pacman.h"

namespace PacmanGame
{
    enum class CellType
    {
        Empty, Wall, Coin, PowerUp, GhostSpawn, PacmanSpawn
    };
    struct Cell
    {
        CellType type;
        uint8_t x, y;
    };

	class Level
	{
	public:
		Level();

        void CreateCoinAndPowerupEntities(MiniEngine::Ref<MiniEngine::Scene>& scene);
        Cell GetPacmanSpawnCell();
        void checkPacmanWallCollision(MiniEngine::Ref<Pacman> pacman);

	private:
        Cell* levelCellsPtrBase = nullptr;
        Cell* levelCellsPtr = nullptr;
	};
}
