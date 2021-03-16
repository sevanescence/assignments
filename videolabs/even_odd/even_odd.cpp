#include "even_odd.hpp"

#include <iostream>
#include <fstream>
#include <string>

namespace even_odd {

    bool isEven(int num) {
        return num % 2 == 0;
    }

    class IntegerFileIStreamSingleton;

    IntegerFileIStreamSingleton* IntegerFileIStreamSingleton::instance_;

    IntegerFileIStreamSingleton* IntegerFileIStreamSingleton::getInstance() {
        if (! instance_) {
            instance_ = new IntegerFileIStreamSingleton;
        }
        return instance_;
    }

    void IntegerFileIStreamSingleton::initializeIntegerFileIStream(std::string path) {
        number_ifstream = std::ifstream(path);
    }


    class IntegerFileStreamConverterFactory;

    IntegerFileStreamConverter IntegerFileStreamConverterFactory::getIntegerFileStreamConverter() {
        return IntegerFileStreamConverter();
    }


    class IntegerFileStreamConverter;

    std::vector<int> IntegerFileStreamConverter::convertIntegerFileStream(std::ifstream* integer_ifstream) {
        std::vector<int> integer_vector;
        
        std::string line;
        while (std::getline(*integer_ifstream, line)) {
            integer_vector.push_back(std::stoi(line));
        }

        return integer_vector;
    }


    class IntegerVectorIterator;

    IntegerVectorIterator::IntegerVectorIterator(std::vector<int> integer_vector) {
        integer_vector_ = integer_vector;
        index_ = 0;
    }

    bool IntegerVectorIterator::isDone() {
        return index_ == (integer_vector_.size() - 1);
    }

    int IntegerVectorIterator::next() {
        return integer_vector_.at(index_++);
    }

}