#pragma once
#include "MiniEngine/Core/Core.h"

namespace MiniEngine
{
    class GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;

        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;

        static Scope<GraphicsContext> Create(void* window);
    };
}
