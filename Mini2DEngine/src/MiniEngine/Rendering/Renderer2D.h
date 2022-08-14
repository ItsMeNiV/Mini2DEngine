#pragma once
#include "mepch.h"
#include "VertexArray.h"
#include "Shader.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "../Core/Core.h"
#include "OrthographicCamera.h"
#include "glm/glm.hpp"

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
        static void BeginScene(OrthographicCamera& camera);
        static void EndScene();
        static void Clear(const glm::vec3 clearColor = {0.3f, 0.3f, 0.3f});
        static void DrawQuad(float x, float y, float sizeX, float sizeY);
        static void DrawQuad(float x, float y, float sizeX, float sizeY, Ref<Texture>& texture);
        static void OnWindowResize(unsigned int width, unsigned int height);
    };
}
