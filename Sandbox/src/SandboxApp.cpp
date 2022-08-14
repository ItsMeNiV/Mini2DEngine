#include <MiniEngine.h>

class Sandbox : public MiniEngine::Layer
{
public:
    Sandbox() : Layer("Sandbox layer"), camera(1280, 720)
    {
        goldTexture = MiniEngine::Texture::Create("assets/pictures/texture.jpg");
        silverTexture = MiniEngine::Texture::Create("assets/pictures/texture2.jpg");
    };

    virtual ~Sandbox() = default;

    virtual void OnAttach() override
    {
        std::cout << "Layer attached" << std::endl;
    }

    virtual void OnDetach() override
    {
        std::cout << "Layer detached" << std::endl;
    }

    void OnUpdate(float deltaTime) override
    {
        MiniEngine::Renderer2D::BeginScene(camera);

        MiniEngine::Renderer2D::DrawQuad(-1.0f, -0.5f, 1.0f, 1.0f, goldTexture);
        MiniEngine::Renderer2D::DrawQuad(1.0f, 0.5f, 1.0f, 1.0f, silverTexture);

        MiniEngine::Renderer2D::EndScene();
    }

private:
    MiniEngine::OrthographicCamera camera;
    MiniEngine::Ref<MiniEngine::Texture> goldTexture;
    MiniEngine::Ref<MiniEngine::Texture> silverTexture;
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
    AppDefinitions appDef{"Sandbox", 1280, 720};
    return new SandboxApp(appDef);
}