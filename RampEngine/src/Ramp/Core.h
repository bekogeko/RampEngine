#pragma once

#ifdef RMP_PLATFORM_WINDOWS
	#if RMP_BUILD_DLL
		#define RAMP_API __declspec(dllexport)
	#else
		#define RAMP_API __declspec(dllimport)
	#endif 
#else
	#error Ramp Engine only support Windows
#endif

#define BIT(x) (1 << x)