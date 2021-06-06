#ifndef PGSL_VIEWS_HPP
#define PGSL_VIEWS_HPP

#include <psg/type_traits.hpp>
#include <psg/exception.hpp>

namespace pgsl {

/**
 * Tag utilizado para indicar que el puntero es dueño de la memoria a la que
 * apunta.
 */
template<typename T, psg::enable_if_t<psg::is_pointer_v<T>, bool> dummie = true>
using owner = T;

/**
 * Funcion utilitaria para acceder seguramente a los elementos de un array
 * estilo C
 *
 * @throws psg::exception En caso de que el elemento este fuera del rango del
 * array.
 */
template<typename T, size_t size>
constexpr T &at(T (&array)[size], size_t position) { // NOLINT
    if (position < size) {
        return array[position];
    }
    throw psg::exception("Excepcion en psgl::at. Elemento fuera de rango");
}

} // namespace pgsl

#endif
