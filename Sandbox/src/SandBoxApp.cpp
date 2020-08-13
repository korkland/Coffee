#include <Coffee.h>

class ExampleLayer : public Coffee::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		CF_INFO("ExamplerLayer::Update");
	}

	void OnEvent(Coffee::Event& event) override
	{
		CF_TRACE("{0}", event);
	}
};

class Sandbox : public Coffee::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Coffee::ImGuiLayer());
	}
	~Sandbox()
	{

	}

private:

};

Coffee::Application* Coffee::CreateApplication()
{
	return new Sandbox();
}