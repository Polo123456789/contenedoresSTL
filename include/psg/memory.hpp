#ifndef PSG_MEMORY_HPP
#define PSG_MEMORY_HPP

#include <psg/memory/allocator.hpp>
#include <psg/memory/allocator_member_checks.hpp>
#include <psg/memory/allocator_traits.hpp>

namespace psg {

namespace imp {

constexpr bool addresof_by_casting = true;

}

/// Regresa la direccion de memoria de el argumento dado.
///
/// Sere completamente honesto, este lo copie de la posible implementacion que
/// se coloca en cppreference. Se me occuria una implementacion que solo fuera
/// `return &arg`, pero dice que tiene que funcionar aunque el operador & este
/// sobrecargado. Por ende, en lugar de romperme la cabeza tratando de buscar
/// como (Que no es el plan, el plan es implementar los contenedores), mejor
/// hago el buen copy paste y damos creditos.
///
/// [Link a el articulo de
/// cppreference](https://en.cppreference.com/w/cpp/memory/addressof)
template<typename T>
T *addressof(T &arg) noexcept {
    if constexpr (imp::addresof_by_casting) {
        return reinterpret_cast<T *>( // NOLINT
            &const_cast<char &>( // NOLINT
                reinterpret_cast<const volatile char &>(arg))); // NOLINT
    } else {
        return &arg;
    }
}

/// Construye un elemento en p, con el paquete de argumentos que se le hayan
/// dado.
/// 
/// Este recomendaria utilizarlo solo para elementos que asigno utilizando el
/// psg::allocator. Tendria que llamar al psg::destroy_at si utiliza este.
template<typename T, typename ...Args>
T* construct_at(T* p, Args&&... args) {
    new (p) T(forward<Args>(args)...);
    return p;
}

/// Destruye el elemento en la direccion p. 
/// 
/// Este seria el complemento del el construct_at
template<typename T>
void destroy_at(T* p) {
    p->~T();
}

/// Destruye todos los elementos en el rango first - last
template<typename ForwardIt>
void destroy(ForwardIt first, ForwardIt last) {
    auto destroy_element = [](ForwardIt it) {
        destroy_at(addressof(*it));
    };
    for_each(first, last, destroy_element);
}

}; // namespace psg

#endif
