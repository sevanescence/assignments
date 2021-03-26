#include <functional>
#include <iostream>
#include <string>
#include <map>

void menu(std::string query);
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
void clear(bool clr);

int main(void) {
    if (std::system("clear")) std::system("cls");
    menu("Welcome to my calculator! Select a function:");

    return 0;
}

void menu(std::string query) {
    std::cout << query << '\n';
    std::cout << "+ : Add two numbers" << '\n';
    std::cout << "- : Subtract two numbers" << '\n';
    std::cout << "* : Multiply two numbers" << '\n';
    std::cout << "/ : Divide two numbers" << '\n';
    std::map<std::string, std::function<float(float, float)>> functions {
        { "+", add },
        { "-", subtract },
        { "*", multiply },
        { "/", divide }
    };

    std::string option;
    std::cin >> option;
    
    std::map<std::string, std::function<float(float, float)>>::iterator it;
    for (it = functions.begin(); it != functions.end(); it++) {
        if (it->first.compare(option) == 0) {
            float n1, n2;
            std::cout << "Type a number: ";
            std::cin >> n1;
            clear(false);
            std::cout << "Type another number: ";
            std::cin >> n2;
            std::cout << n1 << " " << it->first << " " << n2 << " = " << it->second(n1, n2) << '\n';
            break;
        }
    }
    if (it == functions.end()) {
        clear(true);
        menu("Incorrect input. Please select one of the four functions:");
    }
}

float add(float n1, float n2) {
    return n1 + n2;
}

float subtract(float n1, float n2) {
    return n1 - n2;
}

float multiply(float n1, float n2) {
    return n1 * n2;
}

float divide(float n1, float n2) {
    return n1 / n2;
}

void clear(bool clr) {
    std::cin.clear();
    std::cin.ignore(123, '\n');
    if (clr && std::system("clear"))
        std::system("cls");
}