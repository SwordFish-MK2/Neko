#pragma once

#include <Neko/Event.h>

#include <sstream>

namespace Neko {
class WindowResizeEvent final : public Event {
  public:
  WindowResizeEvent(unsigned int width, unsigned int height)
      : m_Width(width), m_Height(height) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "WindowResizeEvent " << m_Width << ", " << m_Height;
    return ss.str();
  }
  EVENT_CLASS_TYPE(WindowResize)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)

  public:
  unsigned int m_Width, m_Height;
};

class WindowCloseEvent final : public Event {
  public:
  WindowCloseEvent() = default;

  EVENT_CLASS_TYPE(WindowClose)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppTickEvent final : public Event {
  public:
  AppTickEvent() = default;

  EVENT_CLASS_TYPE(AppTick)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppRenderEvent final : public Event {
  public:
  AppRenderEvent() = default;

  EVENT_CLASS_TYPE(AppRender)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppUpdateEvent final : public Event {
  public:
  AppUpdateEvent() = default;

  EVENT_CLASS_TYPE(AppUpdate)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

}  // namespace Neko
