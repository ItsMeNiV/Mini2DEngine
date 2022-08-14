#include "mepch.h"
#include "Renderer2D.h"
#include "../Core/Core.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Texture.h"
#include "RenderCommand.h"

namespace MiniEngine
{
    struct Renderer2DData
    {
        static const unsigned int maxQuads = 500;
        static const unsigned int maxVertices = maxQuads * 4;
        static const unsigned int maxIndices = maxQuads * 6;

        Ref<VertexArray> quadVertexArray;
        Ref<VertexBuffer> quadVertexBuffer;
        Ref<IndexBuffer> quadIndexBuffer;
        Ref<Shader> quadShader;

        Vertex* quadVertexBufferBase = nullptr;
        Vertex* quadVertexBufferPtr = nullptr;
        uint32_t quadIndexCount = 0;

        std::array<Ref<Texture>, 32> textureSlots;
        unsigned int textureSlotIndex = 0;

        struct CameraData
        {
            glm::mat4 viewProjection;
        };
        CameraData CameraData;
    };

    static Renderer2DData rendererData;

    void Renderer2D::Init()
    {
        RenderCommand::Init();

        rendererData.quadVertexArray = VertexArray::Create();
        rendererData.quadVertexBuffer = VertexBuffer::Create(rendererData.maxVertices * sizeof(Vertex));
        rendererData.quadVertexBuffer->SetLayout({
            { ShaderDataType::Float3, "aPos" },
            { ShaderDataType::Float2, "aTexCoord" },
            { ShaderDataType::Float, "aTexIndex" }
        });

        rendererData.quadVertexArray->SetVertexBuffer(rendererData.quadVertexBuffer);

        rendererData.quadVertexBufferBase = new Vertex[rendererData.maxIndices];

        unsigned int* quadIndices = new unsigned int[rendererData.maxIndices];
        unsigned int offset = 0;
        for (unsigned int i = 0; i < rendererData.maxIndices; i += 6)
        {
            quadIndices[i + 0] = offset + 0;
            quadIndices[i + 1] = offset + 1;
            quadIndices[i + 2] = offset + 2;

            quadIndices[i + 3] = offset + 2;
            quadIndices[i + 4] = offset + 3;
            quadIndices[i + 5] = offset + 0;

            offset += 4;
        }

        rendererData.quadIndexBuffer = IndexBuffer::Create(quadIndices, rendererData.maxIndices);
        rendererData.quadIndexBuffer->Bind();

        rendererData.quadShader = Shader::Create("assets/shaders/VertexShader.vert", "assets/shaders/FragmentShader.frag");
    }

    void Renderer2D::Shutdown()
    {
        delete[] rendererData.quadVertexBufferBase;
    }

    void Renderer2D::BeginScene(OrthographicCamera& camera)
    {
        Clear();
        rendererData.quadIndexCount = 0;
        rendererData.quadVertexBufferPtr = rendererData.quadVertexBufferBase;
        rendererData.CameraData.viewProjection = camera.GetViewProjectionMatrix();
    }

    void Renderer2D::EndScene()
    {
        glm::mat4 model = glm::mat4(1.0f); // Local space -> World space
        glm::mat4 view = glm::mat4(1.0f); // World Space -> View Space
        glm::mat4 proj = glm::mat4(1.0f); // View Space -> Clip Space
        //Rotate the model
        model = glm::scale(model, glm::vec3(100, 100, 100));
        //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

        glm::mat4 mvp = rendererData.CameraData.viewProjection;// *model;

        //Bind textures
        for (uint32_t i = 0; i < rendererData.textureSlotIndex; i++)
            rendererData.textureSlots[i]->Bind(i);

        rendererData.quadShader->setMat4f("u_MVP", mvp);
        int samplers[32];
        for (size_t i = 0; i < 32; i++)
        {
            samplers[i] = i;
        }
        rendererData.quadShader->setIntv("u_Textures", 32, samplers);

        if (rendererData.quadIndexCount)
        {
            uint32_t dataSize = (uint32_t)((uint8_t*)rendererData.quadVertexBufferPtr - (uint8_t*)rendererData.quadVertexBufferBase);
            rendererData.quadVertexBuffer->SetData(rendererData.quadVertexBufferBase, dataSize);

            rendererData.quadShader->Bind();
            rendererData.quadVertexArray->Bind();
            rendererData.quadIndexBuffer->Bind();
            RenderCommand::DrawIndexed(rendererData.quadVertexArray, rendererData.quadIndexCount);
        }
    }

    void Renderer2D::Clear(const glm::vec3 clearColor)
    {
        RenderCommand::SetClearColor(glm::vec4(clearColor, 1.0f));
        RenderCommand::Clear();
    }

    void Renderer2D::DrawQuad(float x, float y, float sizeX, float sizeY)
    {
        //Vec1
        rendererData.quadVertexBufferPtr->Position = { x, y, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 0.0f, 0.0f };
        rendererData.quadVertexBufferPtr->TexIndex = 0.0f;
        rendererData.quadVertexBufferPtr++;

        //Vec2
        rendererData.quadVertexBufferPtr->Position = { x + sizeX,  y, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 1.0f, 0.0f };
        rendererData.quadVertexBufferPtr->TexIndex = 0.0f;
        rendererData.quadVertexBufferPtr++;

        //Vec3
        rendererData.quadVertexBufferPtr->Position = { x + sizeX, y + sizeY, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 1.0f, 1.0f };
        rendererData.quadVertexBufferPtr->TexIndex = 0.0f;
        rendererData.quadVertexBufferPtr++;

        //Vec4
        rendererData.quadVertexBufferPtr->Position = { x, y + sizeY, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 0.0f, 1.0f };
        rendererData.quadVertexBufferPtr->TexIndex = 0.0f;
        rendererData.quadVertexBufferPtr++;

        rendererData.quadIndexCount += 6;
    }

    void Renderer2D::DrawQuad(float x, float y, float sizeX, float sizeY, Ref<Texture>& texture)
    {
        float textureIndex = -1.0f;
        for (uint32_t i = 0; i < rendererData.textureSlotIndex; i++)
        {
            if (*rendererData.textureSlots[i] == *texture)
            {
                textureIndex = (float)i;
                break;
            }
        }
        if (textureIndex == -1.0f)
        {
            textureIndex = (float)rendererData.textureSlotIndex;
            rendererData.textureSlots[rendererData.textureSlotIndex] = texture;
            rendererData.textureSlotIndex++;
        }

        //Vec1
        rendererData.quadVertexBufferPtr->Position = { x, y, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 0.0f, 0.0f };
        rendererData.quadVertexBufferPtr->TexIndex = textureIndex;
        rendererData.quadVertexBufferPtr++;

        //Vec2
        rendererData.quadVertexBufferPtr->Position = { x + sizeX,  y, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 1.0f, 0.0f };
        rendererData.quadVertexBufferPtr->TexIndex = textureIndex;
        rendererData.quadVertexBufferPtr++;

        //Vec3
        rendererData.quadVertexBufferPtr->Position = { x + sizeX, y + sizeY, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 1.0f, 1.0f };
        rendererData.quadVertexBufferPtr->TexIndex = textureIndex;
        rendererData.quadVertexBufferPtr++;

        //Vec4
        rendererData.quadVertexBufferPtr->Position = { x, y + sizeY, 0.0f };
        rendererData.quadVertexBufferPtr->TexCoords = { 0.0f, 1.0f };
        rendererData.quadVertexBufferPtr->TexIndex = textureIndex;
        rendererData.quadVertexBufferPtr++;

        rendererData.quadIndexCount += 6;
    }

    void Renderer2D::OnWindowResize(unsigned int width, unsigned int height)
    {
        RenderCommand::SetViewPort(0, 0, width, height);
    }

}