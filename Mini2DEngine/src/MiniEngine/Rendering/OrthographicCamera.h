#pragma once
#include "glm/glm.hpp"

namespace MiniEngine
{
    class OrthographicCamera
    {
    public:
        OrthographicCamera(unsigned int screenWidth, unsigned int screenHeight);

        void SetProjection(float left, float right, float bottom, float top);

        const glm::vec3& GetPosition() const { return position; }
        void SetPosition(const glm::vec3 position) { this->position = position; RecalculateViewMatrix(); }

        float GetRotation() const { return rotation; }
        void SetRotation(float rotation) { this->rotation = rotation; RecalculateViewMatrix(); }

        const glm::mat4& GetProjectionMatrix() const { return projectionMatrix; }
        const glm::mat4& GetViewMatrix() const { return viewMatrix; }
        const glm::mat4& GetViewProjectionMatrix() const { return viewProjectionMatrix; }

    private:
        OrthographicCamera(float left, float right, float bottom, float top);
        glm::mat4 projectionMatrix;
        glm::mat4 viewMatrix;
        glm::mat4 viewProjectionMatrix;

        glm::vec3 position = { 0.0f, 0.0f, 0.0f };
        float rotation = 0.0f;

        void RecalculateViewMatrix();
    };
}