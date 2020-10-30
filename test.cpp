#include <iostream>
#include "memory.hpp"

struct S { //NOLINT
    bool construido = false;
    S() {
        construido = true;
        std::cout << "S construido\n";
    }
    S(int, int, int) {
        construido = true;
        std::cout << "S construido\n";
    }
    S(S&&){
        std::cout << "Llamado al constructor por movimiento.\n";
    }
    void work() {
        std::cout << "Working ...\n";
    }
    void destruido() const {
        if (construido) {
            std::cout << "Esta construido de momento\n";
            return;
        }
        std::cout << "Esta destruido\n";
    }
    ~S() {
        construido = false;
        std::cout << "S desconstruido\n";
    }
};

int main (void) {
    psg::allocator<S> allocator;
    S* s = allocator.allocate(1);
    psg::construct_at(s, 1,1,1);
    s->destruido();
    psg::destroy_at(s);
    allocator.deallocate(s, 1);
    return 0;
}

