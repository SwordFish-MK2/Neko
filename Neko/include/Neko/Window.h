#pragma once

#include <Neko/Core.h>
#include <Neko/Event.h>

#include <string>

namespace Neko {

struct WindowProps {
  std::string  Title;
  unsigned int Width;
  unsigned int Height;

  WindowProps(const std::string& title  = "Neko Engine",
              unsigned int       width  = 1280,
              unsigned int       height = 720)
      : Title(title), Width(width), Height(height) {}
};

class NEKO_API Window {
  public:
  using EventCallbackFunc = std::function<void(Event&)>;

  virtual ~Window() {}

  virtual unsigned int GetWidth() const  = 0;
  virtual unsigned int GetHeight() const = 0;

  virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;

  virtual void SetVSync(bool enable) = 0;

  virtual bool IsVSync() const = 0;

  virtual void OnUpdate()=0;

  static Window* Create(const WindowProps& props=WindowProps());
};


}  // namespace Neko