#pragma once
#include "../Core/Core.h"
#include <string>

namespace MiniEngine
{
    class Texture
    {
    public:
        virtual ~Texture() = default;

        virtual void Bind(unsigned int slot = 0) const = 0;
        virtual void Unbind() const = 0;

        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual int GetRendererId() const = 0;

        virtual bool operator==(const Texture& other) const = 0;

        static Ref<Texture> Create(const std::string& path);
    };
}