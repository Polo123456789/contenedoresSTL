#ifndef PSG_VECTOR_CONSTRUCTOR_HPP
#define PSG_VECTOR_CONSTRUCTOR_HPP

#include <psg/vector/class.hpp>

#include <psg/algorithm.hpp>

namespace psg {

/// Simplemente asigna el allocator.
template<class T, class Allocator>
vector<T, Allocator>::vector(const Allocator &alloc) noexcept : alloc(alloc) {}

// NOTE: NO USES MEMCPY. TE VAS A FREGAR LA VTABLE

/// Asigna n espacios en memoria y los llena con el valor default.
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type n, const Allocator &allocator) {

}

/// Asina n espacios en memoria y copia el valor
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type        n,
                             const T &        value,
                             const Allocator &allocator) {

}

/// Asingna distance(first, last) espacios de memoria, y copia los elemtos en el
/// rango [first, last)
template<class T, class Allocator>
template<class InputIt>
vector<T, Allocator>::vector(InputIt          first,
                             InputIt          last,
                             const Allocator &allocator) {

}

/// Copia el other a este vector.
template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &other)
    : vector(other,
             allocator_traits<Allocator>::select_on_container_copy_construction(
                 other.get_allocator())) {}

/// Copia el other al vector, y copia el allocator
template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &other, const Allocator &a) {

}

/// Mueve el other a este vector, garantizando que other estara vacio.
template<class T, class Allocator>
vector<T, Allocator>::vector(vector &&other) noexcept {

}

/// Mueve el other a este vector, y copia el allocator garantizando que other
/// estara vacio.
template<class T, class Allocator>
vector<T, Allocator>::vector(vector &&other, const Allocator &a) {

}

}; // namespace psg

#endif
