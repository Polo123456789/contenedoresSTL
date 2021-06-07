#ifndef PSG_VECTOR_ELEMENT_ACCESS_HPP
#define PSG_VECTOR_ELEMENT_ACCESS_HPP

#include <psg/vector/class.hpp>

namespace psg {
template<class T, class Allocator>
T *vector<T, Allocator>::data() noexcept {
    return object.get();
}

template<class T, class Allocator>
const T *vector<T, Allocator>::data() const noexcept {
    return object.get();
}

}; // namespace psg

#endif
