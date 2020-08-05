#pragma once

#ifdef CF_PLATFORM_WINDOWS

extern Coffee::Application* Coffee::CreateApplication();

int main(int argc, char** argv)
{
	Coffee::Log::Init();
	CF_CORE_WARN("Initialized Log!");
	CF_INFO("Hello!");

	auto app = Coffee::CreateApplication();
	app->Run();

	delete app;
}

#endif // CF_PLATFORM_WINDOWS

