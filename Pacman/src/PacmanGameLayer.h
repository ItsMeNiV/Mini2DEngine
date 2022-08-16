#pragma once
#include "MiniEngine.h"
#include "Level.h"

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

    private:
        MiniEngine::Ref<MiniEngine::OrthographicCamera> camera;
        MiniEngine::Ref<MiniEngine::Scene> scene;
        MiniEngine::Ref<Level> gameLevel;
    };
}