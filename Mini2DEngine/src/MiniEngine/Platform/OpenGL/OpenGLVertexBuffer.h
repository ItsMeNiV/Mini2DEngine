#pragma once
#include "MiniEngine/Rendering/VertexBuffer.h"

namespace MiniEngine
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(const void* data, unsigned int size);
        OpenGLVertexBuffer(unsigned int size);

        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const;
        virtual void Unbind() const;

        virtual void SetData(const void* data, unsigned int size);

        virtual const BufferLayout& GetLayout() const { return layout; };
        virtual void SetLayout(const BufferLayout& layout) { this->layout = layout; };

    private:
        unsigned int rendererId;
        BufferLayout layout;
    };
}