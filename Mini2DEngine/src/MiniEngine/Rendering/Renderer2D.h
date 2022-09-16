#pragma once
#include "mepch.h"
#include "glm/glm.hpp"
#include "MiniEngine/Core/Core.h"
#include "MiniEngine/Rendering/VertexArray.h"
#include "MiniEngine/Rendering/Shader.h"
#include "MiniEngine/Rendering/IndexBuffer.h"
#include "MiniEngine/Rendering/Texture.h"
#include "MiniEngine/Rendering/OrthographicCamera.h"
#include "MiniEngine/Rendering/Scene.h"

namespace MiniEngine
{
    struct Vertex
    {
        glm::vec3 Position;
        glm::vec2 TexCoords;
        float TexIndex;
    };

    class Renderer2D
    {
    public:
        static void Init();
        static void Shutdown();
        static void DrawScene(Scene& scene);
        static void OnWindowResize(unsigned int width, unsigned int height);

    private:
        static void BeginScene(OrthographicCamera& camera);
        static void EndScene();
        static void Clear(const glm::vec3 clearColor = { 0.3f, 0.3f, 0.3f });
        static void DrawQuad(float x, float y, float sizeX, float sizeY);
        static void DrawQuad(float x, float y, float sizeX, float sizeY, float rotation, bool flipHorizontal, Ref<Texture>& texture);
    };
}
