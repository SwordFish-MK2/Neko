#pragma once

#include <Neko/Event.h>

#include <sstream>

#include "Neko/Core.h"

namespace Neko {
class NEKO_API KeyEvent : public Event {
  public:
  // interfaces
  EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
  public:
  // public data
  int m_KeyCode;

  protected:
  KeyEvent(int code) : m_KeyCode(code) {}
};

class NEKO_API KeyPressedEvent final : public KeyEvent {
  public:
  KeyPressedEvent(int code, int rc) : KeyEvent(code), m_RepeatCount(rc) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount
       << "repeats)";
    return ss.str();
  }
  EVENT_CLASS_TYPE(KeyPressed)

  private:
  int m_RepeatCount;
};

class NEKO_API KeyReleasedEvent final : public KeyEvent {
  public:
  KeyReleasedEvent(int code) : KeyEvent(code) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyReleasedEvent " << m_KeyCode;
    return ss.str();
  }

  EVENT_CLASS_TYPE(KeyReleased)
};

}  // namespace Neko
