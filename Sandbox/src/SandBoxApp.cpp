#include <Coffee.h>

class ExampleLayer : public Coffee::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Coffee::Input::IsKeyPressed(CF_KEY_TAB))
			CF_TRACE("Key Tab is pressed (poll)");
	}

	void OnEvent(Coffee::Event& event) override
	{
		if (event.GetEventType() == Coffee::EventType::KeyPressed)
		{
			Coffee::KeyPressedEvent& e = (Coffee::KeyPressedEvent&)event;
			if (e.GetKeycode() == CF_KEY_TAB)
				CF_TRACE("Key Tab is pressed (event)");
			CF_TRACE("{0}", (char)e.GetKeycode());
		}
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