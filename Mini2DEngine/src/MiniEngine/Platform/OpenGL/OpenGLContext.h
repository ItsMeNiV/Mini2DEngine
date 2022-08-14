#pragma once
#include "../../Rendering/GraphicsContext.h"
#include <GLFW/glfw3.h>

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
