#include <iostream>
#include "algorithm.hpp"
#include "array.hpp"

constexpr int size = 20;

std::ostream& operator<<(std::ostream& o, const psg::array<int, size>& a) {
    for (auto n : a) {
        o << n << ' ';
    }
    return o;
}

void printIterator(const psg::array<int, size>& a) {
    std::cout << a << '\n';
}

void printIteratorR(psg::array<int, size>& a) {
    auto fist = a.rbegin();
    auto end = a.rend();
    for (auto i = fist; i!= end; i++) {
        auto n = *i;
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void printIteratorCR(psg::array<int, size>& a) {
    auto fist = a.crbegin();
    auto end = a.crend();
    for (auto i = fist; i!= end; i++) {
        auto n = *i;
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

int main (void) {
    psg::array<int, size> a{};
    a.fill(0);

    auto items = a.begin();

    for (int i=0; i<size; i++) {
        *(items++) = i;
    }

    printIterator(a);
    printIteratorCR(a);
    printIteratorR(a);
    
    return 0;
}

