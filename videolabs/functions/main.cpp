#include <iostream>

// Makoto Miyamoto
// COSC 1436
// Literally every single one of my assignments has these

// function prototype
int calculateArea(int length, int width);

int main(void) {
    int length, width, area;
    std::cout << "Enter the length: ";
    std::cin >> length;
    std::cout << "Enter the width: ";
    std::cin >> width;

    area = calculateArea(length, width); // function call

    std::cout << area << std::endl;
    return 0;
}

// function definition
int calculateArea(int length, int width) {
    int area = 0; // output of the function
    area = length * width;
    return area;
}