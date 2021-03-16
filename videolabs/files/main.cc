#include <iostream>
#include <fstream>

// Makoto Miyamoto
// COSC 1436
// File I/O

/*
 * Objective:
 * Include the header file needed to perform file I/O
 * Define a file stream object (ofstream ifstream)
 * Open file
 * Use file
 * Close file
*/

int main(void) {
    std::ofstream fout;
    fout.open("./names.txt");

    fout << "Sarah Evans" << '\n';
    fout << "Stephen Erikson" << '\n';
    fout.close();

    std::ifstream fin;
    fin.open("names.txt");

    std::string line;
    std::string content;
    while (getline(fin, line)) {
        content.append(line).append("\n");
    }
    std::cout << content;

    return 0;
}