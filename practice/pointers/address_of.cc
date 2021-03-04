#include <iostream>
#include <string>

// The address-of operator allows us to see the memory address of a variable.

int main(void) {
    int x{ 5 };
    std::cout << x << std::endl;  // print the value of x
    std::cout << &x << std::endl; // print the memory address of x

    // The address-of operator (&) doesn't return the address of its operand as a literal.
    //   Instead, it returns a pointer containing the address of the operand, whose type
    //   is derived from the argument (e.g. taking the address of an int will return
    //   the address in an int pointer).

    std::cout << typeid(&x).name() << std::endl; // prints int * in vs2019, and Pi (pointer to int) in gcc

    return 0;
}
