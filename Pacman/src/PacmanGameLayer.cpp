#include "PacmanGameLayer.h"
#include "MiniEngine.h"
#include "entities/Pacman/Pacman.h"
#include "Level.h"

namespace PacmanGame
{

    PacmanGameLayer::PacmanGameLayer() : Layer("PacmanGameLayer")
    {
        camera = MiniEngine::CreateRef<MiniEngine::OrthographicCamera>(800, 600);
        scene = MiniEngine::CreateRef<MiniEngine::Scene>(*camera);
        gameLevel = MiniEngine::CreateRef<Level>();
        Cell pacmanSpawnCell = gameLevel->GetPacmanSpawnCell();
        MiniEngine::Ref<MiniEngine::Texture> pacmanTexture = MiniEngine::Texture::Create("assets/pictures/pacman.png");
        pacmanEntity = MiniEngine::CreateRef<Pacman>((pacmanSpawnCell.x * 20) + 10, (pacmanSpawnCell.y * 20) + 10, pacmanTexture);
    }

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
        scene->OnUpdate(deltaTime);

        gameLevel->checkPacmanWallCollision(pacmanEntity);
        gameLevel->checkPacmanCoinCollision(pacmanEntity, scene);
        gameLevel->checkPacmanPowerUpCollision(pacmanEntity, scene);

        MiniEngine::Renderer2D::DrawScene(*scene);
    }

}