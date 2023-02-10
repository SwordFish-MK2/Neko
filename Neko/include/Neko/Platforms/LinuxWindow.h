#pragma once

#include <GLFW/glfw3.h>
#include <Neko/Window.h>

namespace Neko {
class LinuxWindow : public Window {
  public:
  LinuxWindow(const WindowProps& props);
  virtual ~LinuxWindow();

  inline unsigned int GetWidth() const override { return m_Data.Width; }
  inline unsigned int GetHeight() const override { return m_Data.Height; }

  inline void SetEventCallback(const EventCallbackFunc& callback) override {
    m_Data.Callback = callback;
  }
  void SetVSync(bool enabled) override;
  bool IsVSync() const override;

  void OnUpdate() override;

  private:
  virtual void Init(const WindowProps& props);
  virtual void ShutDown();

  private:
  GLFWwindow* m_Window;

  struct WindowData {
    std::string       Title;
    unsigned int      Width, Height;
    EventCallbackFunc Callback;
    bool VSync=false;
  };

  WindowData m_Data;
};
}  // namespace Neko