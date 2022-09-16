#include "PacmanGameLayer.h"

#include "Entities/Ghost/BlinkyGhost.h"
#include "Entities/Ghost/StateDead.h"
#include "Entities/Pacman/StatePoweredUp.h"
#include "Pathfinding/Pathfinder.h"

namespace PacmanGame
{

    PacmanGameLayer::PacmanGameLayer()
        : Layer("PacmanGameLayer"), camera(MiniEngine::CreateRef<MiniEngine::OrthographicCamera>(800, 600)), scene(MiniEngine::CreateRef<MiniEngine::Scene>(*camera)),
        gameLevel(MiniEngine::CreateRef<Level>()),
        pacmanEntity(MiniEngine::CreateRef<Pacman>((gameLevel->GetPacmanSpawnCell().x * 20) + 10, (gameLevel->GetPacmanSpawnCell().y * 20) + 10, MiniEngine::Texture::Create("assets/pictures/pacman.png"))),
        gameWon(false), gameLost(false)
    {
        Pathfinder::GetInstance().Init(gameLevel->GetLevelCellsPtrBase(), gameLevel->GetLevelSize());
        ghostEntities.push_back(MiniEngine::CreateRef<BlinkyGhost>((gameLevel->GetGhostSpawnCell()->x * 20) + 10, (gameLevel->GetGhostSpawnCell()->y * 20) + 10, gameLevel));
    }

    void PacmanGameLayer::OnAttach()
    {
        MiniEngine::Ref<MiniEngine::Texture> backgroundTexture = MiniEngine::Texture::Create("assets/pictures/background.png");
        MiniEngine::Ref<MiniEngine::Entity> background = MiniEngine::CreateRef<MiniEngine::Entity>(std::string("background"), 400.0f, 300.0f, 800.0f, 600.0f, 0.0f, false, backgroundTexture);
        scene->AddEntity(background);
        gameLevel->CreateCoinAndPowerupEntities(scene);
        scene->AddEntity(pacmanEntity);
        for (MiniEngine::Ref<Ghost> g : ghostEntities)
            scene->AddEntity(g);

    }
    
    void PacmanGameLayer::OnDetach()
    {

    }

    void PacmanGameLayer::OnUpdate(float deltaTime)
    {
        if (!gameWon && !gameLost)
        {
            scene->OnUpdate(deltaTime);
            gameLevel->CheckWallCollision(pacmanEntity, pacmanEntity->GetDirection());
            gameLevel->CheckPacmanCoinCollision(pacmanEntity, scene);
            if (gameLevel->CheckPacmanPowerUpCollision(pacmanEntity, scene))
            {
                for (MiniEngine::Ref<Ghost> g : ghostEntities)
                    g->StartFleeing();
            }

            for (MiniEngine::Ref<Ghost> g : ghostEntities)
            {
                g->SetPacmanPos(pacmanEntity->GetPosition());
                gameLevel->CheckWallCollision(g, g->GetDirection());
                if (gameLevel->CheckGhostCollision(pacmanEntity, g) && dynamic_cast<StateDead*>(g->GetState()) == nullptr)
                {
                    if (dynamic_cast<StatePoweredUp*>(pacmanEntity->GetState()) != nullptr)
                    {
                        g->ReturnToSpawn();
                    }
                    else
                    {
                        pacmanEntity->RemoveLife();
                        std::cout << std::to_string(pacmanEntity->GetLives()) << " Lives left" << std::endl;
                        if (pacmanEntity->GetLives() == 0)
                        {
                            gameLost = true;
                            std::cout << "You Lost!" << std::endl;
                            break;
                        }
                        ResetGame();
                    }
                }

            }

            CheckWin();
        }
        MiniEngine::Renderer2D::DrawScene(*scene);
    }

    void PacmanGameLayer::ResetGame()
    {
        pacmanEntity->Reset((gameLevel->GetPacmanSpawnCell().x * 20) + 10, (gameLevel->GetPacmanSpawnCell().y * 20) + 10);
        for (MiniEngine::Ref<Ghost> g : ghostEntities)
            g->Reset((gameLevel->GetGhostSpawnCell()->x * 20) + 10, (gameLevel->GetGhostSpawnCell()->y * 20) + 10);
    }

    void PacmanGameLayer::CheckWin()
    {
        std::vector<Cell*> coinCells = gameLevel->GetCellsByCellType(CellType::Coin);
        std::vector<Cell*> powerUpCells = gameLevel->GetCellsByCellType(CellType::PowerUp);

        if (coinCells.size() == 0 && powerUpCells.size() == 0)
        {
            gameWon = true;
            std::cout << "You won!" << std::endl;
        }
    }

}