#ifndef PSG_ARRAY_CONSTRUCTORS_HPP
#define PSG_ARRAY_CONSTRUCTORS_HPP

#include <psg/array/class.hpp>

namespace psg {

/// Constructor por copia.
template<typename T, const size_t arr_size>
array<T, arr_size>::array(const array<T, arr_size> &rhs) {
    copy_n(rhs.cbegin(), arr_size, this->begin());
}

/// Asignacion por copia
template<typename T, const size_t arr_size>
array<T, arr_size> &
    array<T, arr_size>::operator=(const array<T, arr_size> &rhs) {

    if (this == &rhs) {
        return *this;
    }
    copy_n(rhs.cbegin(), arr_size, this->begin());
    return *this;
}

}; // namespace psg

#endif
