#include "mepch.h"
#include "MiniEngine/Rendering/Shader.h"

#include "MiniEngine/Rendering/RenderAPI.h"
#include "MiniEngine/Platform/OpenGL/OpenGLShader.h"

namespace MiniEngine
{
    Ref<Shader> Shader::Create(const char* vertexPath, const char* fragmentPath)
    {
        switch (RenderAPI::GetAPI())
        {
        case RenderAPI::API::None: return nullptr;
        case RenderAPI::API::OpenGL: return CreateRef<OpenGLShader>(vertexPath, fragmentPath);
        }

        return nullptr;
    }
}