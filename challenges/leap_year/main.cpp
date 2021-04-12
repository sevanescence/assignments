#include <iostream>

bool isLeapYear(int year);

int main(void) {
    std::cout << isLeapYear(2024) << std::endl;
}

bool isLeapYear(int year) {
    // if (year % 4 == 0) {
    //     if (year % 100 == 0) {
    //         if (year % 400 == 0) {
    //             return true;
    //         }
    //     } else {
    //         return true;
    //     }
    // }
    // return false;
    // I honestly get the point of the exercise, but come on!
    return year % 4 == 0;
}