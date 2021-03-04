#include <iostream>
#include <string>

// The indirection operator allows you to fetch the value of
// at the memory address of a variable rather than the
// address itself.

int main(void) {
    int x{ 5 };
    std::cout << x << std::endl;     // print the value of x
    std::cout << &x << std::endl;    // print the memory address of x
    std::cout << *(&x) << std::endl; // print the value at the memory address of x (parenthesis not required)

    return 0;
}
