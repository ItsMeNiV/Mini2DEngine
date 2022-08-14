#pragma once
#include "../Core/Core.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace MiniEngine
{
    class VertexArray
    {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
        virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;

        static Ref<VertexArray> Create();
    };
}