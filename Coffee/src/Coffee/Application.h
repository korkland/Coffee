#pragma once

#include "Core.h"

#include "Window.h"
#include "Coffee/LayerStack.h"
#include "Coffee/Events/Event.h"
#include "Coffee/Events/ApplicationEvent.h"

#include "Coffee/ImGui/ImGuiLayer.h"

namespace Coffee {

	class COFFEE_API Application
	{
	public:
		Application();
		virtual ~Application();
	
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}

