#pragma once
#include "MiniEngine.h"
#include "StatePacman.h"

namespace PacmanGame
{

    class Pacman : public MiniEngine::Entity, public MiniEngine::StatefulContext
    {
    public:
        Pacman(float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture);

        virtual void OnUpdate(float deltaTime);
        void OnWallCollision(glm::vec2 wallPos);
        const glm::vec2& GetDirection() { return direction; }
        virtual StatePacman* GetState() { return (StatePacman*)state; }

        void OnToOff();
        void OffToOn();

    private:
        const float speed = 100.0f;
        glm::vec2 direction;
        glm::vec2 prevDirection;
        MiniEngine::KeyCode bufferedInput;
        float prevRotation;
        bool justChangedDirection = false;
    };
}