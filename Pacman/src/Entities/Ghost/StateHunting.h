#pragma once
#include "StateGhost.h"
#include "../../Pathfinding/Pathfinder.h"

namespace PacmanGame
{
	class StateHunting : public StateGhost
	{
	public:
		StateHunting() : StateGhost("StateHunting") {}

		virtual void EntryActions() { return; }

		virtual void OnUpdate(float deltaTime)
		{
			Ghost* context = ((Ghost*)GetContext());
			context->UpdatePathTo(context->GetTargetCell());
		}

		virtual void ExitActions() { return; }
	};
}