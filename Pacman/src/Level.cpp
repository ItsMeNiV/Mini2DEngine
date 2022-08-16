#include "Level.h"
#include "MiniEngine.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <format>

namespace PacmanGame
{
    Level::Level()
    {
        levelCellsPtrBase = new Cell[30 * 40]; //30 * 40 cells at 20px*20px = 800*600
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
                *levelCellsPtr = { CellType::Wall, x, y };
            else if (*i == 'O')
                *levelCellsPtr = { CellType::Coin, x, y };
            else if (*i == 'P')
                *levelCellsPtr = { CellType::PacmanSpawn, x, y };
            else if (*i == 'G')
                *levelCellsPtr = { CellType::GhostSpawn, x, y };
            else if (*i == 'U')
                *levelCellsPtr = { CellType::PowerUp, x, y };

            levelCellsPtr++;
            index++;
        }

    }

    void Level::CreateCoinAndPowerupEntities(MiniEngine::Ref<MiniEngine::Scene>& scene)
    {
        MiniEngine::Ref<MiniEngine::Texture> coinTexture = MiniEngine::Texture::Create("assets/pictures/coin.png");
        for (uint16_t i = 0; i <= 30*40; i++)
        {
            Cell c = levelCellsPtrBase[i];
            if (c.type == CellType::Coin)
            {
                MiniEngine::Ref<MiniEngine::Entity> coin = MiniEngine::CreateRef<MiniEngine::Entity>(std::string("Coin") + std::to_string(i), c.x * 20.0f, c.y * 20.0f, 20.0f, 20.0f, coinTexture);
                scene->AddEntity(coin);
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
}
