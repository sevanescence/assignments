#include "callback.h"
#include <iostream>

void callback::incr(int n, void (*f)(int)) {
    (*f)(++n);
}
