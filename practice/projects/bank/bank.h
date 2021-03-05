#include <iostream>
#include <map>

#ifndef BANK_H
#define BANK_H

namespace bank {
    class Windows {
        public:
            static std::map<int, void(*)(int)> menus;
            Windows();
            void start();
            static void nav(int, int);
            static void menu(int);
            static void test(int);
    };
};

#endif