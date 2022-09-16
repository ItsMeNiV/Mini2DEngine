#pragma once
#include "GLFW/glfw3.h"
#include "MiniEngine/Rendering/GraphicsContext.h"

namespace MiniEngine
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* window);

        virtual void Init();
        virtual void SwapBuffers();

    private:
        GLFWwindow* windowHandle;
    };
}
