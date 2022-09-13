#pragma once
#include "StateGhost.h"

namespace PacmanGame
{
	class StateFleeing : public StateGhost
	{
	public:
		StateFleeing() : StateGhost("StateFleeing") {}

		virtual void EntryActions() { return; }
		virtual void ExitActions() { return; }
	};
}