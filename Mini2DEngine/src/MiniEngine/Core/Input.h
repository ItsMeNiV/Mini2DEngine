#pragma once
#include "MiniEngine/Core/Core.h"
#include "MiniEngine/Core/KeyCodes.h"

namespace MiniEngine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode keyCode);
	};
}