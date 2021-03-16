#include "terminal.h"

#include <iostream>
#include <codecvt>
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
    Event::Event(std::string key, Body* body) : key{ key }, body{ body } {}
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
    ControlHandler::ControlHandler(std::string key, Callback callback) 
        : key{ key }, callback{ callback } {}
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

    class TextBody;

    void TextBody::render(bool clear) {
        if (clear && std::system("CLS"))
            std::system("clear");
        
        std::u32string line;
        std::vector<std::u32string>::iterator it;
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
        for (it = content.begin(); it != content.end(); ++it) {
            line = (*it);
            std::cout << convert.to_bytes(line) << '\n';
        }
    }
    void TextBody::addContent(std::u32string line) {
        this->content.push_back(line);
    }
    void TextBody::addContent(std::string line) {
        std::u32string ln;
        for (auto c = line.begin(); c != line.end(); ++c) {
            char ch = *c;
            ln.push_back(ch);
        }
        addContent(ln);
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
