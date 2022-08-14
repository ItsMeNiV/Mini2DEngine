#pragma once
#include "../../Rendering/RenderAPI.h"
#include "glm/glm.hpp"

namespace MiniEngine
{
    class OpenGLRenderAPI : public RenderAPI
    {
    public:
        virtual void Init() override;
        virtual void SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) override;
        virtual void SetClearColor(const glm::vec4& color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, unsigned int indexCount = 0) override;
    };
}