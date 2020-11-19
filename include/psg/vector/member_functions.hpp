#ifndef PSG_VECTOR_MEMBER_FUNCTIONS_HPP
#define PSG_VECTOR_MEMBER_FUNCTIONS_HPP

#include <psg/vector/class.hpp>

namespace psg {

/// Destruye los objetos, y libera la memoria asinada.
template<class T, class Allocator>
vector<T, Allocator>::~vector() {
    auto destroy_element = [&](reference t) {
        allocator_traits<Allocator>::destroy(alloc, addressof(t));
    };
    for_each(this->begin(), this->end(), destroy_element);
    allocator_traits<Allocator>::deallocate(alloc, object, allocated_space);
}

template<class T, class Allocator>
Allocator vector<T, Allocator>::get_allocator() const noexcept {
    return alloc;
}

}; // namespace psg

#endif
