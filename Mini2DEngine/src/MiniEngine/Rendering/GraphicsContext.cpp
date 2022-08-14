#include "mepch.h"
#include "GraphicsContext.h"
#include "RenderAPI.h"
#include "../Platform/OpenGL/OpenGLContext.h"

namespace MiniEngine
{
    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        switch (RenderAPI::GetAPI())
        {
        case RenderAPI::API::None: return nullptr;
        case RenderAPI::API::OpenGL: return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        return nullptr;
    }
}
