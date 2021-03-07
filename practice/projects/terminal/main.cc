#include "terminal.h"

#include <iostream>
#include <cassert>
#include <string>
#include <regex>

// todo add default handler (in case nothing executes)

int main(int argc, char const *argv[]) {
    terminal::Window window;

    window.addKeyController("0", [](terminal::Event event) {
        std::system("clear");
        std::cout << "goodbye!" << std::endl;
        return true;
    });

    window.render();
    std::cout << "Type 0 to close: ";
    window.listen();

    return 0;
}