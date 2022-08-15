#pragma once
#include "MiniEngine.h"

namespace PacmanGame
{
    class Pacman : public MiniEngine::Entity
    {
    public:
        Pacman(float x, float y);

        virtual void OnUpdate(float deltaTime);

    private:
        MiniEngine::Ref<MiniEngine::Texture> pacmanTexture = MiniEngine::Texture::Create("assets/pictures/pacman.png");
    };
}