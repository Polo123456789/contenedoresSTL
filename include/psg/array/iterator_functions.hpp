#ifndef PSG_ARRAY_ITERATOR_FUNCTIONS_HPP
#define PSG_ARRAY_ITERATOR_FUNCTIONS_HPP

#include <psg/array/class.hpp>

namespace psg {

namespace imp {

template<typename T, const size_t arr_size>
using ArrayIter = typename array<T, arr_size>::iterator;

template<typename T, const size_t arr_size>
using ArrayConstIter = typename array<T, arr_size>::const_iterator;

template<typename T, const size_t arr_size>
using ArrayRevIter = typename array<T, arr_size>::reverse_iterator;

template<typename T, const size_t arr_size>
using ArrayConstRevIter = typename array<T, arr_size>::const_reverse_iterator;

} // namespace imp

/// Regresa un iterador al principio del array
template<typename T, const size_t arr_size>
imp::ArrayIter<T, arr_size> array<T, arr_size>::begin(void) noexcept {
    return imp::ArrayIter<T, arr_size>(object, 0);
}

/// Regresa un iterador pasado el final del array. NO SE DEBE SER DEREFERENCIADO
template<typename T, const size_t arr_size>
imp::ArrayIter<T, arr_size> array<T, arr_size>::end(void) noexcept {
    return imp::ArrayIter<T, arr_size>(object, arr_size);
}

/// Regresa un iterador constante al principio del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::begin(
    void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, 0);
}

/// Regresa un iterador cosntante pasado el final del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::end(void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, arr_size);
}

/// Regresa un iterador al principio del array. Los valores dereferenciados no
/// pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::cbegin(
    void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, 0);
}

/// Regresa un iterador pasado el final del array. Los valores dereferenciados
/// no pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::cend(void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, arr_size);
}

/// Regresa un iterador al final del array. Este lo recorrera de el final hacia
/// el inicio.
template<typename T, const size_t arr_size>
imp::ArrayRevIter<T, arr_size> array<T, arr_size>::rbegin(void) noexcept {
    T *last_element = object + arr_size - 1;
    return imp::ArrayRevIter<T, arr_size>(last_element, 0);
}

/// Regresa un iterador pasado el principio del array. NO DEBE SER
/// DEREFERENCIADO
template<typename T, const size_t arr_size>
imp::ArrayRevIter<T, arr_size> array<T, arr_size>::rend(void) noexcept {
    T *last_element = object + arr_size - 1;
    return imp::ArrayRevIter<T, arr_size>(last_element, arr_size);
}

/// Regresa un constante iterador al final del array. Este lo recorrera de el
/// final hacia el inicio.
template<typename T, const size_t arr_size>
imp::ArrayConstRevIter<T, arr_size> array<T, arr_size>::crbegin(
    void) const noexcept {
    const T *last_element = object + arr_size - 1;
    return imp::ArrayConstRevIter<T, arr_size>(last_element, 0);
}

/// Regresa un constante iterador pasado el principio del array. NO DEBE SER
/// DEREFERENCIADO
template<typename T, const size_t arr_size>
imp::ArrayConstRevIter<T, arr_size> array<T, arr_size>::crend(
    void) const noexcept {
    const T *last_element = object + arr_size - 1;
    return imp::ArrayConstRevIter<T, arr_size>(last_element, arr_size);
}

};  // namespace psg

#endif
