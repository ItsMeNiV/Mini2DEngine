#include "mepch.h"
#include "MiniEngine/Rendering/VertexArray.h"

#include "MiniEngine/Rendering/RenderAPI.h"
#include "MiniEngine/Platform/OpenGL/OpenGLVertexArray.h"

namespace MiniEngine
{
    Ref<VertexArray> VertexArray::Create()
    {
        switch (RenderAPI::GetAPI())
        {
        case RenderAPI::API::None: return nullptr;
        case RenderAPI::API::OpenGL: return CreateRef<OpenGLVertexArray>();
        }

        return nullptr;
    }
}