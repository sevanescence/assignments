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
    class Body;
    class TextBody;
    class Window;
    class Panel;
    class TextPanel;
    class RowPanel;


    class Event;
    
    std::string Event::getKey() {
        return this->key;
    }
    Body* Event::getBody() {
        return this->body;
    }
    Event::Event(std::string key, Body* body) {
        this->key = key;
        this->body = body;
    }
    Window* Event::getBodyAsWindow() {
        return (Window*) this->body;
    }
    TextBody* Event::getBodyAsTextBody() {
        return (TextBody*) this->body;
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

    class Body;

    void Body::addKeyController(std::string key, Callback callback) {
        this->controllers.push_back(ControlHandler(key, callback));
    }
    void Body::render(bool clear) {
        if (clear && std::system("CLS"))
            std::system("clear");
    }
    void Body::listen() {
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

    class Window;

    void Window::addContent(Panel panel) {
        this->content.push_back(panel);
    }
    void Window::render(bool clear) {
        if (clear && std::system("CLS"))
            std::system("clear");
        std::cout << "Hello, world!" << std::endl;
    }

}
