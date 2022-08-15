#pragma once
#include "../Core/Core.h"

namespace MiniEngine
{
    class Entity
    {
    public:
        Entity(float x, float y, float sizeX, float sizeY, Ref<Texture> tex) : position(x, y), size(sizeX, sizeY), texture(tex) {}

        glm::vec2& GetPosition() { return position; }
        glm::vec2& GetSize() { return size; }
        Ref<Texture>& GetTexture() { return texture; }
        void SetTexture(Ref<Texture> tex) { texture = tex; }

        virtual void OnUpdate(float deltaTime) {};

    private:
        glm::vec2 position;
        glm::vec2 size;
        Ref<Texture> texture;
    };
}