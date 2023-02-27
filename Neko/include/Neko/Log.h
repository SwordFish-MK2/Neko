#pragma once

#include <Neko/Core.h>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>

#include <memory>

namespace Neko {
class NEKO_API Log {
  public:
  static void Init();

  inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
    return s_CoreLogger;
  }
  inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
    return s_ClientLogger;
  }

  private:
  static std::shared_ptr<spdlog::logger> s_CoreLogger;
  static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
}  // namespace Neko

#define NK_CORE_ERROR(...) ::Neko::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NK_CORE_TRACE(...) ::Neko::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NK_CORE_WARN(...) ::Neko::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NK_CORE_INFO(...) ::Neko::Log::GetCoreLogger()->info(__VA_ARGS__)

#define NK_ERROR(...) ::Neko::Log::GetClientLogger()->error(__VA_ARGS__)
#define NK_TRACE(...) ::Neko::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NK_WARN(...) ::Neko::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NK_INFO(...) ::Neko::Log::GetClientLogger()->info(__VA_ARGS__)
