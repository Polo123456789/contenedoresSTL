#ifndef PSG_VECTOR_ELEMENT_ACCESS_HPP
#define PSG_VECTOR_ELEMENT_ACCESS_HPP

#include <psg/vector/class.hpp>

namespace psg {

/// Acceso directo mediante un puntero al array que utiliza el vector. 
template<class T, class Allocator>
T *vector<T, Allocator>::data() noexcept {
    return object.get();
}

/// Acceso directo mediante un puntero constante al array que utiliza el vector
template<class T, class Allocator>
const T *vector<T, Allocator>::data() const noexcept {
    return object.get();
}

}; // namespace psg

#endif
