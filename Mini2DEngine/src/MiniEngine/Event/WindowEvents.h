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
		WindowResizeEvent(int width, int height) : Event(EventCategory::WindowResizeEventCategory)
		{
			this->width = width;
			this->height = height;
		}
		~WindowResizeEvent() {};

		int GetWidth() { return width; }
		int GetHeight() { return height; }

	private:
		int width, height;
	};
}