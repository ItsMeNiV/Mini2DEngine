#include "Entities/Ghost/Ghost.h"

#include <cmath>
#include "Entities/Ghost/StateIdle.h"
#include "Entities/Ghost/StateHunting.h"
#include "Entities/Ghost/StateScatter.h"
#include "Entities/Ghost/StateFleeing.h"
#include "Entities/Ghost/StateDead.h"
#include "Pathfinding/Pathfinder.h"

namespace PacmanGame
{
	Ghost::Ghost(std::string&& name, float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture, MiniEngine::Ref<Level> levelRef, StateGhost* initialState)
		: MiniEngine::Entity(std::move(name), x, y, 20.0f, 20.0f, 0.0f, false, texture), normalTexture(texture), deadTexture(MiniEngine::Texture::Create("assets/pictures/ghost_dead.png")),
		fleeingTexture(MiniEngine::Texture::Create("assets/pictures/ghost_fleeing.png")), direction(0.0f, 0.0f), levelRef(levelRef), pacmanPos({}), spawnCell(&(levelRef->GetLevelCellsPtrBase()[40 * ((int)y / 20) + (int)x / 20]))
	{
		if (!initialState)
			initialState = new StateIdle(3000);
		SetState(*initialState);
		initialState->SetContext(this);
		initialState->EntryActions();
	}

	void Ghost::Reset()
	{
        glm::vec2& pos = this->GetPosition();
        pos.x = (GetSpawnCell()->x * 20) + 10;
        pos.y = (GetSpawnCell()->y * 20) + 10;
		direction = { 0.0f, 0.0f };
		ChangeState(new StateIdle(3000));
	}

	void Ghost::OnUpdate(float deltaTime)
	{
		GetState()->OnUpdate(deltaTime);

		int posX = GetPosition().x - 10;
		int posY = GetPosition().y - 10;
		Cell& myCurrentCell = levelRef->GetLevelCellsPtrBase()[40 * ((int)posY / 20) + (int)posX / 20];
		if(currentPath.size() >= 2 && posX % 20 == 0 && posY % 20 == 0)
		{
			direction.x = currentPath[1].x - currentPath[0].x;
			direction.y = currentPath[1].y - currentPath[0].y;
		}

		if (direction.x == -1)
			SetFlipHorizontal(true);
		else
			SetFlipHorizontal(false);

		glm::vec2& pos = this->GetPosition();
		float step = speed * deltaTime;
		pos += direction * step;

		float modX = fmod(pos.x - 10, 20.0f);
		float modY = fmod(pos.y - 10, 20.0f);
		if (modX != 0 && modX <= 0.1f && modX >= -0.1f)
			pos.x += modX * (direction.x * -1);
		if (modY != 0 && modY <= 0.1f && modY >= -0.1f)
			pos.y += modY * direction.y;
	}

	void Ghost::StartHunting()
	{
		ChangeState(new StateHunting());
	}

	void Ghost::StartScattering()
	{
		ChangeState(new StateScatter(6000));
	}

	void Ghost::StartFleeing()
	{
		ChangeState(new StateFleeing(6000));
	}

	void Ghost::ReturnToSpawn()
	{
		ChangeState(new StateDead());
	}

	Cell* Ghost::GetPacmanCell()
	{
		uint16_t cellX = (uint16_t)(pacmanPos.x - 10.0f) / 20;
		uint16_t cellY = (uint16_t)(pacmanPos.y - 10.0f) / 20;
		return &levelRef.get()->GetLevelCellsPtrBase()[cellY * 40 + cellX];
	}

	glm::vec2& Ghost::GetPacmanDirection()
	{
		return pacmanDir;
	}

	void Ghost::UpdatePathTo(Cell* cellTo)
	{
		Cell* cellFrom = &levelRef->GetLevelCellsPtrBase()[40 * ((int)GetPosition().y / 20) + (int)GetPosition().x / 20];
		std::vector<Cell> pathBuffer;
		Pathfinder::GetInstance().CalculatePath(cellFrom, cellTo, pathBuffer);
		currentPath = pathBuffer;
	}

	void Ghost::OnCollision(glm::vec2 wallPos)
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
	}
}
