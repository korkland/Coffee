#pragma once

#include "Core.h"
#include "Window.h"

#include "Coffee/Events/ApplicationEvent.h"

namespace Coffee {

	class COFFEE_API Application
	{
	public:
		Application();
		virtual ~Application();
	
		void Run();

		void OnEvent(Event& e);
	
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

