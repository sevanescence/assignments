#include "./terminal.h"
#include "bank.h"

#include <iostream>
#include <map>

namespace bank {
    std::map<int, void(*)(int)> Windows::menus;
    Windows::Windows() {
        menus.insert( std::pair<int, void(*)(int)>(0, menu) );
        menus.insert( std::pair<int, void(*)(int)>(1, test) );
    }
    void Windows::start() {
        this->nav(-1, 0);
    }
    void Windows::nav(int tab, int to) {
        terminal::clear();
        if (tab > -1) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
        }

        std::cout << "╔══════════════════════════════════════════╗" << std::endl;
        std::cout << "║\x1b[31m[x] - Return\x1b[0m                              ║" << std::endl;
        std::cout << "╠══════════════════════════════════════════╣" << std::endl;
        
        int current{};                                           //
        std::map<int, void(*)(int)>::iterator it = menus.find(to);
        if (it == menus.end()) {
            current = tab;
            menus.at(current)(current);
            std::cout << "\x1b[31mWindow #" << to << " is not a valid input.\x1b[0m" << std::endl;
        } else {
            current = to;
            menus.at(current)(current);
        }

        int next;
        std::cin >> next;
        Windows::nav(current, next);
    }
    void Windows::menu(int tab) {
        std::cout << "║Customer Account Banking Management System║" << '\n';
        std::cout << "║\x1b[1m████████\x1b[0m Welcome to the Main Menu \x1b[1m████████\x1b[0m║" << '\n';
        std::cout << "║\x1b[36m1.\x1b[0m Create new account                     ║" << '\n';
        std::cout << "║\x1b[36m2.\x1b[0m Update information of existing account ║" << '\n';
        std::cout << "║\x1b[36m3.\x1b[0m For transactions                       ║" << '\n';
        std::cout << "║\x1b[36m4.\x1b[0m Check the details of existing account  ║" << '\n';
        std::cout << "║\x1b[36m5.\x1b[0m Removing existing account              ║" << '\n';
        std::cout << "║\x1b[36m6.\x1b[0m View customer's list                   ║" << '\n';
        std::cout << "║\x1b[36m7.\x1b[0m Exit                                   ║" << '\n';
        std::cout << "╚══════════════════════════════════════════╝" << std::endl;
    }
    void Windows::test(int tab) {
        std::cout << "test" << std::endl;
    }
}
