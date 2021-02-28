#include <iostream>

namespace console {
    std::string prompt(std::string query);
    double promptDouble(std::string query);
    double promptDouble(std::string query, double def);
    double nextDouble();
}
