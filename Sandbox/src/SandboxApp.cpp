#include <MiniEngine.h>
#include "MiniEngine/Core/EntryPoint.h"
#include "GoldCube.h"

class Sandbox : public MiniEngine::Layer
{
public:
    Sandbox() : Layer("Sandbox layer"), camera(MiniEngine::CreateRef<MiniEngine::OrthographicCamera>(1280, 720)) {}

    virtual ~Sandbox() = default;

    virtual void OnAttach() override
    {
        std::cout << "Layer attached" << std::endl;
        scene = MiniEngine::CreateRef<MiniEngine::Scene>(*camera);
        MiniEngine::Ref<MiniEngine::Texture> goldTexture = MiniEngine::Texture::Create("assets/pictures/texture.jpg");
        MiniEngine::Ref<MiniEngine::Texture> silverTexture = MiniEngine::Texture::Create("assets/pictures/texture2.jpg");
        MiniEngine::Ref<GoldCube> background = MiniEngine::CreateRef<GoldCube>(-(1280.0f / 720.0f), -1.0f, 2*(1280.0f / 720.0f), 2.0f, silverTexture);
        MiniEngine::Ref<GoldCube> goldCube = MiniEngine::CreateRef<GoldCube>(-1.0f, -0.5f, 0.1f, 0.1f, goldTexture);
        MiniEngine::Ref<GoldCube> goldCube2 = MiniEngine::CreateRef<GoldCube>(1.0f, 0.5f, 0.5f, 0.1f, goldTexture);
        scene->AddEntity(background);
        scene->AddEntity(goldCube);
        scene->AddEntity(goldCube2);
    }

    virtual void OnDetach() override
    {
        std::cout << "Layer detached" << std::endl;
    }

    void OnUpdate(float deltaTime) override
    {
        scene->OnUpdate(deltaTime);

        MiniEngine::Renderer2D::DrawScene(*scene);
    }

private:
    MiniEngine::Ref<MiniEngine::OrthographicCamera> camera;
    MiniEngine::Ref<MiniEngine::Scene> scene;
};


class SandboxApp : public MiniEngine::Application
{
public:
    SandboxApp(MiniEngine::AppDefinitions& appDef) : Application(appDef)
    {
        this->PushLayer(new Sandbox());
    }

    ~SandboxApp()
    {

    }
};

MiniEngine::Application* MiniEngine::CreateApplication()
{
    AppDefinitions appDef{"Sandbox", 1280, 720, false};
    return new SandboxApp(appDef);
}