#ifdef __cplusplus__
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include <iomanip>

// ╔══════════════════════════════════════════╗
// ║[x] - Return                              ║
// ╠══════════════════════════════════════════╣
// ║                                          ║
// ╚══════════════════════════════════════════╝

#ifndef TERMINAL_H
#define TERMINAL_H

namespace terminal {
    static int length{};
    static std::stringstream sstream;
    void clear() {
        if (std::system("CLS"))
            std::system("clear");
    }
    void setLength(int len) {
        length = len;
    }
    void begin() {
        sstream = std::stringstream{};
    }
    void addln(std::string line) {
        sstream << line << '\n';
    }
    void print() {
        int len{};
        std::string line;
        while (getline(sstream, line)) {
            len = length - line.length();
            std::cout << "║" << line << std::setw(len) << "" << "║" << std::endl;
        }
    }
    void dump() {
        print();
        sstream = std::stringstream{};
    }
    int getLongestLine(std::stringstream* sstream) {
        std::stringstream res{};
        std::string line;
        int longest{ 0 };
        while (getline(*sstream, line)) {
            res << line << '\n';
            if (line.length() > longest) longest = line.length();
        }
        *sstream = std::stringstream{};
        while (getline(res, line)) {
            *sstream << line << '\n';
        }
        return longest;
    }
    void printBorderTop() {
        std::string stretch{};
        for (int i = 0; i < length; i++) stretch.append("═");
        std::cout << "╔" << stretch << "╗" << '\n';
    }
    std::string generateToolbarBottom();
    void printEmptyToolbar() {
        std::cout << "╠" << generateToolbarBottom() << "╣" << '\n';
    }
    void printToolbar(std::string info) {
        int finalLength { std::abs(length - (int) info.length()) };
        std::string spacing ( finalLength, ' ' );
        std::cout << "║" << info << spacing << "║" << '\n';
        std::cout << "╠" << generateToolbarBottom() << "╣" << '\n';
    }
    std::string generateToolbarBottom() {
        std::string s {};
        for (int i = 0; i < length; i++) s.append("═");
        return s;
    }
    void printBottom() {
        std::string s { generateToolbarBottom() };
        std::cout << "╚" << s << "╝" << '\n';
    }
}

#endif