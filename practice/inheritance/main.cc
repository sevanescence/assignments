#include "unit.h"

#include <iostream>
#include <string>

namespace bonk {
    class Foo {
        public:
            void whatComesAfterBar() {
                std::cout << "Flushing is bad" << '\n';
            }
    };

    class Bar : public Foo {

    };
};

int main(void) {
    unit::Impl impl{ "Test_impl" };

    impl.print();
    std::cout << impl.getNum() << std::endl;
}