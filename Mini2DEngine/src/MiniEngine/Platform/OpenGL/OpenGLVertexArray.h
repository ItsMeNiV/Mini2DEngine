#pragma once
#include "MiniEngine/Rendering/VertexArray.h"

namespace MiniEngine
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void SetVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
        virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

    private:
        unsigned int rendererId;
        Ref<VertexBuffer> vertexBuffer;
        Ref<IndexBuffer> indexBuffer;
    };
}