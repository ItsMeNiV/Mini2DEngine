#include "mepch.h"
#include "../Core/Core.h"
#include "RenderAPI.h"
#include <MiniEngine/Platform/OpenGL/OpenGLRenderAPI.h>

namespace MiniEngine
{
    RenderAPI::API RenderAPI::myApi = RenderAPI::API::OpenGL;

    Scope<RenderAPI> MiniEngine::RenderAPI::Create()
    {
        switch (myApi)
        {
        case RenderAPI::API::None: return nullptr;
        case RenderAPI::API::OpenGL: return CreateScope<OpenGLRenderAPI>();
        }

        return nullptr;
    }
}
