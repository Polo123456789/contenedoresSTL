#include <iostream>
#include <string>
#include "array.hpp"

int main(void) {
    constexpr size_t arr_size = 10;
    psg::array<int, arr_size> a{};

    psg::array<int, arr_size>::iterator it = a.begin();

    for(size_t i=0; i<arr_size; i++) {
        int& number = *it;
        number = static_cast<int>(i*2);
        ++it;
    }

    std::cout << "Construyendo b a partir de a" << '\n';
    psg::array<int, arr_size> b(a);

    for (auto n : b) {
        std::cout << n << ", ";
    }
    std::cout << '\n';

    std::cout << "Copiando a dentro de b" << '\n';

    a = b;
    for (auto n : b) {
        std::cout << n << ", ";
    }
    std::cout << '\n';

    std::cout << "Vamos a por todos los elementos de b, hasta pasarnos\n";
    try {
        for (size_t i = 0; i < arr_size + 1; i++) {
            std::cout << "[" << i << "]: " << b.at(i) << '\n';
        }
    } catch (const psg::exception& e) {
        std::cout << e.what() << '\n';
    }

    std::cout << "Llenamos b con el valor 1\n";
    b.fill(1);
    for (auto n : b) {
        std::cout << n << ", ";
    }
    std::cout << '\n';

    std::cout << "Cambiamos a y b\n";
    a.swap(b);
    std::cout << "a: ";
    for (auto n : a) {
        std::cout << n << ", ";
    }
    std::cout << '\n';
    std::cout << "b: ";
    for (auto n : b) {
        std::cout << n << ", ";
    }
    std::cout << '\n';


    return 0;
}
