#include <iostream>
#include <string> // std::string
#include <random> // std::srand(unsigned int __seed), std::rand()
#include <ctime>  // std::time

void initRandSeed();
int  promptInt(std::string query);

int main(void) {
    initRandSeed(); // i felt like encapsulating this.
    int randnum = std::rand() % 99 + 1;

    int numguess;
    do {
        numguess = promptInt("Guess the generated number: ");

        if (numguess < randnum) {
            std::cout << "too low" << std::endl;
        } else if (numguess > randnum) {
            std::cout << "too high" << std::endl;
        }

        std::cin.clear();
        std::cin.ignore(123, '\n');
    } while (numguess != randnum);

    std::cout << "You guessed correctly! (" << randnum << ")" << std::endl;

    return 0;
}

void initRandSeed() {
    std::srand(std::time(nullptr));
}

int promptInt(std::string query) {
    std::cout << query;

    int num;
    if (! (std::cin >> num)) {
        std::cout << "TypeError: Input must be an integer." << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        return promptInt(query);
    }
    return num;
}