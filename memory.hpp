#ifndef PSG_MEMORY_HPP
#define PSG_MEMORY_HPP

#include <cstddef>
#include <cstdlib>

#include "exception.hpp"
#include "utility.hpp"

namespace psg {

template<typename T>
class allocator {
   public:
    using value_type = T;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    [[nodiscard]] T *allocate(size_type size);
    void deallocate(T *ptr, size_type size [[maybe_unused]]);

    // Estos estan aqui solo por que si. Estan deprecados desde C++17.
    // Asi que ni me voy a molestar en definirlos.
    [[deprecated]] T *address(T &x) const noexcept;
    [[deprecated]] const T *address(const T &x) const noexcept;
    [[deprecated]] size_type max_size(void) const noexcept;
    template<typename U, typename... Args>
    [[deprecated]] void construct(U *p, Args &&... args);
    template<typename U>
    [[deprecated]] void destroy(U *p);
};

/// Asinga la memoria para un puntero tipo T.
///
/// La cantidad de memoria esta dada por sizeof(T)*size. Si la asignacion de la
/// memoria falla, lanza un psg::exception explicando que no pudo asingar la
/// memoria.
template<typename T>
[[nodiscard]] T *allocator<T>::allocate(allocator<T>::size_type size) {
    T* ptr = nullptr;
    ptr = static_cast<T*>(malloc(sizeof(T) * size));
    if (ptr == nullptr) {
        throw exception("psg::allocator::exception Bad alloc: No se pudo "
                        "asignar la memoria");
    }
    return ptr;
}

/// Librera la memoria previamente asignada por el psg::allocator::allocate
//
/// El parametro de size es en relalidad uno que no utilizo, porque de fondo
/// solo uso malloc y free, pero lo mantengo para ser consistente con el
/// estandar. Ademas de que si vas a usar un allocator tuyo, puede que si lo
/// utilizes, asi que vamos a mantenerlo.
template<typename T>
void allocator<T>::deallocate(T *ptr, size_type size [[maybe_unused]]) {
    free(ptr);
}

/* ----------- No mas funciones del allocator pasado este punto ----------- */

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
    return reinterpret_cast<T *>(
        &const_cast<char &>(reinterpret_cast<const volatile char &>(arg)));
}

/// Construye un elemento en p, con el paquete de argumentos que se le hayan
/// dado.
/// 
/// Este recomendaria utilizarlo solo para elementos que asigno utilizando el
/// psg::allocator. Tendria que llamar al psg::destroy_at si utiliza este.
template<typename T, typename ...Args>
T* construct_at(T* p, Args&&... args) {
    new (p) T(args...);
    return p;
}

/// Destruye el elemento en la direccion p. 
/// 
/// Este seria el complemento del el construct_at
template<typename T>
void destroy_at(T* p) {
    p->~T();
}

}; // namespace psg

#endif
