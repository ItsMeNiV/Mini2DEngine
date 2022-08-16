#include "Level.h"
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
            if (bytes[i] == 'X')
                levelCells[i] = { CellType::Wall };
            else if (bytes[i] == 'O')
                levelCells[i] = { CellType::Coin };
            else if (bytes[i] == 'P')
                levelCells[i] = { CellType::PacmanSpawn };
            else if (bytes[i] == 'G')
                levelCells[i] = { CellType::GhostSpawn };
            else if (bytes[i] == 'U')
                levelCells[i] = { CellType::PowerUp };
        }
    }
}
