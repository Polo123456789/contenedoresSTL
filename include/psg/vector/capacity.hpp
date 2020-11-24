#ifndef PSG_VECTOR_CAPACITY_HPP
#define PSG_VECTOR_CAPACITY_HPP

#include <psg/vector/class.hpp>

namespace psg {

template<class T, class Allocator>
[[nodiscard]] size_t vector<T, Allocator>::size() const noexcept {
    return last_valid_element;
}

}

#endif
