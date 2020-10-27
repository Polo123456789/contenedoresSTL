#ifndef PSG_MEMORY_HPP
#define PSG_MEMORY_HPP

#include <cstddef>
#include <cstdlib>

#include "exception.hpp"

namespace psg {

template<typename T>
class allocator {
   public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    [[nodiscard]] pointer allocate(size_t size);
    void deallocate(pointer ptr);
};

/* Asinga la memoria para un puntero tipo T. La cantidad de memoria esta dada
 * por sizeof(T)*size. Si la asignacion de la memoria falla, lanza un
 * psg::exception explicando que no pudo asingar la memoria.
 * */

template<typename T>
[[nodiscard]] typename allocator<T>::pointer allocator<T>::allocate(
    size_t size) {
    pointer ptr = nullptr;
    ptr = static_cast<allocator<T>::pointer>(malloc(sizeof(T) * size));
    if (ptr == nullptr) {
        throw exception("psg::allocator::exception Bad alloc: No se pudo "
                        "asignar la memoria");
    }
    return ptr;
}

template<typename T>
void allocator<T>::deallocate(allocator<T>::pointer ptr) {
    free(ptr);
}

}; // namespace psg

#endif
