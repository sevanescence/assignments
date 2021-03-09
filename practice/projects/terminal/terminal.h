#ifndef TERMINAL_H
#define TERMINAL_H

#include <functional>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace terminal {
    struct Style;
    class Event;
    class ControlHandler;
    class Body;
    class TextBody;
    class Window;
    class Panel;
    class TextPanel;
    class RowPanel;

    class Event {
        private:
            std::string key;
            Body* body;
        public:
            std::string getKey();
            Body* getBody();
            Event(std::string key, Body* body);
            Window* getBodyAsWindow();
            TextBody* getBodyAsTextBody();
    };

    typedef void (*function)();
    //typedef lambda []bool (*event_callback)(Event event);
    typedef std::function<bool(Event)> event_callback;

    struct Style {
        public:
            int padleft;
            int padright;
            bool border;
    };

    class ControlHandler {
        private:
            std::string key;
            terminal::event_callback callback;
        public:
            std::string getKey();
            terminal::event_callback getCallback();
            ControlHandler();
            ControlHandler(std::string, terminal::event_callback callback);
            void setKey(std::string key);
            void setCallback(terminal::event_callback callback);
    };

    class Body {
        private:
            int length;
            std::vector<ControlHandler> controllers;
        public:
            void addKeyController(std::string key, terminal::event_callback callback);
            virtual void render(bool clear);
            void listen();
    };

    class TextBody : public Body {
        private:
            std::vector<std::u32string> content;
        public:
    };

    class Window : public Body {
        private:
            std::vector<Panel> content;
        public:
            void addContent(Panel panel);
            void render(bool clear) override;
    };

    class Panel {
        private:
            Style style;
        public:
            Style getStyle();
    };

    class TextPanel : public Panel {
        private:
            std::u32string text;
        public:
            std::string getText();
            TextPanel();
            void setText(std::string text);
            void setText(std::u32string text);
    };

    class RowPanel : Panel {

    };
}

#endif
