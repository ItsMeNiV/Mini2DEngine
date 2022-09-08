#include "Pacman.h"
#include "MiniEngine.h"

namespace PacmanGame
{

	Pacman::Pacman(float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture) : MiniEngine::Entity("Pacman", x, y, 20.0f, 20.0f, 0.0f, texture),
		direction(0.0f, 0.0f), prevDirection(0.0f, 0.0f), bufferedInput(MiniEngine::Key::SPACE) {}

	void Pacman::OnUpdate(float deltaTime)
	{
		int posX = GetPosition().x - 10;
		int posY = GetPosition().y - 10;
		justChangedDirection = false;
		//Pacman Controls
		if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::W) || bufferedInput == MiniEngine::Key::W && direction != glm::vec2(0.0f, 1.0f))
		{
			if (posX % 20 == 0)
			{
				prevDirection = direction;
				direction = { 0.0f, 1.0f };
				prevRotation = GetRotation();
				SetRotation(90.0f);
				justChangedDirection = true;
				bufferedInput = MiniEngine::Key::SPACE;
			}
			else if (bufferedInput != MiniEngine::Key::W)
				bufferedInput = MiniEngine::Key::W;
		}
		else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::A) || bufferedInput == MiniEngine::Key::A && direction != glm::vec2(-1.0f, 0.0f))
		{
			if (posY % 20 == 0)
			{
				prevDirection = direction;
				direction = { -1.0f, 0.0f };
				prevRotation = GetRotation();
				SetRotation(180.0f);
				justChangedDirection = true;
				bufferedInput = MiniEngine::Key::SPACE;
			}
			else if (bufferedInput != MiniEngine::Key::A)
				bufferedInput = MiniEngine::Key::A;
		}
		else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::S) || bufferedInput == MiniEngine::Key::S && direction != glm::vec2(0.0f, -1.0f))
		{
			if (posX % 20 == 0)
			{
				prevDirection = direction;
				direction = { 0.0f, -1.0f };
				prevRotation = GetRotation();
				SetRotation(270.0f);
				justChangedDirection = true;
				bufferedInput = MiniEngine::Key::SPACE;
			}
			else if (bufferedInput != MiniEngine::Key::S)
				bufferedInput = MiniEngine::Key::S;
		}
		else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::D) || bufferedInput == MiniEngine::Key::D && direction != glm::vec2(1.0f, 0.0f))
		{
			if (posY % 20 == 0)
			{
				prevDirection = direction;
				direction = { 1.0f, 0.0f };
				prevRotation = GetRotation();
				SetRotation(0.0f);
				justChangedDirection = true;
				bufferedInput = MiniEngine::Key::SPACE;
			}
			else if (bufferedInput != MiniEngine::Key::D)
				bufferedInput = MiniEngine::Key::D;
		}

		glm::vec2& pos = this->GetPosition();
		float step = speed * deltaTime;
		pos += direction * step;
	}

	void Pacman::OnWallCollision(glm::vec2 wallPos)
	{
		glm::vec2& pos = this->GetPosition();

		if (direction == glm::vec2(0.0f, 1.0f)) // Up
			pos.y = wallPos.y - 20.0f;
        if (direction == glm::vec2(-1.0f, 0.0f)) // Left
            pos.x = wallPos.x + 20.0f;
        if (direction == glm::vec2(0.0f, -1.0f)) // Down
            pos.y = wallPos.y + 20.0f;
		if (direction == glm::vec2(1.0f, 0.0f)) // Right
			pos.x = wallPos.x - 20.0;

        if (justChangedDirection)
        {
            direction = prevDirection;
			SetRotation(prevRotation);
        }
	}

}
