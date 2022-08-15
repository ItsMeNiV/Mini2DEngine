#include "Pacman.h"
#include "MiniEngine.h"

namespace PacmanGame
{

    Pacman::Pacman(float x, float y) : MiniEngine::Entity(x, y, 20.0f, 20.0f, nullptr)
    {
        this->SetTexture(pacmanTexture);
    }

    void Pacman::OnUpdate(float deltaTime)
    {
        glm::vec2& pos = this->GetPosition();
        pos.x += 100.0f * deltaTime;
    }

}
