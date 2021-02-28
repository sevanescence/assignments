#include <iostream>

int main() {
    int inches;
    std::cout << "Enter your height in inches: ";

    if (! (std::cin >> inches)) {
        std::cout << "Input must be an integer." << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        main();
    }

    int ft = inches / 12;
    int rm = inches % 12;
    std::cout << "Height: " << ft << " ft " << rm << " in." << std::endl;
}