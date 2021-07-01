#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Coffee
{
	class COFFEE_API Log
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

#define CF_CORE_FATAL(...)     ::Coffee::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define CF_CORE_ERROR(...)     ::Coffee::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CF_CORE_WARN(...)      ::Coffee::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CF_CORE_INFO(...)      ::Coffee::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CF_CORE_TRACE(...)     ::Coffee::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define CF_CLIENT_FATAL(...)   ::Coffee::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define CF_CLIENT_ERROR(...)   ::Coffee::Log::GetClientLogger()->error(__VA_ARGS__)
#define CF_CLIENT_WARN(...)    ::Coffee::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CF_CLIENT_INFO(...)    ::Coffee::Log::GetClientLogger()->info(__VA_ARGS__)
#define CF_CLIENT_TRACE(...)   ::Coffee::Log::GetClientLogger()->trace(__VA_ARGS__)


