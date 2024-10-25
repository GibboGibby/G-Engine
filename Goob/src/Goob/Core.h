#pragma once

#ifdef GB_PLATFORM_WINDOWS
	#ifdef GB_BUILD_DLL
		#define GOOB_API __declspec(dllexport)
	#else
		#define GOOB_API __declspec(dllimport)
	#endif
#else
#error Goob only supports Windows!
#endif

#define BIT(x) (1 << x)

#ifdef GB_ENABLE_ASSERTS
#define GOOB_ASSERT(x, ...) {if (!(x)) {GOOB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#define GOOB_CORE_ASSERT(x, ...) {if(!(x)) {GOOB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define GOOB_ASSERT(x, ...)
#define GOOB_CORE_ASSERT(x, ...)
#endif