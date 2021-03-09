#ifndef UNIT_H
#define UNIT_H

#include <string>

namespace unit {
    class Test;
    class Impl;

    class Test {
        private:
            int num;
        public:
            int getNum();
            Test(int _num);
            void print();
    };

    class Impl : public Test {
        private:
            std::string str;
        public:
            std::string getStr();
            Impl(std::string str);
    };
}

#endif