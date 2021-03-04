#include <iostream>
#include <string>
#include <typeinfo>

// A pointer is a variable that holds a memory address as its value.

void test(int* x);

int main(void) {
    int* iPtr{}; // a pointer to an integer value
    double* dPtr{}; // a pointer to a double value

    // Best practice: When declaring a pointer variable,
    //  put the asterisk next to the type to make it
    //  easier to distinguish it from an indirection.

    // Assigning a value to a pointer

    int x{ 5 };
    int* ptr{ &x }; // initialize ptr with address of variable x

    std::cout << "\x1b[33mLine 22:   \x1b[0m" << &x << std::endl;  // print the address of x
    std::cout << "\x1b[33mLine 23:   \x1b[0m" << ptr << std::endl; // print the address that ptr is holding (x)

    test(&x);
    std::cout << "\x1b[33mLine 26:   \x1b[0m" << x << std::endl;

    return 0;
}

// \x1b[0m - reset
// \x1b[36m - cyan

// https://stackoverflow.com/a/41407246

void test(int* x) {
    std::cout << "\x1b[36mfrom test: \x1b[0m" << x << std::endl;  // prints the address of x
    std::cout << "\x1b[36mfrom test: \x1b[0m" << *x << std::endl; // prints the value of x
    *x = 7;
}