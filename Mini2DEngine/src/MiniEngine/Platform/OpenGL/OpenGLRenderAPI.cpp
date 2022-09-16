#include "mepch.h"
#include "OpenGLRenderAPI.h"

#include "glm/glm.hpp"
#include "glad/glad.h"

namespace MiniEngine
{
    void OpenGLRenderAPI::Init()
    {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
    }

    void OpenGLRenderAPI::SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
    {
        glViewport(x, y, width, height);
    }

    void OpenGLRenderAPI::SetClearColor(const glm::vec4& color)
    {
        glClearColor(color.x, color.y, color.z, color.w);
    }

    void OpenGLRenderAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OpenGLRenderAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, unsigned int indexCount)
    {
        vertexArray->Bind();
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    }
}
