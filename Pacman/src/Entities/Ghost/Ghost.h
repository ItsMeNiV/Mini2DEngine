#pragma once
#include "MiniEngine.h"
#include "StateGhost.h"
#include "../../Level.h"

namespace PacmanGame
{
	class Ghost : public MiniEngine::Entity, public MiniEngine::StatefulContext
	{
	public:
		Ghost(std::string&& name, float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture, MiniEngine::Ref<Level> levelRef);
		virtual ~Ghost() = default;

		virtual StateGhost* GetState() { return (StateGhost*)state.get(); }

	private:
		MiniEngine::Ref<Level> levelRef;
		const float speed = 100.0f;
		glm::vec2 direction;
	};
}
