#include "even_odd.hpp"

#include <iostream>
#include <vector>

using namespace even_odd;

int main(void) {
    IntegerFileIStreamSingleton* iStreamSingleton = IntegerFileIStreamSingleton::getInstance();
    (*iStreamSingleton).initializeIntegerFileIStream("numbers.txt");

    IntegerFileStreamConverter streamConverter = IntegerFileStreamConverterFactory().getIntegerFileStreamConverter();
    std::vector<int> integer_vector = streamConverter.convertIntegerFileStream(&(*iStreamSingleton).number_ifstream);

    IntegerVectorIterator integerVectorIterator { integer_vector };
    while (! integerVectorIterator.isDone()) {
        int next { integerVectorIterator.next() };
        std::cout << next << " is " << (isEven(next) ? "even" : "odd") << "!" << std::endl;
    }

}