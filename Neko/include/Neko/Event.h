#pragma once

#include<Neko/Core.h>

#include<string>
#include<functional>

namespace Neko{

    enum class EventType{
        None=0,
        WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,
        AppTick,AppUpdate,AppRender,
        KeyPressed,KeyReleased,
        MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
    };

    enum class EventCategory{
        None=0,
        EventCatagoryApplication=BIT(0),
        EventCatagoryInput=BIT(1),
        EventCatagoryKeyboard=BIT(2),
        EventCatagoryMouse=BIT(3),
        EventCatagoryMouseButton=BIT(4)
    };

    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::##type; }\
        virtual EventType GetEventType()const override{return GetStaticType();}\
        virtual const char* GetName()const override{return #type;}

    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags()const override{return category;}

    class NEKO_API Event{
        friend class EventDispatcher;
        public:
        virtual EventType GetEventType()const=0;
        virtual const char* GetName()const =0;
        virtual int GetCategoryFlags()const = 0;
        virtual std::string ToString()const{return GetName();}

        inline bool IsInCategory(EventCategory category){
            return GetCategoryFlags()&category;
        }
        
        protected:
        bool m_handled=false;
    };

    class EventDispatcher{
        template<class T>
        using EventFunc=std::function<bool(T&)>;
    }
}