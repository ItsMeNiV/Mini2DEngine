#pragma once
#include "../Core/Core.h"
#include "glm/glm.hpp"

namespace MiniEngine
{
    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void setBool(const std::string& name, bool value) const = 0;
        virtual void setInt(const std::string& name, int value) const = 0;
        virtual void setIntv(const std::string& name, int count, int value[]) const = 0;
        virtual void setFloat(const std::string& name, float value) const = 0;
        virtual void setVec3(const std::string& name, float x, float y, float z) const = 0;
        virtual void setMat4f(const std::string& name, const glm::mat4& matrix) const = 0;

        static Ref<Shader> Create(const char* vertexPath, const char* fragmentPath);
    };
}