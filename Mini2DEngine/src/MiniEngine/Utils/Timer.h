#pragma once
#include "mepch.h"
#include <future>
#include <ctime>

namespace MiniEngine
{
	class Timer
	{
	public:
		Timer(uint32_t delayMs, std::function<void()> callbackFn) : delayTime(delayMs), isRunning(false), callback(callbackFn) {}
		~Timer()
		{
			isRunning.store(false, std::memory_order_release);
		}

		void StartTimer()
		{
			isRunning.store(true, std::memory_order_release);
			timerFuture = std::async(std::launch::async, RunTimer, delayTime, &isRunning, callback);
		}
		void CancelTimer()
		{
			isRunning.store(false, std::memory_order_release);
			isRunning = false;
		}

		bool IsRunning() { return isRunning; }

	private:
		std::atomic<bool> isRunning;
		uint32_t delayTime;
		std::function<void()> callback;

		std::future<void> timerFuture;

		static void RunTimer(uint32_t delay, std::atomic<bool>* isRunning, std::function<void()> callback)
		{
			clock_t now = clock();

			while (clock() - now < delay && isRunning->load(std::memory_order_acquire));

			if(clock() - now >= delay) //Otherwise timer was cancelled
				callback();
			else
				std::cout << "Timer was cancelled!" << std::endl;

			isRunning->store(false, std::memory_order_release);
		}

	};
}