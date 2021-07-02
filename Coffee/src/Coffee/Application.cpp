#include "Application.h"

#include "Coffee/Events/ApplicationEvent.h"
#include "Coffee/Log.h"

namespace Coffee {

	Application::Application()
	{

	}
	
	Application::~Application()
	{

	}
	
	void Application::Run()
	{
		WindowResizeEvent evnt(1280, 720);

		if (evnt.IsInCategory(EventCategoryApplication))
			CF_TRACE(evnt.ToString());

		if (evnt.IsInCategory(EventCategoryInput))
			CF_TRACE(evnt.ToString());

		while (true);
	}
}
