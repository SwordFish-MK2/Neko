#include <Neko/Log.h>
#include <spdlog/common.h>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include<spdlog/sinks/stdout_color_sinks.h>
#include <memory>

namespace Neko {
std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init() {
  spdlog::set_pattern("%^[%T] %n: %v$");
  s_CoreLogger = spdlog::stdout_color_mt("Neko");
  s_CoreLogger->set_level(spdlog::level::trace);

  s_ClientLogger=spdlog::stdout_color_mt("App");
  s_ClientLogger->set_level(spdlog::level::trace);
}
}  // namespace Neko