#include "mepch.h"
#include "VertexBuffer.h"
#include "RenderAPI.h"
#include "../Platform/OpenGL/OpenGLVertexBuffer.h"

namespace MiniEngine
{

    MiniEngine::Ref<MiniEngine::VertexBuffer> VertexBuffer::Create(const void* data, unsigned int size)
    {
        switch (RenderAPI::GetAPI())
        {
        case RenderAPI::API::None: return nullptr;
        case RenderAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(data, size);
        }

        return nullptr;
    }

    MiniEngine::Ref<MiniEngine::VertexBuffer> VertexBuffer::Create(unsigned int size)
    {
        switch (RenderAPI::GetAPI())
        {
        case RenderAPI::API::None: return nullptr;
        case RenderAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(size);
        }

        return nullptr;
    }

}