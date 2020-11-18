#ifndef PSG_ARRAY_HPP
#define PSG_ARRAY_HPP

#include <psg/array/class.hpp>
#include <psg/array/constructors.hpp>
#include <psg/array/access_functions.hpp>
#include <psg/array/iterator_functions.hpp>
#include <psg/array/operations.hpp>

namespace psg {

template<typename T, const size_t arr_size>
void swap(array<T, arr_size>& a, array<T, arr_size>& b) noexcept {
    a.swap(b);
}

}; // namespace psg

#endif
