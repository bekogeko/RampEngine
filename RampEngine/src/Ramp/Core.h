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

#ifdef RMP_ENABLE_ASSERTS
	#define RMP_ASSERT(x, ...) { if(!(x)) { RMP_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); } }
	#define RMP_CORE_ASSERT(x, ...) { if(!(x)) { RMP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RMP_ASSERT(x, ...)
	#define RMP_CORET(x, ...)
#endif

#define BIT(x) (1 << x)
#define RMP_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)