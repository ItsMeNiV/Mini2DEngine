#pragma once
#include <MiniEngine.h>
#include "Entities/Pacman/Pacman.h"

namespace PacmanGame
{
    enum class CellType
    {
        Empty, Wall, Coin, PowerUp, GhostSpawn, PacmanSpawn, MazeEntrance
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
        Cell* GetGhostSpawnCell();
        void CheckWallCollision(MiniEngine::Ref<MiniEngine::Entity> entity, const glm::vec2& direction);
        void CheckPacmanCoinCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Scene>& scene);
        bool CheckPacmanPowerUpCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Scene>& scene);
        bool CheckGhostCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Entity> ghostEntity);

        std::vector<Cell*> GetCellsByCellType(CellType cellType);
        Cell* GetLevelCellsPtrBase() { return levelCellsPtrBase; }
        uint16_t GetLevelSize() { return levelSize; }

	private:
        Cell* levelCellsPtrBase = nullptr;
        Cell* levelCellsPtr = nullptr;
        const uint16_t levelSize = 30 * 40; //30 * 40 cells at 20px*20px = 800*600
	};
}
