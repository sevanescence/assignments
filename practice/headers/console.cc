#include "console.h"
#include <iostream>

std::string console::prompt(std::string query) {
    std::cout << query;
    std::string in;

    std::cin >> in;
    return in;
}

double console::promptDouble(std::string query) {
    std::cout << query;
    double in;
    if (! (std::cin >> in)) {
        throw "TypeError: Excepted number response @promptDouble";
        return 0;
    }
    return in;
}

double console::promptDouble(std::string query, double def) {
    std::cout << query;
    double in;
    if (! (std::cin >> in)) {
        return def;
    }
    return in;
}

