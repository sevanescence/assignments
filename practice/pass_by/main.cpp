#include <iostream>

void reassign(int*& ipr, int& m);

int main(void) {
    int n = 5;
    int m = 6;
    int* nptr = &n;
    std::cout << nptr << std::endl;
    reassign(nptr, m);
    std::cout << nptr << std::endl;
}

void reassign(int*& ipr, int& m) {
    ipr = &m;
}