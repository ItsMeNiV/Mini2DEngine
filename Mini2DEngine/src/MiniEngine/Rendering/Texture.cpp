#include "mepch.h"
#include "MiniEngine/Rendering/Texture.h"

#include "MiniEngine/Rendering/RenderAPI.h"
#include "MiniEngine/Platform/OpenGL/OpenGLTexture.h"

namespace MiniEngine
{
    Ref<Texture> Texture::Create(const std::string& path)
    {
        switch (RenderAPI::GetAPI())
        {
        case RenderAPI::API::None: return nullptr;
        case RenderAPI::API::OpenGL: return CreateRef<OpenGLTexture>(path);
        }

        return nullptr;
    }
}