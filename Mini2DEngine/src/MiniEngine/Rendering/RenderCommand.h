#pragma once
#include "RenderAPI.h"

namespace MiniEngine
{
    class RenderCommand
    {
    public:
        static void Init()
        {
            renderAPI->Init();
        }

        static void SetClearColor(const glm::vec4& color)
        {
            renderAPI->SetClearColor(color);
        }

        static void Clear()
        {
            renderAPI->Clear();
        }

        static void DrawIndexed(const Ref<VertexArray>& vertexArray, unsigned int indexCount = 0)
        {
            renderAPI->DrawIndexed(vertexArray, indexCount);
        }

        static void SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
        {
            renderAPI->SetViewPort(x, y, width, height);
        }

    private:
        static Scope<RenderAPI> renderAPI;
    };
}