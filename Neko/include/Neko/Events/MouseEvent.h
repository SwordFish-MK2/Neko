#pragma once

#include <Neko/Event.h>

#include <iostream>
#include <sstream>

namespace Neko {
class MouseMovedEvent final : public Event {
  public:
  // functions
  MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
    return ss.str();
  }

  EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
  EVENT_CLASS_TYPE(MouseMoved)

  public:
  // datas
  float m_MouseX, m_MouseY;
};

class MouseScrolledEvent final : public Event {
  public:
  MouseScrolledEvent(float x, float y) : m_XOffset(x), m_YOffset(y) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseScrolledEvent " << m_XOffset << ", " << m_YOffset;
    return ss.str();
  }
  EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
  EVENT_CLASS_TYPE(MouseScrolled)

  public:
  // data
  float m_XOffset, m_YOffset;
};

// Mouse button virtual class
class MouseButtonEvent : public Event {
  public:
  EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton |
                       EventCategoryInput)
  protected:
  MouseButtonEvent(int button) : m_Button(button) {}

  public:
  // data
  int m_Button;
};

class MouseButtonPressedEvent final : public MouseButtonEvent {
  public:
  MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseButtonPressedEvent " << m_Button;
    return ss.str();
  }
  EVENT_CLASS_TYPE(MouseButtonPressed)
};

class MouseButtonReleasedEvent final : public MouseButtonEvent {
  public:
  MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent " << m_Button;
    return ss.str();
  }

  EVENT_CLASS_TYPE(MouseButtonReleased)
};

}  // namespace Neko