#include <iostream>
#include "utility.hpp"

struct S { //NOLINT
    bool construido = false; // NOLINT
    S() {
        construido = true;
        std::cout << "S construido\n";
    }
    S(S&& /*unused*/) noexcept {
        construido = true;
        std::cout << "Llamado al constructor por movimiento.\n";
    }
    ~S() {
        construido = false;
        std::cout << "S desconstruido\n";
    }
};

int main (void) {
    S s;
    S d(psg::move(s));
    return 0;
}

