#pragma once
#include "MiniEngine/Event/Event.h"

namespace MiniEngine
{

	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int keyCode) : Event(EventCategory::KeyPressedEventCategory) { this->keyCode = keyCode; }
		~KeyPressedEvent() {};

		int GetKeyCode() { return keyCode; }

	private:
		int keyCode;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int keyCode) : Event(EventCategory::KeyReleasedEventCategory) { this->keyCode = keyCode; }
		~KeyReleasedEvent() {};

		int GetKeyCode() { return keyCode; }

	private:
		int keyCode;
	};

}