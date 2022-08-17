#include "Pacman.h"
#include "MiniEngine.h"

namespace PacmanGame
{

	Pacman::Pacman(float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture) : MiniEngine::Entity("Pacman", x, y, 20.0f, 20.0f, texture),
		direction(0.0f, 0.0f), prevDirection(0.0f, 0.0f) {}

	void Pacman::OnUpdate(float deltaTime)
	{
		justChangedDirection = false;
		//Pacman Controls
		if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::W) && direction != glm::vec2(0.0f, 1.0f))
		{
			prevDirection = direction;
			direction = { 0.0f, 1.0f };
			justChangedDirection = true;
		}
		else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::A) && direction != glm::vec2(-1.0f, 0.0f))
		{
			prevDirection = direction;
			direction = { -1.0f, 0.0f };
			justChangedDirection = true;
		}
		else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::S) && direction != glm::vec2(0.0f, -1.0f))
		{
			prevDirection = direction;
			direction = { 0.0f, -1.0f };
			justChangedDirection = true;
		}
		else if (MiniEngine::Input::IsKeyPressed(MiniEngine::Key::D) && direction != glm::vec2(1.0f, 0.0f))
		{
			prevDirection = direction;
			direction = { 1.0f, 0.0f };
			justChangedDirection = true;
		}

		glm::vec2& pos = this->GetPosition();
		float step = speed * deltaTime;
		pos += direction * step;
	}

	void Pacman::OnWallCollision(glm::vec2 wallPos)
	{
		if (justChangedDirection)
		{
			direction = prevDirection;
		}
		glm::vec2& pos = this->GetPosition();
		pos = wallPos - 20.0f * direction;
	}

}
