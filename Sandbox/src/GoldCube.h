#pragma once
#include "MiniEngine.h"

class GoldCube : public MiniEngine::Entity
{
public:
    GoldCube(float x, float y, float sizeX, float sizeY, MiniEngine::Ref<MiniEngine::Texture> texture) : Entity(x, y, sizeX, sizeY, texture) {}

    void OnUpdate(float deltaTime) override
    {
        
    }
};