#ifndef PGSL_VIEWS_HPP
#define PGSL_VIEWS_HPP

#include <psg/type_traits.hpp>
#include <psg/exception.hpp>

namespace pgsl {

template<typename T, psg::enable_if_t<psg::is_pointer_v<T>, bool> dummie = true>
using owner = T;


// https://stackoverflow.com/questions/10007986/c-pass-an-array-by-reference
template<typename T, size_t size>
auto at(T (&array)[size], size_t position) -> T & {//NOLINT
    if (position < size) {
        return array[size];
    }
    throw psg::exception("Excepcion en psgl::at. Elemento fuera de rango");
}

} // namespace pgsl

#endif
