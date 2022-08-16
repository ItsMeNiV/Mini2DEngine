#include "Level.h"
#include "MiniEngine.h"
#include <iostream>
#include <fstream>
#include <vector>

namespace PacmanGame
{
    Level::Level()
    {
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

        for (size_t i = 0; i < bytes.size(); i++) {
            uint8_t x = i % 40;
            uint8_t y = i / 40;
            if (bytes[i] == 'X')
                levelCells[i] = { CellType::Wall, x, y };
            else if (bytes[i] == 'O')
                levelCells[i] = { CellType::Coin, x, y };
            else if (bytes[i] == 'P')
                levelCells[i] = { CellType::PacmanSpawn, x, y };
            else if (bytes[i] == 'G')
                levelCells[i] = { CellType::GhostSpawn, x, y };
            else if (bytes[i] == 'U')
                levelCells[i] = { CellType::PowerUp, x, y };
        }

    }
    void Level::CreateCoinAndPowerupEntities(MiniEngine::Ref<MiniEngine::Scene> scene)
    {
        MiniEngine::Ref<MiniEngine::Texture> coinTexture = MiniEngine::Texture::Create("assets/pictures/coin.png");
        for (Cell c : levelCells)
        {
            if (c.type == CellType::Coin)
                scene->AddEntity(MiniEngine::CreateRef<MiniEngine::Entity>(800 - 20 - c.x * 20.0f, 600 - 20 - c.y * 20.0f, 20.0f, 20.0f, coinTexture));
        }
    }
}
