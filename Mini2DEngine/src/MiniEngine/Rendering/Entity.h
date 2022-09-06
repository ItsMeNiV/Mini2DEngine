#pragma once
#include "../Core/Core.h"
#include "../Utils/UUID.h"

namespace MiniEngine
{
    class Entity
    {
    public:
        Entity(std::string&& name, float x, float y, float sizeX, float sizeY, Ref<Texture> tex) : entityId(generate_uuid_v4()), name(name), position(x, y), size(sizeX, sizeY), texture(tex) {}

        std::string& GetEntityId() { return entityId; }
        std::string& GetName() { return name; }
        glm::vec2& GetPosition() { return position; }
        glm::vec2& GetSize() { return size; }
        Ref<Texture>& GetTexture() { return texture; }
        void SetTexture(Ref<Texture> tex) { texture = tex; }

        virtual void OnUpdate(float deltaTime) {};

    private:
        std::string entityId;
        std::string name;
        glm::vec2 position;
        glm::vec2 size;
        Ref<Texture> texture;
    };
}