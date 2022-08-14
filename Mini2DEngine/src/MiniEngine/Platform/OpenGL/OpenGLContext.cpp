#include "mepch.h"
#include "OpenGLContext.h"

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace MiniEngine
{
    OpenGLContext::OpenGLContext(GLFWwindow* window) : windowHandle(window) {}

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(windowHandle);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
    }
    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(windowHandle);
    }
}
