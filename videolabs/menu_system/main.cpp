#include <functional>
#include <iostream>
#include <string>

// Makoto Miyamoto
// COSC 1436
// Menu System (Linux/Windows compatible)

void DisplayMenu();
void Cat();
void Dog();
void Cow();
void clr();

int main(void) {
    clr();

    bool previousInvalid = false;
    int choice;
    while (choice != 4) {
        DisplayMenu();

        if (previousInvalid) {
            std::cout << "Invalid input. Select a number from 1-4\n> ";
        } else {
            std::cout << "> ";
        } // using a ternary operator did some weird stuff :(
        previousInvalid = false;
        std::cin >> choice;

        switch (choice) {
            case 1:
                Cat();
                break;
            case 2:
                Dog();
                break;
            case 3:
                Cow();
                break;
            case 4:
                clr();
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                previousInvalid = true;
                break;
        }
        std::cin.get();
        std::cin.clear();
        std::cin.ignore(123, '\n');
        clr();
    }

    return 0;
}

void DisplayMenu() {
    std::cout << "1. Cat" << '\n'
              << "2. Dog" << '\n'
              << "3. Cow" << '\n'
              << "4. Exit" << std::endl;
}

void Cat() {
    std::cout << "Nyan uwu";
}

void Dog() {
    std::cout << "Bark.";
}

void Cow() {
    std::cout << "Moo :)";
}

void clr() {
    if (std::system("clear"))
        std::system("cls");
}