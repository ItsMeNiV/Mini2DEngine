#pragma once
#include "MiniEngine/Core/Core.h"

namespace MiniEngine
{
    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual unsigned int GetCount() const = 0;

        static Ref<IndexBuffer> Create(unsigned int* data, unsigned int count);
    };
}