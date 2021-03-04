#include "constants.h"

#include <iostream>

// Write a file named constants.h that makes the following program run.

int main(void) {
    std::cout << "How many students are in your class? ";
    int students{};
    std::cin >> students;

    if (students > constants::max_class_size) {
        std::cout << "There are too many students in this class." << std::endl;
    } else {
        std::cout << "This class isn't too large." << std::endl;
    }

    return 0;
}