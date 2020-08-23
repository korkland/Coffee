#pragma once

#ifdef CF_PLATFORM_WINDOWS
	#ifdef CF_BUILD_DLL
		#define COFFEE_API __declspec(dllexport)
	#else
		#define COFFEE_API __declspec(dllimport)
	#endif
#else
	#error Coffe only supports Windows !
#endif

#ifdef CF_DEBUG
	#define CF_ENABLE_ASSERTS
#endif

#ifdef CF_ENABLE_ASSERTS
	#define CF_ASSERT(x, ...) {if(!(x)) {CF_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CF_CORE_ASSERT(x, ...) {if(!(x)) {CF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CF_ASSERT(x, ...)
	#define CF_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CF_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
