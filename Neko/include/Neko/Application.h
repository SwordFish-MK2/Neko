#include <Neko/Core.h>

namespace Neko {
class NEKO_API Application {
public:
  Application();
  virtual ~Application();
  void Run();
};

Application* CreateApplication();

}  // namespace NEko