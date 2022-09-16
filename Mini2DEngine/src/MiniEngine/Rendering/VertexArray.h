#pragma once
#include "MiniEngine/Core/Core.h"
#include "MiniEngine/Rendering/VertexBuffer.h"
#include "MiniEngine/Rendering/IndexBuffer.h"

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