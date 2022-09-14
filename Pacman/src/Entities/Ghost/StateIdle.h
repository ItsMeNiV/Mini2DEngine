#pragma once
#include "StateGhost.h"

namespace PacmanGame
{
	class StateIdle : public StateGhost
	{
	public:
		StateIdle(uint16_t idleTimeMs) : StateGhost("StateIdle"), timer(idleTimeMs, timerOver) {}

		virtual void EntryActions() { timer.StartTimer(); }
		virtual void ExitActions() { timer.CancelTimer(); }

		virtual void OnUpdate(float deltaTime)
		{
			if (timerOver)
			{
				((Ghost*)GetContext())->StartHunting();
				timerOver = false;
			}
		}

	private:
		MiniEngine::Timer timer;
		std::atomic_bool timerOver = false;
	};
}