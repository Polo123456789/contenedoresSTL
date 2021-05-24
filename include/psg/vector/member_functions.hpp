#ifndef PSG_VECTOR_MEMBER_FUNCTIONS_HPP
#define PSG_VECTOR_MEMBER_FUNCTIONS_HPP

#include <psg/vector/class.hpp>

namespace psg {

/// Destruye los objetos, y libera la memoria asinada.
template<class T, class Allocator>
vector<T, Allocator>::~vector() noexcept {
}

/// Regresa el allocator que este utilizando el vector.
template<class T, class Allocator>
Allocator vector<T, Allocator>::get_allocator() const noexcept {
}

/// Asignacion por copia.
template<class T, class Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(const vector &x) {
}

/// Asignacion por movimiento.
template<class T, class Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(vector &&x) noexcept {
}

/// Reemplaza los elemntos del vector con los elementos en el rango first, last.
template<class T, class Allocator>
template<class InputIt>
void vector<T, Allocator>::assign(InputIt first, InputIt last) {
}

/// Reemplaza los elemtos del vector por n copias de u.
template<class T, class Allocator>
void vector<T, Allocator>::assign(size_type n, const T &u) {
}

}; // namespace psg

#endif
