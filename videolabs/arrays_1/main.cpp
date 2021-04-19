#include <iostream>
#include <string.h>

int main(void) {
    /**
     * Declare an array
     * use named constant
     * assign values to array
     * display the array
     * array initialization list
     */

    const int SIZE = 5;
    int numbers[SIZE]; // int array of size 5

    numbers[0] = 44;
    numbers[1] = 33;
    numbers[2] = 22;
    numbers[3] = 11;
    numbers[4] = 55;
    // for (int i = 44; i >= 11; i -= 11) {
    //     int loc = SIZE - 1 - (int) (i / 10);
    //     numbers[loc] = i;
    // } // ignore this, was just doodling

    for (int i = 0; i < SIZE; i++) {
        std::cout << numbers[i] << '\n';
    }

    for (int i = 0; i < SIZE; i++) {
        std::cout << "Enter value: " << i << ": ";
        std::cin >> numbers[i];
    }

    for (int i = 0; i < SIZE; i++) {
        std::cout << numbers[i] << '\n';
    }

    std::string names[] = { "Homer", "Bart", "Lisa", "Marge", "Maggie" };

    for (int i = 0; i < SIZE; i++) {
        std::cout << names[i] << '\n';
    }

}