#pragma once
#include <vector>
#include "Entity.h"
#include "OrthographicCamera.h"

namespace MiniEngine
{
    class Scene
    {
    public:
        Scene(OrthographicCamera& cam) : camera(cam) {}

        void AddEntity(Ref<Entity> entity) { entities.push_back(entity); }
        std::vector<Ref<Entity>> GetEntities() const { return entities; }
        OrthographicCamera& GetCamera() const { return camera; }

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