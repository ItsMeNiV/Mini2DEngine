#pragma once
#include <MiniEngine.h>
#include "entities/Pacman/Pacman.h"

namespace PacmanGame
{
    enum class CellType
    {
        Empty, Wall, Coin, PowerUp, GhostSpawn, PacmanSpawn
    };
    struct Cell
    {
        std::string id;
        CellType type;
        uint8_t x, y;
    };

	class Level
	{
	public:
		Level();

        void CreateCoinAndPowerupEntities(MiniEngine::Ref<MiniEngine::Scene>& scene);
        Cell GetPacmanSpawnCell();
        void checkPacmanWallCollision(MiniEngine::Ref<Pacman> pacmanEntity);
        void checkPacmanCoinCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Scene>& scene);
        void checkPacmanPowerUpCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Scene>& scene);

	private:
        Cell* levelCellsPtrBase = nullptr;
        Cell* levelCellsPtr = nullptr;
	};
}
