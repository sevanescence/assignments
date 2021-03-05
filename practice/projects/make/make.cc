#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <regex>
namespace fs = std::experimental::filesystem;

void filterFileNames(std::string* dir);

int main(int argc, const char *argv[]) {
    std::system("dir -R > tmp.txt");

    std::string line;
    std::string content;
    std::ifstream file ("tmp.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            content.append(line).append(" ");
        }
    }
    filterFileNames(&content);

    std::string command { "g++ -o " + std::string(argv[1]) + " " + content };
    std::cout << command << std::endl;

    std::system(command.c_str());
    std::system("rm ./tmp.txt");
    return 0;
}

void filterFileNames(std::string* dir) {
    std::regex e ("\\S+?\\.(cc|h)");
    std::smatch sm;
    std::string n{};
    while (std::regex_search(*dir, sm, e)) {
        for (auto x : sm) { n.append(x).append(" "); break; }
        *dir = sm.suffix().str();
    }
    *dir = n;
}
