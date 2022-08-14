#include "mepch.h"
#include "Texture.h"
#include "RenderAPI.h"
#include "../Platform/OpenGL/OpenGLTexture.h"

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