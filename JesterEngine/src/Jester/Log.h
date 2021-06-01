#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Jester {
	class JESTER_API Log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}


// Core log macros
#define JS_CORE_ERROR(...)    ::Jester::Log::getCoreLogger()->error(__VA_ARGS__)
#define JS_CORE_INFO(...)     ::Jester::Log::getCoreLogger()->info(__VA_ARGS__)
#define JS_CORE_WARN(...)     ::Jester::Log::getCoreLogger()->warn(__VA_ARGS__)
#define JS_CORE_TRACE(...)    ::Jester::Log::getCoreLogger()->trace(__VA_ARGS__)
#define JS_CORE_FATAL(...)    ::Jester::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define JS_ERROR(...)    ::Jester::Log::getClientLogger()->error(__VA_ARGS__)
#define JS_INFO(...)     ::Jester::Log::getClientLogger()->info(__VA_ARGS__)
#define JS_WARN(...)     ::Jester::Log::getClientLogger()->warn(__VA_ARGS__)
#define JS_TRACE(...)    ::Jester::Log::getClientLogger()->trace(__VA_ARGS__)
#define JS_FATAL(...)    ::Jester::Log::getClientLogger()->fatal(__VA_ARGS__)