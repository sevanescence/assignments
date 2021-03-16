#ifndef EVEN_ODD_H
#define EVEN_ODD_H

#include <fstream>
#include <vector>

namespace even_odd {
    class IntegerFileIStreamSingleton;
    class IntegerVectorIterator;
    class IntegerFileStreamConverterFactory;
    class IntegerFileStreamConverter;

    bool isEven(int num);

    class IntegerFileIStreamSingleton {
        private:
            static IntegerFileIStreamSingleton* instance_;
        public:
            std::ifstream number_ifstream;
        public:
            static IntegerFileIStreamSingleton* getInstance();
            void initializeIntegerFileIStream(std::string path);
    };

    class IntegerVectorIterator {
        private:
            std::vector<int> integer_vector_;
            int index_;
        public:
            IntegerVectorIterator(std::vector<int> integer_vector);
            bool isDone();
            int next();
    };

    class IntegerFileStreamConverterFactory {
        public:
            IntegerFileStreamConverter getIntegerFileStreamConverter();
    };

    class IntegerFileStreamConverter {
        public:
            static std::vector<int> convertIntegerFileStream(std::ifstream* integer_ifstream);
    };
}

#endif