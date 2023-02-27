#include <GLFW/glfw3.h>
#include <Neko/Events/ApplicationEvent.h>
#include <Neko/Events/KeyEvent.h>
#include <Neko/Events/MouseEvent.h>
#include <Neko/Log.h>
#include <Neko/Platforms/LinuxWindow.h>
#include <Neko/Window.h>

namespace Neko {
static bool s_GLFWInitialized = false;

static void GLFWErrorCallback(int error,const char* description){
  NK_CORE_ERROR("GLFW Error ({0}):{1}",error,description);
}

Window* Window::Create(const WindowProps& props) {
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
    glfwSetErrorCallback(GLFWErrorCallback);
    s_GLFWInitialized = true;
  }
  m_Window = glfwCreateWindow((int)props.Width, (int)props.Height,
                              m_Data.Title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(m_Window);
  glfwSetWindowUserPointer(m_Window, &m_Data);
  SetVSync(true);

  // set GLFW callback
  glfwSetWindowSizeCallback(
      m_Window, [](GLFWwindow* window, int width, int height) {
        WindowData&       data = *(WindowData*)glfwGetWindowUserPointer(window);
        WindowResizeEvent event(width, height);
        data.Callback(event);
      });

  glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
    WindowData&      data = *(WindowData*)glfwGetWindowUserPointer(window);
    WindowCloseEvent event;
    data.Callback(event);
  });

  glfwSetKeyCallback(
      m_Window,
      [](GLFWwindow* window, int key, int scncode, int action, int mods) {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        switch (action) {
          case GLFW_PRESS: {
            KeyPressedEvent event(key, 0);
            data.Callback(event);
            break;
          }
          case GLFW_RELEASE: {
            KeyReleasedEvent event(key);
            data.Callback(event);
            break;
          }
          case GLFW_REPEAT: {
            KeyPressedEvent event(key, 1);
            data.Callback(event);
            break;
          }
        }
      });

  glfwSetMouseButtonCallback(
      m_Window, [](GLFWwindow* window, int button, int action, int mods) {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        switch (action) {
          case GLFW_PRESS: {
            MouseButtonPressedEvent event(button);
            data.Callback(event);
            break;
          }
          case GLFW_RELEASE: {
            MouseButtonReleasedEvent event(button);
            data.Callback(event);
            break;
          }
        }
      });

  glfwSetScrollCallback(
      m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        MouseScrolledEvent event((float)xOffset, (float)yOffset);
        data.Callback(event);
      });

  glfwSetCursorPosCallback(
      m_Window, [](GLFWwindow* window, double xpos, double ypos) {
        WindowData&     data = *(WindowData*)glfwGetWindowUserPointer(window);
        MouseMovedEvent event((float)xpos, (float)ypos);
        data.Callback(event);
      });
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

bool LinuxWindow::IsVSync() const { return m_Data.VSync; }

}  // namespace Neko