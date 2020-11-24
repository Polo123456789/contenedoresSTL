#ifndef PSG_VECTOR_MEMBER_FUNCTIONS_HPP
#define PSG_VECTOR_MEMBER_FUNCTIONS_HPP

#include <psg/vector/class.hpp>

namespace psg {

/// Destruye los objetos, y libera la memoria asinada.
template<class T, class Allocator>
vector<T, Allocator>::~vector() {
    if (allocated_space == 0) {
        return;
    }
    auto destroy_element = [&](reference t) {
        allocator_traits<Allocator>::destroy(alloc, addressof(t));
    };
    for_each(this->begin(), this->end(), destroy_element);
    allocator_traits<Allocator>::deallocate(alloc, object, allocated_space);
}

/// Regresa el allocator que este utilizando el vector.
template<class T, class Allocator>
Allocator vector<T, Allocator>::get_allocator() const noexcept {
    return alloc;
}

/// Asignacion por copia.
template<class T, class Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(const vector &x) {
    if (this != &x) {
        vector<T, Allocator> copy(x);
        this->swap(copy);
    }
}

/// Asignacion por movimiento.
template<class T, class Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(vector &&x) noexcept {
    if (this != &x) {
        vector<T, Allocator> copy(move(x));
        this->swap(copy);
    }
}

/// Reemplaza los elemntos del vector con los elementos en el rango first, last.
template<class T, class Allocator>
template<class InputIt>
void vector<T, Allocator>::assign(InputIt first, InputIt last) {
    vector<T, Allocator> v(first, last);
    this->swap(v);
}

/// Reemplaza los elemtos del vector por n copias de u.
template<class T, class Allocator>
void vector<T, Allocator>::assign(size_type n, const T &u) {
    vector<T, Allocator> v(n, u);
    this->swap(v);
}

}; // namespace psg

#endif
