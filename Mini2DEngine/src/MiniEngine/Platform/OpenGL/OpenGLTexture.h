#pragma once
#include "../../Rendering/Texture.h"

namespace MiniEngine
{
    class OpenGLTexture : public Texture
    {
    public:
        OpenGLTexture(const std::string& path);
        ~OpenGLTexture();

        virtual void Bind(unsigned int slot = 0) const;
        virtual void Unbind() const;

        inline virtual int GetWidth() const { return width; }
        inline virtual int GetHeight() const { return height; }
        inline virtual int GetRendererId() const { return rendererId; }

        virtual bool operator==(const Texture& other) const { return rendererId == other.GetRendererId(); }
        
    private:
        unsigned int rendererId;
        std::string filePath;
        unsigned char* localBuffer;
        int width, height, bpp;
    };
}