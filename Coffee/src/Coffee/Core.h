#pragma once

#ifdef CF_PLATFORM_WINDOWS
	#ifdef CF_BUILD_DLL
		#define COFFEE_API __declspec(dllexport)
	#else
		#define COFFEE_API __declspec(dllexport)
	#endif
#else
	#error Coffe only support Windows !
#endif
