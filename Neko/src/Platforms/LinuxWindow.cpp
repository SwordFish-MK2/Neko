#include <GLFW/glfw3.h>
#include <Neko/Log.h>
#include <Neko/Platforms/LinuxWindow.h>
#include "Neko/Window.h"

namespace Neko {
static bool s_GLFWInitialized = false;

Window* Window::Create(const WindowProps& props){
    return new LinuxWindow(props);
}

LinuxWindow::LinuxWindow(const WindowProps& props) { Init(props); }

LinuxWindow::~LinuxWindow() { ShutDown(); }

void LinuxWindow::Init(const WindowProps& props) {
  m_Data.Title  = props.Title;
  m_Data.Width  = props.Width;
  m_Data.Height = props.Height;

  NK_CORE_INFO("Createing window {0} {1} {2}", props.Title, props.Width,
               props.Height);

  if (!s_GLFWInitialized) {
    int success = glfwInit();
    NK_CORE_ASSERT(success, "Could not initialize GLFW!");

    s_GLFWInitialized = true;
  }
  m_Window = glfwCreateWindow((int)props.Width, (int)props.Height,
                              m_Data.Title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(m_Window);
  glfwSetWindowUserPointer(m_Window, &m_Data);
  SetVSync(true);
}

void LinuxWindow::ShutDown() { glfwDestroyWindow(m_Window); }

void LinuxWindow::OnUpdate() {
  glfwPollEvents();
  glfwSwapBuffers(m_Window);
}

void LinuxWindow::SetVSync(bool enabled) {
  if (enabled)
    glfwSwapInterval(1);
  else
    glfwSwapInterval(0);
  m_Data.VSync = enabled;
}

bool LinuxWindow::IsVSync()const{
    return m_Data.VSync;
}

}  // namespace Neko