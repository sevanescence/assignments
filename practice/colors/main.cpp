#include "./colors.cpp"

#include <iostream>
#include <string.h>

int main(int argc, char const *argv[]){
    std::cout << colors::ColoredText("%1test %2test %3test %4test %0") << '\n';
    
    return 0;
}
