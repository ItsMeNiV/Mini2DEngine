#pragma once
#include <MiniEngine.h>

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

	private:
        Cell* levelCellsPtrBase = nullptr;
        Cell* levelCellsPtr = nullptr;
	};
}
