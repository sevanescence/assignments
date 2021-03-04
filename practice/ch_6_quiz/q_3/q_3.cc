#include <iostream>

// Complete the following program by writing the passOrFail() function, which should return true for the first 3 calls, and false thereafter.

bool passOrFail();

int main(void) {
    std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
}

bool passOrFail() {
    static int passes{ 3 };
    return (--passes >= 0);
}
