#include <iostream>

// Makoto Miyamoto
// COSC 1436
// Pass by Value and Reference

/*
 * TODO: Create a swap function
 *       exchange the values between
 *       two integers.
 *       Know difference between "pass
 *       by value" and "pass by reference 
*        (pointer)"
*/

void swap(int& n1, int& n2);

int main(void) {
    int n1 = 20;
    int n2 = 30;

    std::cout << "Address of n1: " << &n1 << std::endl;
    std::cout << "Address of n2: " << &n2 << std::endl;

    std::cout << "Numbers before swap: " << n1 << ", " << n2 << std::endl;
    swap(n1, n2);
    std::cout << "Numbers after swap:  " << n1 << ", " << n2 << std::endl;

    return 0;
}

void swap(int& n1, int& n2) {
    std::cout << "Address of n1: " << &n1 << std::endl;
    std::cout << "Address of n2: " << &n2 << std::endl;
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}