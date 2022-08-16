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
        MiniEngine::Ref<MiniEngine::Entity> background = MiniEngine::CreateRef<MiniEngine::Entity>(0.0f, 0.0f, 800.0f, 600.0f, backgroundTexture);
        scene->AddEntity(background);
        gameLevel->CreateCoinAndPowerupEntities(scene);
        scene->AddEntity(MiniEngine::CreateRef<Pacman>(380.0f, 140.0f));
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