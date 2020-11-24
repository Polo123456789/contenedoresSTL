#include <iostream>
#include <psg/vector.hpp>

int main(void) {
    psg::vector<int> a(static_cast<size_t>(5), static_cast<int>(1)); // NOLINT

    for (auto n : a) {
        std::cout << n << '\n';
    }

    try {
        std::cout << "A por los elemntos hasta pasarnos\n";
        for (size_t i = 0; i < a.size() + 1; i++) {
            std::cout << "[" << i << "]: " << a.at(i) << '\n';
        }
    } catch (const psg::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
