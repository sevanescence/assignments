#include "unit.h"

#include <iostream>

namespace unit {
    class Test;

    int Test::getNum() { return num; }
    Test::Test(int _num) : num{ _num } {}
    void Test::print() {
        this->num = 15;
        std::cout << "Hello!" << std::endl;
    }

    class Impl;

    std::string Impl::getStr() { return str; }
    Impl::Impl(std::string _str) : Test(2), str{ _str } {}
}