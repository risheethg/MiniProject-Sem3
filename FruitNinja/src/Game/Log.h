#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Engine {

	class Log
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

///Logger Macros 
#define ENGINE_CORE_TRACE(...)  ::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define ENGINE_CORE_INFO(...)   ::Engine::Log::GetCoreLogger()->info(__VA_ARGS__);
#define ENGINE_CORE_WARN(...)   ::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define ENGINE_CORE_ERROR(...)  ::Engine::Log::GetCoreLogger()->error(__VA_ARGS__);
#define ENGINE_CORE_FATAL(...)  ::Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define ENGINE_TRACE(...)  ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__);
#define ENGINE_INFO(...)   ::Engine::Log::GetClientLogger()->info(__VA_ARGS__);
#define ENGINE_WARN(...)   ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__);
#define ENGINE_ERROR(...)  ::Engine::Log::GetClientLogger()->error(__VA_ARGS__);
#define ENGINE_FATAL(...)  ::Engine::Log::GetClientLogger()->fatal(__VA_ARGS__);

#ifdef ENGINE_ENABLE_ASSERTS
#define ENGINE_ASSERT(x, ...) { if(!x) { ENGINE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak();} }
#define ENGINE_CORE_ASSERT(x, ...) { if(!x) { ENGINE_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak();} }
#else 
#define ENGINE_ASSERT(x, ...)
#define ENGINE_CORE_ASSERT(x, ...)
#endif

#define ENGINE_EVENT_BIND_FN(Fn) std::bind(&Fn, this, std::placeholders::_1)