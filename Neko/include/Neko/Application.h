#include <Neko/Core.h>
#include <Neko/Window.h>

#include <memory>

namespace Neko {

class NEKO_API Application {
  public:
  Application();
  virtual ~Application();
  void Run();

  private:
  std::unique_ptr<Window> m_Window;
  bool m_Running=true;
};

Application* CreateApplication();

}  // namespace Neko