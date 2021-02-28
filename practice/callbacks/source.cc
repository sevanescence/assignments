#include <iostream>
#include "callback.h"

int main() {
    callback::incr(1, [](int n) {
        std::cout << n << std::endl;
    });
}
