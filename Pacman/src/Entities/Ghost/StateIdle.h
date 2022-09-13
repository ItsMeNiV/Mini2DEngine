#pragma once
#include "StateGhost.h"

namespace PacmanGame
{
	class StateIdle : public StateGhost
	{
	public:
		StateIdle() : StateGhost("StateIdle") {}

		virtual void EntryActions() { return; }
		virtual void ExitActions() { return; }
	};
}