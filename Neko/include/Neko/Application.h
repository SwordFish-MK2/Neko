#include <Neko/Core.h>
#include <Neko/Window.h>

#include <memory>
#include "Neko/Events/ApplicationEvent.h"

namespace Neko {

class NEKO_API Application {
  public:
  Application();
  virtual ~Application();
  void Run();

  void OnEvent(Event& e);

  private:
  bool OnWindowClose(WindowCloseEvent& e);

  std::unique_ptr<Window> m_Window;
  bool m_Running=true;
};

Application* CreateApplication();

}  // namespace Neko