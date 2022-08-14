#include "mepch.h"
#include "OrthographicCamera.h"

#include "glm/gtc/matrix_transform.hpp"

namespace MiniEngine
{
    OrthographicCamera::OrthographicCamera(unsigned int screenWidth, unsigned int screenHeight)
        : OrthographicCamera(-((float)screenWidth / (float)screenHeight), ((float)screenWidth / (float)screenHeight), -1.0f, 1.0f) {}

    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
        : projectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), viewMatrix(1.0f)
    {
        viewProjectionMatrix = projectionMatrix * viewMatrix;
    }

    void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
    {
        projectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        viewProjectionMatrix = projectionMatrix * viewMatrix;
    }

    void OrthographicCamera::RecalculateViewMatrix()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
        viewMatrix = glm::inverse(transform);
        viewProjectionMatrix = projectionMatrix * viewMatrix;
    }
}
