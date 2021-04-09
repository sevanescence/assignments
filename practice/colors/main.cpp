#include "./colors.cpp"

#include <iostream>
#include <string.h>

int main(int argc, char const *argv[]){
    std::cout << colors::ColoredText("%30test%0") << '\n';

    return 0;
}
