#pragma once

#include <memory>

#include "Core.h"
#include "spdlog\spdlog.h"

namespace Ramp
{
	class RAMP_API Log
	{ 
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define RMP_CORE_TRACE(...) ::Ramp::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define RMP_CORE_INFO(...) ::Ramp::Log::GetCoreLogger()->info(__VA_ARGS__);
#define RMP_CORE_WARN(...) ::Ramp::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define RMP_CORE_ERROR(...) ::Ramp::Log::GetCoreLogger()->error(__VA_ARGS__);
#define RMP_CORE_FATAL(...) ::Ramp::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define RMP_TRACE(...)     ::Ramp::Log::GetClientLogger()->trace(__VA_ARGS__);
#define RMP_INFO(...)      ::Ramp::Log::GetClientLogger()->info(__VA_ARGS__);
#define RMP_WARN(...)      ::Ramp::Log::GetClientLogger()->warn(__VA_ARGS__);
#define RMP_ERROR(...)     ::Ramp::Log::GetClientLogger()->error(__VA_ARGS__);
#define RMP_FATAL(...)     ::Ramp::Log::GetClientLogger()->fatal(__VA_ARGS__);

