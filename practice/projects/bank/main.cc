#include "terminal.h"

#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
    //std::stringstream sstream{};

    for (int i = 1; i < argc-1; i++) {
        terminal::sstream << argv[i] << " ";
    }
    terminal::sstream << argv[argc-1] << '\n';
    terminal::sstream << "How are you?" << '\n';

    int length { terminal::getLongestLine(&terminal::sstream) };
    std::cout << length << std::endl;

    terminal::setLength(length);
    terminal::printBorderTop();
    terminal::printToolbar("[x] - Return");
    terminal::print();
    terminal::printBottom();

    std::cin.get();
}