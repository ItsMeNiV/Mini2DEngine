#pragma once

namespace MiniEngine
{

	enum EventCategory
	{
		WindowCloseEventCategory, WindowResizeEventCategory,
		KeyPressedEventCategory, KeyReleasedEventCategory
	};

	class Event
	{
	public:
		Event(EventCategory eventCategory) { this->eventCategory = eventCategory; }
		virtual ~Event() = default;

		EventCategory GetEventCategory() { return eventCategory; }

	private:
		EventCategory eventCategory;
	};
}