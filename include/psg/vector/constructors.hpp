#ifndef PSG_VECTOR_CONSTRUCTOR_HPP
#define PSG_VECTOR_CONSTRUCTOR_HPP

#include <psg/vector/class.hpp>

#include <psg/algorithm.hpp>

namespace psg {

/// Simplemente asigna el allocator.
template<class T, class Allocator>
vector<T, Allocator>::vector(const Allocator &alloc) noexcept : alloc(alloc) {}

/// Asigna n espacios en memoria y los llena con el valor default.
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type n, const Allocator &allocator)
    : alloc(allocator) {

    // Asinamos la memoria
    allocated_space = n;
    object = allocator_traits<Allocator>::allocate(alloc, n);

    // Ultimo elemento valido para poder tener el iterador listo.
    last_valid_element = n;

    // Y construimos
    auto default_construct = [&](T &t) {
        allocator_traits<Allocator>::construct(alloc, addressof(t));
    };
    for_each(this->begin(), this->end(), default_construct);
}

/// Asina n espacios en memoria y copia el valor
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type n,
    const T &value,
    const Allocator &allocator)
    : alloc{allocator} {

    // Asinamos la memoria
    allocated_space = n;
    object = allocator_traits<Allocator>::allocate(alloc, n);

    // Ultimo elemento valido para poder tener el iterador listo.
    last_valid_element = n;

    // Y construimos
    auto copy_construct = [&](T &t) {
        allocator_traits<Allocator>::construct(alloc, addressof(t), value);
    };
    for_each(this->begin(), this->end(), copy_construct);
}

/// Asingna distance(first, last) espacios de memoria, y copia los elemtos en el
/// rango [first, last)
template<class T, class Allocator>
template<class InputIt>
vector<T, Allocator>::vector(InputIt first,
    InputIt last,
    const Allocator &allocator)
    : alloc(allocator) {

    // Tomamos el tamaño y asignamos la memoria
    size_type size = distance(first, last);
    object = allocator_traits<Allocator>::allocate(alloc, size);
    allocated_space = size;

    // Copiamos los elementos
    copy(first, last, this->begin());

    // Y dejamos el ultimo valido
    last_valid_element = size;
}

template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &other)
    : last_valid_element(other.last_valid_element),
      allocated_space(other.allocated_space) {

    // Copiamos el allocator
    alloc = allocator_traits<Allocator>::select_on_container_copy_construction(
        other.get_allocator());

    // Asignamos la memoria
    object = allocator_traits<Allocator>::allocate(alloc, allocated_space);

    // Copiamos los elementos
    copy(other.begin(), other.end(), this->begin());
}

template<class T, class Allocator>
vector<T, Allocator>::vector(vector &&other) noexcept {

}

}; // namespace psg

#endif
