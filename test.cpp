#include "array.hpp"


int main (void) {
    const int size = 10;
    psg::array<int, size> hola{};
    psg::array<int, size> adios{};

    adios.fill(1);

    hola[1] = 1;
    hola.back() = 2;
    hola.front() = 3;
    hola.at(4) = 4;

    psg::swap(hola, adios);
    return 0;
}

