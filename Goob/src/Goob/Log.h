#pragma once



#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
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
#define GOOB_CORE_TRACE(...) ::Goob::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GOOB_CORE_INFO(...)  ::Goob::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GOOB_CORE_WARN(...)  ::Goob::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GOOB_CORE_ERROR(...) ::Goob::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GOOB_CORE_CRITICAL(...) ::Goob::Log::GetCoreLogger()->critical(__VA_ARGS__)
		 
// Client Log Macros
#define GOOB_TRACE(...) ::Goob::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GOOB_INFO(...)  ::Goob::Log::GetClientLogger()->info(__VA_ARGS__)
#define GOOB_WARN(...)  ::Goob::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GOOB_ERROR(...) ::Goob::Log::GetClientLogger()->error(__VA_ARGS__)
#define GOOB_CRITICAL(...) ::Goob::Log::GetClientLogger()->critical(__VA_ARGS__)

