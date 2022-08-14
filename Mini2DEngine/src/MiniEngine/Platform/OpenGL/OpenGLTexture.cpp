#include "mepch.h"
#include "OpenGLTexture.h"
#include "glad/glad.h"
#include "stb_image.h"

namespace MiniEngine
{

    OpenGLTexture::OpenGLTexture(const std::string& path)
        : filePath(path), localBuffer(0), width(0), height(0), bpp(0)
    {
        stbi_set_flip_vertically_on_load(1);
        localBuffer = stbi_load(path.c_str(), &width, &height, &bpp, 4);

        glGenTextures(1, &rendererId);
        Bind();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
        Unbind();

        if (localBuffer)
        {
            stbi_image_free(localBuffer);
        }
    }

    OpenGLTexture::~OpenGLTexture()
    {
        glDeleteTextures(1, &rendererId);
    }

    void OpenGLTexture::Bind(unsigned int slot /*= 0*/) const
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, rendererId);
    }

    void OpenGLTexture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}