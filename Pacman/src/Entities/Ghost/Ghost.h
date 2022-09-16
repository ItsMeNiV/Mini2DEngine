#pragma once
#include <MiniEngine.h>
#include "Entities/Ghost/StateGhost.h"
#include "Level.h"

namespace PacmanGame
{
	class Ghost : public MiniEngine::Entity, public MiniEngine::StatefulContext
	{
	public:
		Ghost(std::string&& name, float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture, MiniEngine::Ref<Level> levelRef);
		virtual ~Ghost() = default;

		virtual StateGhost* GetState() { return (StateGhost*)state.get(); }
		void SetPacmanPos(const glm::vec2& pacmanPos) { this->pacmanPos = pacmanPos; }
		MiniEngine::Ref<Level> GetLevelRef() const { return levelRef; }
		const glm::vec2& GetDirection() { return direction; }
		virtual Cell* GetTargetCell() = 0; //Override in each specific Ghost-Implementation
		virtual Cell* GetTargetScatterCell() = 0; //Override in each specific Ghost-Implementation
		MiniEngine::Ref<MiniEngine::Texture> GetNormalTexture() { return normalTexture; }
		MiniEngine::Ref<MiniEngine::Texture> GetDeadTexture() { return deadTexture; }
		MiniEngine::Ref<MiniEngine::Texture> GetFleeingTexture() { return fleeingTexture; }
		void SetSpeed(float speed) { this->speed = speed; }

		void Reset(float x, float y);

		virtual void OnUpdate(float deltaTime);
		virtual void OnCollision(glm::vec2 wallPos) override;

		Cell* GetPacmanCell();
		void UpdatePathTo(Cell* cellTo);

		//State Events
		void StartHunting();
		void StartScattering();
		void StartFleeing();
		void ReturnToSpawn();

	private:
		MiniEngine::Ref<MiniEngine::Texture> normalTexture;
		MiniEngine::Ref<MiniEngine::Texture> deadTexture;
		MiniEngine::Ref<MiniEngine::Texture> fleeingTexture;
		MiniEngine::Ref<Level> levelRef;
		float speed = 100.0f;
		glm::vec2 direction;
		glm::vec2 pacmanPos;
		std::vector<Cell> currentPath;
	};
}
