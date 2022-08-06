#pragma once
#include "MiniEngine/Core/Core.h"
#include <MiniEngine/Core/KeyCodes.h>

namespace MiniEngine
{
	ME_API class Input
	{
	public:
		static bool IsKeyPressed(KeyCode keyCode);
	};
}