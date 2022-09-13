#include "Pacman.h"
#include "MiniEngine.h"
#include "StateNormal.h"
#include "StatePoweredUp.h"

namespace PacmanGame
{

	Pacman::Pacman(float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture)
		: MiniEngine::Entity("Pacman", x, y, 20.0f, 20.0f, 0.0f, texture), direction(0.0f, 0.0f), prevDirection(0.0f, 0.0f), prevRotation(0.0f), bufferedInput(MiniEngine::Key::SPACE), inputBufferTimer(0)
	{
		StatePacman* initialState = new StateNormal();
		SetState(*initialState);
		initialState->SetContext(*this);
		initialState->EntryActions();
	}

	void Pacman::OnUpdate(float deltaTime)
	{
		if (bufferedInput != MiniEngine::Key::SPACE)
		{
			if (++inputBufferTimer == 100)
			{
				bufferedInput = MiniEngine::Key::SPACE;
				inputBufferTimer = 0;
			}
		}

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
				inputBufferTimer = 0;
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
				inputBufferTimer = 0;
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
				inputBufferTimer = 0;
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
				inputBufferTimer = 0;
			}
			else if (bufferedInput != MiniEngine::Key::D)
				bufferedInput = MiniEngine::Key::D;
		}

		glm::vec2& pos = this->GetPosition();
		float step = speed * deltaTime;
		pos += direction * step;

		if ((int)pos.x - 10 % 20 != 0 && (int)pos.x - 10 % 20 <= 0.1)
			pos.x = (int)pos.x + (int)pos.x % 20;
		if ((int)pos.y - 10 % 20 != 0 && (int)pos.y - 10 % 20 <= 0.1)
			pos.y = (int)pos.y + (int)pos.y % 20;

		GetState()->OnUpdate();
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

	void Pacman::PowerUpCollected()
	{
		GetState()->PowerUpCollected();
	}

	void Pacman::NormalToPoweredUp()
	{
		ChangeState(new StatePoweredUp());
	}

	void Pacman::PoweredUpToNormal()
	{
		ChangeState(new StateNormal());
	}

}
