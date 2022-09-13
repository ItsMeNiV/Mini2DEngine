#pragma once
#include "MiniEngine.h"
#include "StateGhost.h"

namespace PacmanGame
{
	class Ghost : public MiniEngine::Entity, public MiniEngine::StatefulContext
	{
	public:
		Ghost(std::string&& name, float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture);
		virtual ~Ghost() = default;

		virtual StateGhost* GetState() { return (StateGhost*)state.get(); }

	private:
		const float speed = 100.0f;
		glm::vec2 direction;
	};
}