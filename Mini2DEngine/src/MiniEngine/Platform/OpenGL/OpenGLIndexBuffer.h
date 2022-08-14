#pragma once
#include "../../Rendering/IndexBuffer.h"

namespace MiniEngine
{
    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(unsigned int* indices, unsigned int count);
        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const;
        virtual void Unbind() const;

        virtual unsigned int GetCount() const { return count; };

    private:
        unsigned int rendererId;
        unsigned int count;
    };
}