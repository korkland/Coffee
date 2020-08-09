#include "cfpch.h"
#include "Application.h"

#include "Coffee/Events/ApplicationEvent.h"
#include "Log.h"

namespace Coffee {

	Application::Application()
	{

	}
	
	Application::~Application()
	{

	}
	
	void Application::Run()
	{
		Coffee::Log::Init();
		WindowResizeEvent e(1280, 720);
		CF_CORE_WARN(e);

		while (true);
	}
}
