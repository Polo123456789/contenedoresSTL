#ifndef PSG_VECTOR_MODIFIERS_HPP
#define PSG_VECTOR_MODIFIERS_HPP

#include <psg/vector/class.hpp>

#include <psg/utility.hpp>

namespace psg {

template<class T, class Allocator>
void vector<T, Allocator>::swap(vector<T, Allocator> &v) noexcept {

}


template<class T, class Allocator>
void vector<T, Allocator>::clear(void) noexcept {
    for_each(this->begin(), this->end(), [&](reference r) {
            traits::destroy(alloc, addressof(r));
    });
}

}; // namespace psg

#endif
