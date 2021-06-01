#pragma once

#ifdef JS_PLATFORM_WINDOWS
	#ifdef JS_DLL_BUILD
		#define JESTER_API __declspec(dllexport)
	#else
		#define JESTER_API __declspec(dllimport)
	#endif
#else
	#error JesterEngine only supports Windows 10 lel
#endif