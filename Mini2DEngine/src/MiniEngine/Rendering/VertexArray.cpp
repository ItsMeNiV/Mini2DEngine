#include "mepch.h"
#include "VertexArray.h"
#include "RenderAPI.h"
#include "../Platform/OpenGL/OpenGLVertexArray.h"

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