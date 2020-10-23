#include <iostream>
#include "array.hpp"

int main(void) {
    constexpr int arr_size = 10;
    psg::array<int, arr_size> a{};

    for(auto n : a) {
        std::cout << n << '\n';
    }
    return 0;
}
