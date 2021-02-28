#include <iostream>

#include "console.h"

int main(int argc, const char *argv[]) {
    std::string s = console::prompt("What is your name? ");
    std::cout << "Hello " << s << "!" << std::endl;
    double num = console::promptDouble("Enter a number: ");
    std::cout << "You entered " << num << std::endl;
}