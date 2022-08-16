#include "Pacman.h"
#include "MiniEngine.h"

namespace PacmanGame
{

    Pacman::Pacman(float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture) : MiniEngine::Entity(std::string("Pacman"), x, y, 20.0f, 20.0f, texture),
        direction(0.0f, 0.0f) {}

    void Pacman::OnUpdate(float deltaTime)
    {
        //Pacman Controls
        if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::W))
            direction = { 0.0f, 1.0f };
        else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::A))
            direction = { -1.0f, 0.0f };
        else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::S))
            direction = { 0.0f, -1.0f };
        else if(MiniEngine::Input::IsKeyPressed(MiniEngine::Key::D))
            direction = { 1.0f, 0.0f };

        glm::vec2& pos = this->GetPosition();
        float step = speed * deltaTime;
        pos += direction * step;
    }

}
