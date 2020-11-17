#ifndef PSG_ARRAY_ACCESS_FUNTIONS_HPP
#define PSG_ARRAY_ACCESS_FUNTIONS_HPP

#include <psg/array/class.hpp>

namespace psg {

/// Regresa el elemento en la posicion solicitada con checkeo.
///
/// Este regresa una referencia a el elemento revisando que este dentro del
/// array, si el elemento esta fuera de rango, esta lanza un psg::exception.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::at(
    typename array<T, arr_size>::size_type position) {

    if (position < arr_size) {
        return object[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                    "elemento fuera de rango. ");
}

/// Regresa el elemento en la posicion solicitada con checkeo.
///
/// Este regresa una referencia constante a el elemento revisando que este
/// dentro del array, si el elemento esta fuera de rango, esta lanza un
/// psg::exception.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::at(
    typename array<T, arr_size>::size_type position) const {

    if (position < arr_size) {
        return object[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                    "elemento fuera de rango. ");
}

/// Regresa una referencia a el elemento en la posicion solicitada sin
/// checkeo.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::operator[](
    typename array<T, arr_size>::size_type position) {

    return object[position];
}

/// Regresa una referencia constante a el elemento en la posicion solicitada
/// sin checkeo.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::operator[](
    typename array<T, arr_size>::size_type position) const {

    return object[position];
}

/// Regresa una referencia al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::front(void) {
    return object[0];
}

/// Regresa una referencia constante al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::front(
    void) const {
    return object[0];
}

/// Regresa una referencia al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::back(void) {
    return object[arr_size - 1];
}

/// Regresa una referencia constante al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::back(
    void) const {

    return object[arr_size - 1];
}

}; // namespace psg

#endif
