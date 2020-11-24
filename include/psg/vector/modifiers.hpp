#ifndef PSG_VECTOR_MODIFIERS_HPP
#define PSG_VECTOR_MODIFIERS_HPP

#include <psg/vector/class.hpp>

#include <psg/utility.hpp>

namespace psg {

template<class T, class Allocator>
void vector<T, Allocator>::swap(vector<T, Allocator> &v) noexcept {
    swap(object, v.object);
    swap(allocated_space, v.allocated_space);
    swap(last_valid_element, v.last_valid_element);
    swap(alloc, v.alloc);
}

} // namespace psg

#endif
