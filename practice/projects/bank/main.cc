#include "terminal.h"

#include <iostream>
#include <sstream>

/* 
but ill consider adding it as an optional setting
the only catch with println is that it wont affect the size of the box
i could probably add a function like terminal::render or something but /shrug
hmm maybe ill do that actually 
*/

int main(int argc, char const *argv[]) {
    //std::stringstream sstream{};

    // for (int i = 1; i < argc-1; i++) {
    //     terminal::sstream << argv[i] << " ";
    // }
    // terminal::sstream << argv[argc-1] << '\n';
    // terminal::sstream << "How are you?" << '\n';

    terminal::sstream << "Hello :)" << '\n';
    terminal::sstream << "How are you?" << '\n';
    terminal::sstream << "This window is pretty cool" << '\n';
    terminal::sstream << "This is a very long line of text that will stretch the window to it's max" << '\n';

    int len{};
    terminal::setLength(24 > (len = terminal::getLongestLine(&terminal::sstream)) ? 24 : len );

    terminal::printBorderTop();
    // terminal::print();
    terminal::printEach(&terminal::sstream, []{
        terminal::printRow();
    });
    terminal::println("A fifth line!");
    terminal::printBottom();

    // int length { terminal::getLongestLine(&terminal::sstream) };
    // std::cout << length << std::endl;

    // terminal::setLength(length);
    // terminal::printBorderTop();
    // terminal::printToolbar("[x] - Return");
    // terminal::print();
    // terminal::printBottom();

    std::cin.get();
}