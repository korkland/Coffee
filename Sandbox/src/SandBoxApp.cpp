#include <Coffee.h>

#include "imgui/imgui.h"

class ExampleLayer : public Coffee::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//CF_INFO("ExamplerLayer::Update");

		if (Coffee::Input::IsKeyPressed(CF_KEY_TAB))
			CF_TRACE("Tab key is pressed(poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Coffee::Event& event) override
	{
		if (event.GetEventType() == Coffee::EventType::KeyPressed)
		{
			Coffee::KeyPressedEvent& e = (Coffee::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CF_KEY_TAB)
				CF_TRACE("Tab key is pressed (event)!");
			CF_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Coffee::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
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