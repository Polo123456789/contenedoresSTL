#ifndef PSG_ARRAY_OPERATIONS_HPP
#define PSG_ARRAY_OPERATIONS_HPP

#include <psg/array/class.hpp>

namespace psg {

/// Indica si el array esta vacio
///
/// Este sera unicamente verdadero cuando el array tiene un tamaño de 0. No me
/// preguntes porque existe, no lo se.
template<typename T, const size_t arr_size>
[[nodiscard]] constexpr bool array<T, arr_size>::empty(void) const noexcept {
    return arr_size == 0;
}

/// Regresa el tamaño del array
template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::size(void) const noexcept {
    return arr_size;
}

/// Regresa el tamaño del array
template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::max_size(void) const noexcept {
    return this->size();
}

/// Llena el array con el valor dado
template<typename T, const size_t arr_size>
void array<T, arr_size>::fill(const_reference value) {
    auto assing_value = [&](reference element) -> void {
        element = value;
    };
    for_each(this->begin(), this->end(), assing_value);
}

/// Intercambia dos arrays
///
/// Este tambien se usa para especializar el psg::swap
template<typename T, const size_t arr_size>
void array<T, arr_size>::swap(array<T, arr_size> &other) noexcept {
    array<T, arr_size> tmp = *this;
    *this = other;
    other = tmp;
}

/// Regresa un puntero a los datos que este mantiene
template<typename T, const size_t arr_size>
T *array<T, arr_size>::data() noexcept {
    return object;
}

/// Regresa un puntero constante a los datos que este sostiene
template<typename T, const size_t arr_size>
const T *array<T, arr_size>::data() const noexcept {
    return object;
}

} // namespace psg

#endif
