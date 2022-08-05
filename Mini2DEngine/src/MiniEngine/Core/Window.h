#pragma once
#include "mepch.h"

#include "MiniEngine/Core/Core.h"

namespace MiniEngine
{
	class ME_API Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		static Window* Create(const char* windowTitle = "MiniEngine", unsigned int width = 1280, unsigned int height = 720);

	};
}
