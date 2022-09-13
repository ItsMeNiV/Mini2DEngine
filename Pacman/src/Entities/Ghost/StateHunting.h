#pragma once
#include "StateGhost.h"

namespace PacmanGame
{
	class StateHunting : public StateGhost
	{
	public:
		StateHunting() : StateGhost("StateHunting") {}

		virtual void EntryActions() { return; }
		virtual void ExitActions() { return; }
	};
}