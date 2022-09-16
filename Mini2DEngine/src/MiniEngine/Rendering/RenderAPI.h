#pragma once
#include "glm/glm.hpp"
#include "MiniEngine/Core/Core.h"
#include "MiniEngine/Rendering/VertexArray.h"

namespace MiniEngine
{
    class RenderAPI
    {
    public:
        enum class API
        {
            None = 0, OpenGL = 1
        };

        virtual ~RenderAPI() = default;

        virtual void Init() = 0;

        virtual void SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;
        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, unsigned int indexCount = 0) = 0;

        static API GetAPI() { return myApi; }
        static Scope<RenderAPI> Create();

    private:
        static API myApi;
    };
}