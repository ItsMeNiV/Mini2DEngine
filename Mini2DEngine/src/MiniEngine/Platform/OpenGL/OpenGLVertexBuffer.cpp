#include "mepch.h"
#include "glad/glad.h"
#include "MiniEngine/Platform/OpenGL/OpenGLVertexBuffer.h"

namespace MiniEngine
{

    OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, unsigned int size)
    {
        glGenBuffers(1, &rendererId);
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(unsigned int size)
    {
        glGenBuffers(1, &rendererId);
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &rendererId);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
    }

    void OpenGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::SetData(const void* data, unsigned int size)
    {
        Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

}