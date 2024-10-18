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