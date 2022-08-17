#pragma once
#include "MiniEngine.h"

namespace PacmanGame
{

    class Pacman : public MiniEngine::Entity
    {
    public:
        Pacman(float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture);

        virtual void OnUpdate(float deltaTime);
        void OnWallCollision(glm::vec2 wallPos);
        const glm::vec2& GetDirection() { return direction; }

    private:
        const float speed = 100.0f;
        glm::vec2 direction;
        glm::vec2 prevDirection;
        bool justChangedDirection = false;
    };
}