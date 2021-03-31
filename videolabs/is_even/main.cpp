#include <iostream>

// Makoto Miyamoto
// COSC 1436
// Boolean Functions - is_even

bool is_even(int& n);

int main(void) {
    int num;
    char c;
    
    while (true) {
        std::cout << "Enter an integer: ";
        std::cin >> num;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        std::cout << "Number is " << (is_even(num) ? "even" : "odd") << std::endl;

        std::cout << "Run again? (Y/n) ";
        std::cin >> c;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        if (toupper(c) != 'Y') {
            break;
        }
    }
}

bool is_even(int& n) {
    return n % 2 == 0;
}