#pragma once
#include "MiniEngine.h"
#include "Level.h"
#include "Entities/Pacman/Pacman.h"
#include "Entities/Ghost/Ghost.h"

namespace PacmanGame
{
    class PacmanGameLayer : public MiniEngine::Layer
    {
    public:
        PacmanGameLayer();
        virtual ~PacmanGameLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        void OnUpdate(float deltaTime);

        void ResetGame();
        void CheckWin();

    private:
        MiniEngine::Ref<MiniEngine::OrthographicCamera> camera;
        MiniEngine::Ref<MiniEngine::Scene> scene;
        MiniEngine::Ref<Level> gameLevel;
        MiniEngine::Ref<Pacman> pacmanEntity;
        std::vector<MiniEngine::Ref<Ghost>> ghostEntities;
        bool gameWon, gameLost;
    };
}