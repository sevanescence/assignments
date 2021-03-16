#include "terminal.h"

#include <iostream>
#include <typeinfo>
#include <cassert>
#include <string>
#include <regex>

// todo add default handler (in case nothing executes)
// todo add prefix option to allow for dynamic input

int main(int argc, char const *argv[]) {
    terminal::TextBody body;

    body.addContent("Hello");
    body.addContent("Controls:");
    body.addContent("0 - exit");
    body.addContent("1 - re-render");
    body.addContent("2 - print Testing to console");

    body.addKeyController("0", [](terminal::Event event) {
        if (std::system("CLS")) std::system("clear");
        return true;
    });
    body.addKeyController("1", [](terminal::Event event) {
        (*event.getBody()).render(true);
        return false;
    });
    body.addKeyController("2", [](terminal::Event event) {
        std::cout << "Testing" << std::endl;
        return false;
    });

    body.render(true);
    body.listen();

    return 0;
}