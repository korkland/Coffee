#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Coffee {

	class COFFEE_API Application
	{
	public:
		Application();
		virtual ~Application();
	
		void Run();
	};

	Application* CreateApplication();
}

