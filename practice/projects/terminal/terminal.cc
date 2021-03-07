#include "terminal.h"

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using Callback = terminal::event_callback;

namespace terminal {

    // class declarations
    struct Style;
    class Event;
    class ControlHandler;
    class Window;
    class Panel;
    class TextPanel;
    class RowPanel;


    class Event;
    
    std::string Event::getKey() {
        return this->key;
    }
    Window* Event::getWindow() {
        return this->window;
    }
    Event::Event(std::string key, Window* window) {
        this->key = key;
        this->window = window;
    }

    class ControlHandler;

    std::string ControlHandler::getKey() {
        return this->key;
    }
    Callback ControlHandler::getCallback() {
        return this->callback;
    }
    ControlHandler::ControlHandler(std::string key, Callback callback) {
        this->key = key;
        this->callback = callback;
    }
    void ControlHandler::setKey(std::string key) {
        this->key = key;
    }
    void ControlHandler::setCallback(Callback callback) {
        this->callback = callback;
    }

    class Window;

    void Window::addKeyController(std::string key, Callback callback) {
        this->controllers.push_back(ControlHandler(key, callback));
    }
    void Window::addContent(Panel panel) {
        this->content.push_back(panel);
    }
    void Window::render() {
        if (std::system("CLS"))
            std::system("clear");
        std::cout << "Hello, world!" << std::endl;
    }
    void Window::listen() {
        std::string input;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(input.length(), '\n');
        
        bool close;
        std::vector<ControlHandler>::iterator it;
        for (it = controllers.begin(); it != controllers.end(); ++it) {
            ControlHandler handler { (*it) };
            if (input.compare(handler.getKey()) == 0) {
                close = handler.getCallback()(Event(handler.getKey(), this));
            }
        }
        if (! close) {
            listen();
        }
    }

}
