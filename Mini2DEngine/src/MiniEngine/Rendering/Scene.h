#pragma once
#include <vector>
#include "MiniEngine/Rendering/Entity.h"
#include "MiniEngine/Rendering/OrthographicCamera.h"

namespace MiniEngine
{
    class Scene
    {
    public:
        Scene(OrthographicCamera& cam) : camera(cam) {}

        void AddEntity(Ref<Entity> entity) { entities.push_back(entity); }
        std::vector<Ref<Entity>> GetEntities() const { return entities; }
        OrthographicCamera& GetCamera() const { return camera; }

        void RemoveEntity(std::string entityId)
        {
            entities.erase(std::remove_if(begin(entities), end(entities), [entityId](Ref<Entity> e)
                {
                    return e->GetEntityId() == entityId;
                }), entities.end());
        }

        void OnUpdate(float deltaTime)
        {
            for (Ref<Entity> e : entities)
            {
                e->OnUpdate(deltaTime);
            }
        };

    private:
        std::vector<Ref<Entity>> entities;
        OrthographicCamera& camera;
    };
}