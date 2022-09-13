#include "PacmanGameLayer.h"
#include "MiniEngine.h"
#include "entities/Pacman/Pacman.h"
#include "Level.h"

namespace PacmanGame
{

    PacmanGameLayer::PacmanGameLayer()
        : Layer("PacmanGameLayer"), camera(MiniEngine::CreateRef<MiniEngine::OrthographicCamera>(800, 600)), scene(MiniEngine::CreateRef<MiniEngine::Scene>(*camera)),
        gameLevel(MiniEngine::CreateRef<Level>()),
        pacmanEntity(MiniEngine::CreateRef<Pacman>((gameLevel->GetPacmanSpawnCell().x * 20) + 10, (gameLevel->GetPacmanSpawnCell().y * 20) + 10, MiniEngine::Texture::Create("assets/pictures/pacman.png"))),
        gameWon(false) {}

    void PacmanGameLayer::OnAttach()
    {
        MiniEngine::Ref<MiniEngine::Texture> backgroundTexture = MiniEngine::Texture::Create("assets/pictures/background.png");
        MiniEngine::Ref<MiniEngine::Entity> background = MiniEngine::CreateRef<MiniEngine::Entity>(std::string("background"), 400.0f, 300.0f, 800.0f, 600.0f, 0.0f, backgroundTexture);
        scene->AddEntity(background);
        gameLevel->CreateCoinAndPowerupEntities(scene);
        scene->AddEntity(pacmanEntity);
    }
    
    void PacmanGameLayer::OnDetach()
    {

    }

    void PacmanGameLayer::OnUpdate(float deltaTime)
    {
        if (!gameWon)
        {
            scene->OnUpdate(deltaTime);

            gameLevel->checkPacmanWallCollision(pacmanEntity);
            gameLevel->checkPacmanCoinCollision(pacmanEntity, scene);
            gameLevel->checkPacmanPowerUpCollision(pacmanEntity, scene);

            CheckWin();
        }
        MiniEngine::Renderer2D::DrawScene(*scene);
    }

    void PacmanGameLayer::CheckWin()
    {
        std::vector<Cell*> coinCells = gameLevel->GetCellsByCellType(CellType::Coin);
        std::vector<Cell*> powerUpCells = gameLevel->GetCellsByCellType(CellType::PowerUp);

        if (coinCells.size() == 0 && powerUpCells.size() == 0)
        {
            gameWon = true;
        }
    }

}