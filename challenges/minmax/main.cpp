#include <iostream>
#include <fstream>
#include <cstring> // i know i should use basic_string<char> instead, but BLEH
#include <string>
#include <random>
#include <chrono>

struct options {
    char const* filepath;
    bool generate_file;
    bool delete_file;
    bool print_debug;
};
options program_options;

// checks if args array contains a string literal
bool argsContains(int argc, char const* argv[], char* c_str);

// evaluates arguments and returns whether or not to print help page.
bool evalArgs(int argc, char const* argv[]);

// generates random numbers
// meant as a closure for loadFileIStream
std::string generateRandomNumbers();

// loads the file input stream for the defined file path.
std::ifstream loadFileIStream(std::string filepath);

// prints input string if debug mode is active.
void log(std::string str);

int main(int argc, char const* argv[]) {
    if (evalArgs(argc, argv)) {
        std::string exec { argv[0] };
        if (exec.substr(0, 2).compare("./") == 0) {
            exec = exec.substr(2);
        }
        std::cout << exec << std::endl;
        std::cout << "usage: " << exec << " <filepath> [-g] [-d] [-p] [-help]" << '\n';
        std::cout << "  filepath      any file path - must be the first argument." << '\n';
        std::cout << "  -g            generate file despite defined path." << '\n';
        std::cout << "  -d            delete file after program ends." << '\n';
        std::cout << "  -p            print debug messages." << '\n';
        std::cout << "  -help         print this page." << '\n';
        return 1;
    }

    std::ifstream numbers_file { loadFileIStream(program_options.filepath) };

    int current;
    int min { INT32_MAX };
    int max { INT32_MIN };
    while (numbers_file >> current) {
        if (current > max)
            max = current;
        if (current < min)
            min = current;
    }
    numbers_file.close();

    std::cout << "Min: " << min << '\n';
    std::cout << "Max: " << max << '\n';

    if (program_options.delete_file) {
        int statusCode = std::remove(program_options.filepath);
        #if defined _WIN32 || defined _WIN64
            if (statusCode != 0) {
                std::cout << "Error: This file is open elsewhere." << std::endl;
            }
        #endif
        if (statusCode == 0)
            log(std::string(program_options.filepath).append(" deleted."));
    }
}

bool argsContains(int argc, char const* argv[], char const* arg) {
    for (int i = 0; i < argc; i++) {
        if (std::strcmp(argv[i], arg) == 0)
            return true;
    }
    return false;
}

bool evalArgs(int argc, char const* argv[]) {
    program_options.generate_file = argsContains(argc, argv, "-g");
    program_options.delete_file = argsContains(argc, argv, "-d");
    program_options.print_debug = argsContains(argc, argv, "-p");
    if (argsContains(argc, argv, "-help") || argc < 2)
        return true;
    program_options.filepath = argv[1];
    return false; // blatant redundancy for scalability
}

std::string generateRandomNumbers() {
    std::string result;

    std::srand(std::time(0));
    int rows { std::rand() % 10 + 1 };
    int cols;
    for (int i = 0; i < rows; i++) {
        cols = std::rand() % 5 + 1;
        for (int j = 0; j < cols; j++) {
            result.append(std::to_string(std::rand() % 500)).append(" ");
        }
        result.append("\n");
    }

    return result;
}

void generateFile(std::string filepath) {
    std::ofstream ofstream { filepath };
    ofstream << generateRandomNumbers();
    ofstream.close();
}
std::ifstream loadFileIStream(std::string filepath) {
    if (program_options.generate_file) {
        log("generating file...");
        generateFile(filepath);
        log("done!");
    }
    std::ifstream ifstream { filepath };
    if (ifstream.good()) {
        return ifstream;
    } else {
        log(std::string(filepath).append(" does not exist. generating file..."));
        generateFile(filepath);
        ifstream = std::ifstream { filepath };
        log("done!");
    }
    return ifstream;
}

void log(std::string str) {
    if (program_options.print_debug) std::cout << str << std::endl;
}
