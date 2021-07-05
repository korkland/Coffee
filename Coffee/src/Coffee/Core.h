#pragma once

#ifdef CF_PLATFORM_WINDOWS
	#ifdef CF_BUILD_DLL
		#define COFFEE_API __declspec(dllexport)
	#else
		#define COFFEE_API __declspec(dllimport)
	#endif
#else
	#error Coffee only support Windows !
#endif

#ifdef CF_ENABLE_ASSERTS
	#define CF_ASSERT(x, ...) { if(!(x)) {CF_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak();}}
	#define CF_CORE_ASSERT(x, ...) { if(!(x)) {CF_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define CF_ASSERT(x, ...)
	#define CF_CORE_ASSERT(x, ...)
#endif // CF_ENABLE_ASSERTS

#define CF_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define BIT(x) (1 << x)