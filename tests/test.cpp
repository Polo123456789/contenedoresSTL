#include <iostream>
#include <psg/vector.hpp>

class S {
   public:
    S() {
        std::cout << "S construido por default\n";
    }
    S(const S &) {
        std::cout << "S construido por copia\n";
    }
    S(S &&) {
        std::cout << "S construido por movimiento\n";
    }
    ~S() {
        std::cout << "S destruido\n";
    }
};

int main(void) {
    psg::vector<S> a(5);
    psg::vector<S> b(a);
    psg::vector<S> c(psg::move(b));
    return 0;
}
