#include "terminal.h"

#include <iostream>
#include <typeinfo>
#include <cassert>
#include <string>
#include <regex>

// todo add default handler (in case nothing executes)
// todo add prefix option to allow for dynamic input

int main(int argc, char const *argv[]) {
    //terminal::Window window, modal;
    terminal::Window window;
    terminal::Window modal;

    window.addKeyController("0", [&modal](terminal::Event event) {
        std::cout << "Displaying modal" << std::endl;
        modal.render(false);
        return false;
    });
    window.addKeyController("1", [](terminal::Event event) {
        (*event.getBody()).render(true);
        return false;
    });
    window.addKeyController("exit", [](terminal::Event event) {
        if (std::system("CLS"))
            std::system("clear");
        return true;
    });

    window.render(true);
    window.listen();

    return 0;
}