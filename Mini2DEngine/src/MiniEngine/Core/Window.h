#pragma once
#include "mepch.h"

#include "MiniEngine/Core/Core.h"
#include <MiniEngine/Event/Event.h>
#include <MiniEngine/Event/WindowEvents.h>

namespace MiniEngine
{
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		static Window* Create(const char* windowTitle = "MiniEngine", unsigned int width = 1280, unsigned int height = 720);

	};
}
