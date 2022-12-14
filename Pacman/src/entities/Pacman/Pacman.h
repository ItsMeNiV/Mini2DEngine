#pragma once
#include <MiniEngine.h>
#include "Entities/Pacman/StatePacman.h"

namespace PacmanGame
{

    class Pacman : public MiniEngine::Entity, public MiniEngine::StatefulContext
    {
    public:
        Pacman(float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture);

        virtual void OnUpdate(float deltaTime);
        virtual void OnCollision(glm::vec2 wallPos) override;
        const glm::vec2& GetDirection() { return direction; }
        virtual StatePacman* GetState() { return (StatePacman*)state.get(); }
        void RemoveLife() { lives--; }
        uint8_t GetLives() const { return lives; }
        void Reset(float x, float y);

        //State-related Events
        void PowerUpCollected();

        //State-Changes
        void NormalToPoweredUp();
        void PoweredUpToNormal();

    private:
        uint8_t lives;
        const float speed = 100.0f;
        glm::vec2 direction;
        glm::vec2 prevDirection;
        MiniEngine::KeyCode bufferedInput;
        float prevRotation;
        bool justChangedDirection = false;
        uint8_t inputBufferTimer;
    };
}