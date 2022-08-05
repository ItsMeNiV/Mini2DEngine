#pragma once
#include "Event.h"

namespace MiniEngine
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() : Event(EventCategory::WindowCloseEventCategory) {}
		~WindowCloseEvent() {};
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent() : Event(EventCategory::WindowResizeEventCategory) {}
		~WindowResizeEvent() {};
	};
}