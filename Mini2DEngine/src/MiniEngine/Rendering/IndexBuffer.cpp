#include "mepch.h"
#include "IndexBuffer.h"
#include "RenderAPI.h"
#include <MiniEngine/Platform/OpenGL/OpenGLIndexBuffer.h>

namespace MiniEngine
{
    Ref<IndexBuffer> IndexBuffer::Create(unsigned int* data, unsigned int count)
    {
        switch (RenderAPI::GetAPI())
        {
            case RenderAPI::API::None: return nullptr;
            case RenderAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(data, count);
        }
    }
}