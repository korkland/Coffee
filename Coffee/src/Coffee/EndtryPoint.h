#pragma once

#ifdef CF_PLATFORM_WINDOWS

#else
	#error Coffee only support Windows!
#endif // CF_PLATFORM_WINDOWS

extern Coffee::Application* Coffee::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Coffee::CreateApplication();
	app->Run();

	delete app;
}