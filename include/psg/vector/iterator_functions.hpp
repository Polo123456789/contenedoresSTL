#ifndef PSG_VECTOR_ITERATOR_FUNCTIONS
#define PSG_VECTOR_ITERATOR_FUNCTIONS

#include <psg/vector/class.hpp>

namespace psg {

/// Iterador al principio del contenedor.
template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() noexcept {
    return typename vector<T, Allocator>::iterator(object, 0);
}

/// Iterador constante al principio del contenedor.
template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::begin() const noexcept {

    return typename vector<T, Allocator>::const_iterator(object, 0);
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() noexcept {
    return typename vector<T, Allocator>::iterator(object, last_valid_element);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::end() const noexcept {

    return typename vector<T, Allocator>::const_iterator(object,
        last_valid_element);
}

}; // namespace psg

#endif
