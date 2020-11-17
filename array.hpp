#ifndef PSG_ARRAY_HPP
#define PSG_ARRAY_HPP

#include <array/class.hpp>
#include <array/constructors.hpp>
#include <array/access_functions.hpp>
#include <array/iterator_functions.hpp>

namespace psg {

template<typename T, const size_t arr_size>
void swap(array<T, arr_size>& a, array<T, arr_size>& b) noexcept {
    a.swap(b);
}

}; // namespace psg

#endif
