#include <iostream>
#include "memory.hpp"

int main(void) {
    try {

        using ALI = psg::allocator<int>;
        ALI a;
        int *i = nullptr;

        constexpr int allocated_size = 1;
        constexpr int value_to_construt = 2;

        i = psg::allocator_traits<ALI>::allocate(a, allocated_size);
        psg::allocator_traits<ALI>::construct(a, i, value_to_construt);

        //auto c = &psg::construct_at;

        std::cout << *i << '\n';
        std::cout << psg::allocator_traits<ALI>::max_size(a) << '\n';

        auto b =
            psg::allocator_traits<ALI>::select_on_container_copy_construction(
                a);

        psg::allocator_traits<ALI>::destroy(b, i);
        psg::allocator_traits<ALI>::deallocate(b, i, allocated_size);

    } catch (const psg::exception &e) {
        std::cout << e.what() << '\n';
    } catch (...) {
        std::cout << "Excepcion que no agarre, tendre que revisar algo mas\n";
    }
    return 0;
}
