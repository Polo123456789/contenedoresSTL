#include <iostream>
#include <psg/memory.hpp>

int main(void) {
    try {

        using ALI = psg::allocator<int>;
        ALI a;
        int *i = nullptr;

        constexpr int allocated_size = 1;
        constexpr int value_to_construt = 2;

        std::cout << "Asingando espacio ...\n";
        i = psg::allocator_traits<ALI>::allocate(a, allocated_size);
        std::cout << "Construyendo ...\n";
        psg::allocator_traits<ALI>::construct(a, i, value_to_construt);

        std::cout << *i << '\n';

        std::cout << "Destruyendo ...\n";
        psg::allocator_traits<ALI>::destroy(a, i);
        std::cout << "Liberando memoria ...\n";
        psg::allocator_traits<ALI>::deallocate(a, i, allocated_size);

    } catch (const psg::exception &e) {
        std::cout << e.what() << '\n';
    } catch (...) {
        std::cout << "Excepcion que no agarre, tendre que revisar algo mas\n";
    }
    return 0;
}
