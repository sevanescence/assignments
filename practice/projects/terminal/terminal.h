#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace terminal {
    class Event;
    struct Style;
    class ControlHandler;
    class Window;
    class Panel;
    class TextPanel;
    class RowPanel;

    class Event {
        private:
            std::string key;
            Window* window;
        public:
            std::string getKey();
            Window* getWindow();
            Event(std::string key, Window* window);
    };

    typedef void (*function)();
    typedef bool (*event_callback)(Event event);

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

    class Window {
        private:
            int length;
            std::vector<Panel> content;
            std::vector<ControlHandler> controllers;
        public:
            void addKeyController(std::string key, terminal::event_callback callback);
            void addContent(Panel panel);
            void render();
            void listen();
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