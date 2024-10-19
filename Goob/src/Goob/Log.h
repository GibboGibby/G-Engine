#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Goob
{
	class GOOB_API Log
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

// Core Log Macros
#define GB_CORE_TRACE(...) ::Goob::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GB_CORE_INFO(...)  ::Goob::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GB_CORE_WARN(...)  ::Goob::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GB_CORE_ERROR(...) ::Goob::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GB_CORE_FATAL(...) ::Goob::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define GB_TRACE(...) ::Goob::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GB_INFO(...)  ::Goob::Log::GetClientLogger()->info(__VA_ARGS__)
#define GB_WARN(...)  ::Goob::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GB_ERROR(...) ::Goob::Log::GetClientLogger()->error(__VA_ARGS__)
#define GB_FATAL(...) ::Goob::Log::GetClientLogger()->fatal(__VA_ARGS__)