#include <iostream>
//#include <array>
#include "array.hpp"

using namespace psg;
//using namespace std;

constexpr int array_size = 5;

void print(const array<int, array_size>& a) {
    for (auto first = a.crbegin(); first != a.crend(); first++) {
        std::cout << *first << ", ";
    }
}

int main (void) {
    array<int, array_size> a{};

    for (int i=0; i<array_size; i++) {
        a.at(i) = i;
    }

    print(a);
    
    return 0;
}
