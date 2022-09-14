#pragma once
#include "mepch.h"
#include <future>
#include <ctime>

namespace MiniEngine
{
	class Timer
	{
	public:
		Timer(uint32_t delayMs, std::atomic_bool& timerOver) : delayTime(delayMs), isRunning(false), timerOver(timerOver) {}
		~Timer() { CancelTimer(); }

		void StartTimer()
		{
			isRunning.store(true, std::memory_order_release);
			startTime = clock();
			timerFuture = std::async(std::launch::async, RunTimer, &startTime, delayTime, &isRunning, &timerOver);
		}
		void CancelTimer()
		{
			isRunning.store(false, std::memory_order_release);
		}
		void RestartTimer()
		{
			startTime = clock();
		}

		bool IsRunning() { return isRunning; }

	private:
		std::atomic_bool isRunning;
		std::atomic_bool& timerOver;
		uint32_t delayTime;
		clock_t startTime;

		std::future<void> timerFuture;

		static void RunTimer(clock_t* startTime, uint32_t delay, std::atomic<bool>* isRunning, std::atomic<bool>* timerOver)
		{
			while (clock() - *startTime < delay && isRunning->load(std::memory_order_acquire));

			isRunning->store(false, std::memory_order_release);
			if(clock() - *startTime < delay)
				std::cout << "Timer was cancelled!" << std::endl;
			else
				timerOver->store(true, std::memory_order_release);
		}

	};
}