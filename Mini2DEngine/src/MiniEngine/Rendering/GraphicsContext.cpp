#include "mepch.h"
#include "MiniEngine/Rendering/GraphicsContext.h"

#include "MiniEngine/Rendering/RenderAPI.h"
#include "MiniEngine/Platform/OpenGL/OpenGLContext.h"

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
