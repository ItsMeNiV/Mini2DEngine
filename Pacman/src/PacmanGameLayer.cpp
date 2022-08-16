#include "PacmanGameLayer.h"
#include "MiniEngine.h"
#include "entities/Pacman.h"
#include "Level.h"

namespace PacmanGame
{

    PacmanGameLayer::PacmanGameLayer() : Layer("PacmanGameLayer")
    {
        camera = MiniEngine::CreateRef<MiniEngine::OrthographicCamera>(800, 600);
        scene = MiniEngine::CreateRef<MiniEngine::Scene>(*camera);
        gameLevel = MiniEngine::CreateRef<Level>();
    }

    void PacmanGameLayer::OnAttach()
    {
        MiniEngine::Ref<MiniEngine::Texture> backgroundTexture = MiniEngine::Texture::Create("assets/pictures/background.png");
        MiniEngine::Ref<MiniEngine::Entity> background = MiniEngine::CreateRef<MiniEngine::Entity>(std::string("background"), 0.0f, 0.0f, 800.0f, 600.0f, backgroundTexture);
        scene->AddEntity(background);
        gameLevel->CreateCoinAndPowerupEntities(scene);
        Cell& pacmanSpawnCell = gameLevel->GetPacmanSpawnCell();
        scene->AddEntity(MiniEngine::CreateRef<Pacman>(800 - 20 - pacmanSpawnCell.x, 600 - 20 - pacmanSpawnCell.y));
    }
    
    void PacmanGameLayer::OnDetach()
    {

    }

    void PacmanGameLayer::OnUpdate(float deltaTime)
    {
        scene->OnUpdate(deltaTime);

        MiniEngine::Renderer2D::DrawScene(*scene);
    }

}