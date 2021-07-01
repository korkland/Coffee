#pragma once

#ifdef CF_PLATFORM_WINDOWS

#else
	#error Coffee only support Windows!
#endif // CF_PLATFORM_WINDOWS

extern Coffee::Application* Coffee::CreateApplication();

int main(int argc, char** argv)
{
	Coffee::Log::Init();
	CF_CORE_WARN("Init Log!");
	CF_CLIENT_INFO("Hello client {0}!", 5);

	auto app = Coffee::CreateApplication();
	app->Run();

	delete app;
}