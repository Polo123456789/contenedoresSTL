#ifndef PSG_VECTOR_CAPACITY_HPP
#define PSG_VECTOR_CAPACITY_HPP

#include <psg/vector/class.hpp>

namespace psg {

/// Indica si el contendedor esta vació. Este esta vació si no se le han
/// introducido elementos, aunque tenga memoria asignada.
template<class T, class Allocator>
[[nodiscard]] bool vector<T, Allocator>::empty() const noexcept {
    return last_valid_element == 0;
}

/// Regresa la cantidad de elementos que tiene el contendedor.
template<class T, class Allocator>
[[nodiscard]] size_t vector<T, Allocator>::size() const noexcept {
    return last_valid_element;
}

/// Regresa el tamaño maximo teorico que puede almacenar el contendedor. En este
/// caso es igual a Allocator::max_size.
template<class T, class Allocator>
[[nodiscard]] size_t vector<T, Allocator>::max_size() const noexcept {
    return allocator_traits<Allocator>::max_size(alloc);
}

/// Regresa el espacio que el vector tenga asinado en la memoria.
template<class T, class Allocator>
[[nodiscard]] size_t vector<T, Allocator>::capacity() const noexcept {
    return allocated_space;
}

// TODO(pablo): Implementar las siguientes funciones.
// NOTE: shrink_to_fit dice que la solicitud se puede cumplir opcionalemte.
// Toca investigar que tan practico es en realidad. O dar un criterio. Ej:
//
// * Si solo son 3 espacios los que no se usan, para que copiar todos los demas
// a otro espacio en la memoria?
// * Si si son 50, creo que si se puede devolver.
template<class T, class Allocator>
void vector<T, Allocator>::resize(size_type sz);

template<class T, class Allocator>
void vector<T, Allocator>::resize(size_type sz, const T &c);

template<class T, class Allocator>
void vector<T, Allocator>::reserve(size_type n);

template<class T, class Allocator>
void vector<T, Allocator>::shrink_to_fit();

} // namespace psg

#endif
