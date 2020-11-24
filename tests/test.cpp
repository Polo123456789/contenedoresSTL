#include <iostream>
#include <vector>
#include <psg/vector.hpp>

using namespace psg;

int main(void) {
    vector<int> a(static_cast<size_t>(5), static_cast<int>(1)); // NOLINT

    for (auto n : a) {
        std::cout << n << '\n';
    }

    a.assign(static_cast<size_t>(3), static_cast<int>(2));

    for (auto n : a) {
        std::cout << n << '\n';
    }

    // try {
    //     std::cout << "A por los elemntos hasta pasarnos\n";
    //     for (size_t i = 0; i < a.size() + 1; i++) {
    //         std::cout << "[" << i << "]: " << a.at(i) << '\n';
    //     }
    // } catch (const exception &e) {
    //     std::cout << e.what() << '\n';
    // }
    return 0;
}
