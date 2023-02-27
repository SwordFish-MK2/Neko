#pragma once

#include <Neko/Core.h>

#include <functional>
#include <iostream>
#include <string>

namespace Neko {

enum class EventType {
  None = 0,
  WindowClose,
  WindowResize,
  WindowFocus,
  WindowLostFocus,
  WindowMoved,
  AppTick,
  AppUpdate,
  AppRender,
  KeyPressed,
  KeyReleased,
  MouseButtonPressed,
  MouseButtonReleased,
  MouseMoved,
  MouseScrolled
};

enum EventCategory {
  None                     = 0,
  EventCategoryApplication = BIT(0),
  EventCategoryInput       = BIT(1),
  EventCategoryKeyboard    = BIT(2),
  EventCategoryMouse       = BIT(3),
  EventCategoryMouseButton = BIT(4)
};

#define EVENT_CLASS_TYPE(type)                                                  \
  static EventType    GetStaticType() { return EventType::type; }               \
  virtual EventType   GetEventType() const override { return GetStaticType(); } \
  virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)                                         \
  virtual int GetCategoryFlags() const override { return category; }

class NEKO_API Event {
  friend class EventDispatcher;

  public:
  virtual EventType   GetEventType() const     = 0;
  virtual const char *GetName() const          = 0;
  virtual int         GetCategoryFlags() const = 0;
  virtual std::string ToString() const { return GetName(); }

  inline bool IsInCategory(EventCategory category) {
    return GetCategoryFlags() & category;
  }

  protected:
  bool m_handled = false;
};

class EventDispatcher {
  template <class T>
  using EventFunc = std::function<bool(T &)>;

  public:
  EventDispatcher(Event &event) : m_event(event) {}

  template <class T>
  bool Dispath(EventFunc<T> func) {
    if (m_event.GetEventType() == T::GetStaticType()) {
      m_event.m_handled = func(*(T *)&m_event);
      return true;
    }
    return false;
  }

  private:
  Event &m_event;
};

inline std::ostream &operator<<(std::ostream &os, const Event &e) {
  return os << e.ToString();
}
}  // namespace Neko