#include <iostream>
#include "array.hpp"

constexpr int array_size = 5;

void print(const psg::array<int, array_size>& a) {
    for (auto first = a.crbegin(); first != a.crend(); first++) {
        std::cout << *first << ", ";
    }
}

int main (void) {
    psg::array<int, array_size> a{};

    for (int i=0; i<array_size; i++) {
        a.at(i) = i;
    }

    print(a);
    
    return 0;
}
