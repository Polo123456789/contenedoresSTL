#ifndef PSG_ARRAY_ITERATOR_FUNCTIONS_HPP
#define PSG_ARRAY_ITERATOR_FUNCTIONS_HPP

#include <psg/array/class.hpp>

namespace psg {

/// Regresa un iterador al principio del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::iterator array<T, arr_size>::begin(void) noexcept {
    return typename array<T, arr_size>::iterator(object, 0);
}

/// Regresa un iterador pasado el final del array. NO SE DEBE SER DEREFERENCIADO
template<typename T, const size_t arr_size>
typename array<T, arr_size>::iterator array<T, arr_size>::end(void) noexcept {
    return typename array<T, arr_size>::iterator(object, arr_size);
}

/// Regresa un iterador constante al principio del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_iterator array<T, arr_size>::begin(
    void) const noexcept {

    return typename array<T, arr_size>::const_iterator(object, 0);
}

/// Regresa un iterador cosntante pasado el final del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_iterator array<T, arr_size>::end(
    void) const noexcept {

    return typename array<T, arr_size>::const_iterator(object, arr_size);
}

/// Regresa un iterador al principio del array. Los valores dereferenciados no
/// pueden ser modificados.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_iterator array<T, arr_size>::cbegin(
    void) const noexcept {

    return typename array<T, arr_size>::const_iterator(object, 0);
}

/// Regresa un iterador pasado el final del array. Los valores dereferenciados
/// no pueden ser modificados.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_iterator array<T, arr_size>::cend(
    void) const noexcept {

    return typename array<T, arr_size>::const_iterator(object, arr_size);
}

/// Regresa un iterador al final del array. Este lo recorrera de el final hacia
/// el inicio.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reverse_iterator array<T, arr_size>::rbegin(
    void) noexcept {

    T *last_element = object + arr_size - 1;
    return typename array<T, arr_size>::reverse_iterator(last_element, 0);
}

/// Regresa un iterador pasado el principio del array. NO DEBE SER
/// DEREFERENCIADO
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reverse_iterator array<T, arr_size>::rend(
    void) noexcept {

    T *last_element = object + arr_size - 1;
    return
        typename array<T, arr_size>::reverse_iterator(last_element, arr_size);
}

/// Regresa un constante iterador al final del array. Este lo recorrera de el
/// final hacia el inicio.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reverse_iterator array<T, arr_size>::crbegin(
    void) const noexcept {

    const T *last_element = object + arr_size - 1;
    return typename array<T, arr_size>::const_reverse_iterator(last_element, 0);
}

/// Regresa un constante iterador pasado el principio del array. NO DEBE SER
/// DEREFERENCIADO
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reverse_iterator array<T, arr_size>::crend(
    void) const noexcept {

    const T *last_element = object + arr_size - 1;
    return typename array<T, arr_size>::const_reverse_iterator(last_element,
        arr_size);
}

}; // namespace psg

#endif
