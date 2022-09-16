#pragma once
#include <MiniEngine.h>

namespace PacmanGame
{
	class StateGhost : public MiniEngine::StateBase
	{
	public:
		StateGhost(std::string&& name) : StateBase(std::move(name)) {}

		virtual void OnUpdate(float deltaTime) { return; }
	};
}