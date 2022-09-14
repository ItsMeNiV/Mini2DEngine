#include "Level.h"
#include "MiniEngine.h"
#include <iostream>
#include <fstream>
#include <vector>

namespace PacmanGame
{
    Level::Level()
    {
        levelCellsPtrBase = new Cell[levelSize];
        levelCellsPtr = levelCellsPtrBase;
        std::string filename("assets/level.txt");
        std::vector<char> bytes;
        char byte = 0;

        std::ifstream input_file(filename);
        if (!input_file.is_open()) {
            std::cerr << "Could not open the file - '"
                << filename << "'" << std::endl;
        }

        while (input_file.get(byte)) {
            if (byte != '\n')
                bytes.push_back(byte);
        }
        input_file.close();

        uint16_t index = 0;
        for (std::vector<char>::reverse_iterator i = bytes.rbegin(); i != bytes.rend(); ++i)
        {
            uint8_t x = index % 40;
            uint8_t y = index / 40;
            if (*i == 'X')
                *levelCellsPtr = { "W" + std::to_string(index), CellType::Wall, x, y};
            else if (*i == 'O')
                *levelCellsPtr = { "C" + std::to_string(index), CellType::Coin, x, y };
            else if (*i == 'P')
                *levelCellsPtr = { "PS" + std::to_string(index), CellType::PacmanSpawn, x, y };
            else if (*i == 'G')
                *levelCellsPtr = { "GS" + std::to_string(index), CellType::GhostSpawn, x, y };
            else if (*i == 'U')
                *levelCellsPtr = { "PU" + std::to_string(index), CellType::PowerUp, x, y };
            else if (*i == 'M')
                *levelCellsPtr = { "M" + std::to_string(index), CellType::MazeEntrance, x, y };

            levelCellsPtr++;
            index++;
        }
    }

    void Level::CreateCoinAndPowerupEntities(MiniEngine::Ref<MiniEngine::Scene>& scene)
    {
        MiniEngine::Ref<MiniEngine::Texture> coinTexture = MiniEngine::Texture::Create("assets/pictures/coin.png");
        MiniEngine::Ref<MiniEngine::Texture> powerUpTexture = MiniEngine::Texture::Create("assets/pictures/powerup.png");
        for (uint16_t i = 0; i <= 30*40; i++)
        {
            Cell& c = levelCellsPtrBase[i];
            if (c.type == CellType::Coin)
            {
                MiniEngine::Ref<MiniEngine::Entity> coin = MiniEngine::CreateRef<MiniEngine::Entity>(std::string("Coin") + std::to_string(i), c.x * 20.0f + 10.0f, c.y * 20.0f + 10.0f, 20.0f, 20.0f, 0.0f, false, coinTexture);
                scene->AddEntity(coin);
                c.id = coin->GetEntityId();
            }
            if (c.type == CellType::PowerUp)
            {
                MiniEngine::Ref<MiniEngine::Entity> powerUp = MiniEngine::CreateRef<MiniEngine::Entity>(std::string("PowerUp") + std::to_string(i), c.x * 20.0f + 10.0f, c.y * 20.0f + 10.0f, 20.0f, 20.0f, 0.0f, false, powerUpTexture);
                scene->AddEntity(powerUp);
                c.id = powerUp->GetEntityId();
            }
        }
    }

    Cell Level::GetPacmanSpawnCell()
    {
        for (uint16_t i = 0; i <= 30*40; i++)
        {
            Cell c = levelCellsPtrBase[i];

            if (c.type == CellType::PacmanSpawn)
                return c;
        }
        return *levelCellsPtrBase;
    }

    Cell* Level::GetGhostSpawnCell()
    {
        for (uint16_t i = 0; i <= levelSize; i++)
        {
            Cell& c = levelCellsPtrBase[i];

            if (c.type == CellType::GhostSpawn)
                return &c;
        }
        return levelCellsPtrBase;
    }

    void Level::CheckWallCollision(MiniEngine::Ref<MiniEngine::Entity> entity, const glm::vec2& direction)
    {
        uint16_t cellX = (uint16_t)(entity->GetPosition().x - 10.0f) / 20;
        uint16_t cellY = (uint16_t)(entity->GetPosition().y - 10.0f) / 20;

        if (direction == glm::vec2(0.0f, 1.0f)) // Up
            cellY += 1;
        else if (direction == glm::vec2(1.0f, 0.0f)) // Right
            cellX += 1;

        Cell collisionCheckCell = levelCellsPtrBase[cellY * 40 + cellX];

        if (collisionCheckCell.type == CellType::Wall)
            entity->OnCollision({ collisionCheckCell.x * 20.0f + 10.0f, collisionCheckCell.y * 20.0f + 10.0f });

    }

    void Level::CheckPacmanCoinCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Scene>& scene)
    {
        uint16_t cellX = (uint16_t)pacmanEntity->GetPosition().x / 20;
        uint16_t cellY = (uint16_t)pacmanEntity->GetPosition().y / 20;

        Cell& collisionCheckCell = levelCellsPtrBase[cellY * 40 + cellX];

        if (collisionCheckCell.type == CellType::Coin)
        {
            collisionCheckCell.type = CellType::Empty;
            
            scene->RemoveEntity(collisionCheckCell.id);
        }
    }

    bool Level::CheckPacmanPowerUpCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Scene>& scene)
    {
        uint16_t cellX = (uint16_t)pacmanEntity->GetPosition().x / 20;
        uint16_t cellY = (uint16_t)pacmanEntity->GetPosition().y / 20;

        Cell& collisionCheckCell = levelCellsPtrBase[cellY * 40 + cellX];

        if (collisionCheckCell.type == CellType::PowerUp)
        {
            collisionCheckCell.type = CellType::Empty;
            scene->RemoveEntity(collisionCheckCell.id);
            pacmanEntity->PowerUpCollected();
            return true;
        }
        return false;
    }

    bool Level::CheckGhostCollision(MiniEngine::Ref<Pacman> pacmanEntity, MiniEngine::Ref<MiniEngine::Entity> ghostEntity)
    {
        uint16_t pacmanX = (uint16_t)pacmanEntity->GetPosition().x / 20;
        uint16_t pacmanY = (uint16_t)pacmanEntity->GetPosition().y / 20;
        uint16_t ghostX = (uint16_t)ghostEntity->GetPosition().x / 20;
        uint16_t ghostY = (uint16_t)ghostEntity->GetPosition().y / 20;

        Cell& pacmanCell = levelCellsPtrBase[pacmanY * 40 + pacmanX];
        Cell& ghostCell = levelCellsPtrBase[ghostY * 40 + ghostX];

        return pacmanCell.id == ghostCell.id;
    }

    std::vector<Cell*> Level::GetCellsByCellType(CellType cellType)
    {
        std::vector<Cell*> returnVector;
        for (uint16_t i = 0; i <= levelSize; i++)
        {
            Cell& c = levelCellsPtrBase[i];
            if (c.type == cellType)
            {
                returnVector.push_back(&c);
            }
        }
        return returnVector;
    }
}
