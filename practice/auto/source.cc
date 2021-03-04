#include <iostream>
#include <string>

auto incr(int x) -> int; // not very conventional (because it's redundant) but looks cool!

int main(void) {
    auto i{ 1 + 2 }; // 1 + 2 evaluates to an int, so i will be type int
    auto d{ 5.0 };   // 5.0 is a double literal, so d will be type double

    std::cout << i << std::endl;
    std::cout << d << std::endl;
    std::cout << incr(1) << std::endl;

    return 0;
}

auto incr(int x) -> int {
    return ++x;
}