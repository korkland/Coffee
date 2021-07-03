#include "cfpch.h"
#include "Application.h"

#include "Coffee/Events/ApplicationEvent.h"
#include "Coffee/Log.h"

namespace Coffee {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	
	Application::~Application()
	{

	}
	
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
