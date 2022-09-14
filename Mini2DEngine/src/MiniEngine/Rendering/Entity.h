#pragma once
#include "../Core/Core.h"
#include "../Utils/UUID.h"

namespace MiniEngine
{
    class Entity
    {
    public:
        Entity(std::string&& name, float x, float y, float sizeX, float sizeY, float rotation, Ref<Texture> tex)
            : entityId(generate_uuid_v4()), name(name), position(x, y), size(sizeX, sizeY), rotation(rotation), texture(tex) {}

        std::string& GetEntityId() { return entityId; }
        std::string& GetName() { return name; }
        glm::vec2& GetPosition() { return position; }
        glm::vec2& GetSize() { return size; }
        float GetRotation() const { return rotation; }
        void SetRotation(float rotation) { this->rotation = rotation; }
        Ref<Texture>& GetTexture() { return texture; }
        void SetTexture(Ref<Texture> tex) { texture = tex; }

        virtual void OnUpdate(float deltaTime) {}

        virtual void OnCollision(glm::vec2 colliderPos) {}

    private:
        std::string entityId;
        std::string name;
        glm::vec2 position;
        glm::vec2 size;
        float rotation;
        Ref<Texture> texture;
    };
}