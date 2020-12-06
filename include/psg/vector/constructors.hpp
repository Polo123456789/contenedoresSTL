#ifndef PSG_VECTOR_CONSTRUCTOR_HPP
#define PSG_VECTOR_CONSTRUCTOR_HPP

#include <psg/vector/class.hpp>

#include <psg/algorithm.hpp>

namespace psg {

/// Simplemente asigna el allocator.
template<class T, class Allocator>
vector<T, Allocator>::vector(const Allocator &alloc) noexcept : alloc(alloc) {}

// TODO(Pablo): Es necesario implementar el psg::unique_ptr para continuar, este
// se encargara eliminar los memory leaks que podamos tener.
//
// NOTE: Todo lo que se lleva hecho del vector tendra que ser migrado para usar
// el unique_ptr.
//
// TODO(Pablo): Eliminar memcpy, parece buena, pero te vas a fregar la vtable.
//https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-eq-base

/// Asigna n espacios en memoria y los llena con el valor default.
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type n, const Allocator &allocator)
    : allocated_space(n), last_valid_element(n), alloc(allocator) {

    object = allocator_traits<Allocator>::allocate(alloc, n);

    size_type constructed_elements = 0;
    auto      default_construct = [&](reference t) {
        allocator_traits<Allocator>::construct(alloc, addressof(t));
        constructed_elements++;
    };

    try {
        for_each(this->begin(), this->end(), default_construct);
    } catch (...) {
        last_valid_element = constructed_elements;
        this->~vector<T, Allocator>();
        throw psg::exception(
            "Exepcion en el psg::vector, uno de los constructores de los "
            "elementos ha lanzado una excepcion");
    }
}

/// Asina n espacios en memoria y copia el valor
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type        n,
                             const T &        value,
                             const Allocator &allocator)
    : allocated_space(n), last_valid_element(n), alloc{allocator} {

    object = allocator_traits<Allocator>::allocate(alloc, n);

    auto copy_construct = [&](T &t) {
        allocator_traits<Allocator>::construct(alloc, addressof(t), value);
    };
    for_each(this->begin(), this->end(), copy_construct);
}

/// Asingna distance(first, last) espacios de memoria, y copia los elemtos en el
/// rango [first, last)
template<class T, class Allocator>
template<class InputIt>
vector<T, Allocator>::vector(InputIt          first,
                             InputIt          last,
                             const Allocator &allocator)
    : alloc(allocator) {

    // Tomamos el tamaño y asignamos la memoria
    size_type size = distance(first, last);
    object = allocator_traits<Allocator>::allocate(alloc, size);
    allocated_space = size;

    // Copiamos los elementos
    iterator m_first = this->begin();
    auto construct = [&](typename InputIt::reference it, reference element) {
        allocator_traits<Allocator>::construct(alloc, addressof(*element), *it);
    };
    extra::for_each(first, last, m_first, construct);

    // Y dejamos el ultimo valido
    last_valid_element = size;
}

/// Copia el other a este vector.
template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &other)
    : vector(other,
             allocator_traits<Allocator>::select_on_container_copy_construction(
                 other.get_allocator())) {}

/// Copia el other al vector, y copia el allocator
template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &other, const Allocator &a)
    : allocated_space(other.allocated_space),
      last_valid_element(other.last_valid_element), alloc(a) {

    object = allocator_traits<Allocator>::allocate(alloc, allocated_space);

    iterator m_first = this->begin();
    auto     construct = [&](const_reference it, reference element) {
        allocator_traits<Allocator>::construct(alloc, addressof(element), it);
    };
    extra::for_each(other.begin(), other.end(), m_first, construct);
}

/// Mueve el other a este vector, garantizando que other estara vacio.
template<class T, class Allocator>
vector<T, Allocator>::vector(vector &&other) noexcept
    : object(exchange(other.object, nullptr)),
      allocated_space(exchange(other.allocated_space, 0)),
      last_valid_element(exchange(other.last_valid_element, 0)),
      alloc(move(other.alloc)) {}

/// Mueve el other a este vector, y copia el allocator garantizando que other
/// estara vacio.
template<class T, class Allocator>
vector<T, Allocator>::vector(vector &&other, const Allocator &a)
    : object(exchange(other.object, nullptr)),
      allocated_space(exchange(other.allocated_space, 0)),
      last_valid_element(exchange(other.last_valid_element, 0)), alloc(a) {}

}; // namespace psg

#endif