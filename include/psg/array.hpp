#ifndef PSG_ARRAY_HPP
#define PSG_ARRAY_HPP

#include <psg/array/class.hpp>
#include <psg/array/constructors.hpp>
#include <psg/array/operations.hpp>

namespace psg {

/**
 * Overload de swap especial para el array.
 *
 * **Nota:** Es equivalente a `a.swap(b)`.
 */
template<typename T, const size_t arr_size>
void swap(array<T, arr_size> &a, array<T, arr_size> &b) noexcept {
    a.swap(b);
}

/**
 * Compara que todos los elementos de `a` sean iguales al elemento en la
 * posicion equivalente de `b`.
 *
 * **Nota:** El tipo de los elementos del array tienen que cumplir con ser
 * EqualityComparable
 */
template<typename T, const size_t arr_size>
bool operator==(const array<T, arr_size> &a, const array<T, arr_size> &b) {
    auto first_a = a.begin();
    auto last_a = a.end();
    auto first_b = b.begin();

    for (; first_a != last_a; ++first_a, ++first_b) {
        if (*first_a != *first_b) {
            return false;
        }
    }
    return true;
}

// TODO(pabsa): Investigar lexicografical compare y hacer los overloads que
// hacen falta.

}; // namespace psg

#endif
