#include <Neko/Application.h>
#include <Neko/Log.h>

#include <memory>

#include "Neko/Event.h"
#include "Neko/Events/ApplicationEvent.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Neko {
Application::Application() {
  m_Window = std::unique_ptr<Window>(Window::Create());
  m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Application::~Application() {}

void Application::Run() {
  while (m_Running) { m_Window->OnUpdate(); }
}
void Application::OnEvent(Event& e) {
  EventDispatcher dispather(e);
  dispather.Dispath<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
  NK_CORE_TRACE("{0}", e.ToString());
}

bool Application::OnWindowClose(WindowCloseEvent& e) {
  m_Running = false;
  return false;
}
}  // namespace Neko