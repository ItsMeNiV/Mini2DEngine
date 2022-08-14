#pragma once
#include "../../Rendering/Shader.h"
#include "glm/glm.hpp"

namespace MiniEngine
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const char* vertexPath, const char* fragmentPath);

        virtual void Bind() const;
        virtual void Unbind() const;

        virtual void setBool(const std::string& name, bool value) const;
        virtual void setInt(const std::string& name, int value) const;
        virtual void setIntv(const std::string& name, int count, int value[]) const;
        virtual void setFloat(const std::string& name, float value) const;
        virtual void setVec3(const std::string& name, float x, float y, float z) const;
        virtual void setMat4f(const std::string& name, const glm::mat4& matrix) const;

    private:
        unsigned int rendererId;

        void checkCompileErrors(unsigned int shader, std::string type);
    };
}