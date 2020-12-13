#ifndef PSG_MEMORY_ALLOCATOR_HPP
#define PSG_MEMORY_ALLOCATOR_HPP

#include <cstddef>
#include <cstdlib>

#include <psg/type_traits.hpp>
#include <psg/utility.hpp>
#include <psg/exception.hpp>

#include <psg/memory/allocator_traits.hpp>

#include <pgsl/gsl.hpp>

namespace psg {

/// Este es el encargado de asignar y limpiar memoria
///
/// Este es el que sera utilizado en todas las clases si el usuario no provee
/// uno. Este es carente de estado, esto significa que todas las instancias que
/// use de psg::allocator son intercabliables entre si.
template<typename T>
class allocator {
   public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    /// Indica si tiene que ser copiado el allocator cuando el contenedor es
    /// move assigned
    using propagate_on_container_move_assingment = false_type;
    /// Igual que antes pero para la copia
    using propagate_on_container_copy_assingment = false_type;
    template<typename U>
    struct _rebind {
        using other = allocator<U>;
    };
    /// El rebind nos da una forma para obtener un allocator para un tipo
    /// diferente
    template<typename U>
    using rebind = _rebind<U>;
    using difference_type = ptrdiff_t;
    using is_allways_equal = true_type;

    constexpr allocator() = default;

    /// Asigna sizeof(T)*size bytes de memoria
    [[nodiscard]] pointer allocate(size_type size);
    /// Regresa la memoria
    void deallocate(T *ptr, size_type size [[maybe_unused]]) noexcept;

    // Puede que quieras declarar la siguiente funcion. Si
    // propagate_on_container_copy_assingment es verdadero y necesitas una forma
    // especial de copiar el allocator
    //
    // allocator<T> select_on_container_copy_construction(void) const
    //
    // Siempre, al construir por copia todos los contenedores usan el
    // allocator_traits::select_on_container_copy_construction al copiar el
    // contenedor.

    // Estos estan aqui solo por que si. Estan deprecados desde C++17.
    // Asi que ni me voy a molestar en definirlos.
    // [[deprecated]] T *address(T &x) const noexcept;
    // [[deprecated]] const T *address(const T &x) const noexcept;
    // [[deprecated]] [[nodiscard]] size_type max_size(void) const noexcept;
    // template<typename U, typename... Args>
    // [[deprecated]] void construct(U *p, Args &&... args);
    // template<typename U>
    // [[deprecated]] void destroy(U *p);
   private:
    static constexpr size_type max_alloc_size =
        size_type(-1) / sizeof(value_type);
};

/// Asinga la memoria para un puntero tipo T.
///
/// La cantidad de memoria esta dada por sizeof(T)*size. Si la asignacion de la
/// memoria falla, lanza un psg::exception explicando que no pudo asingar la
/// memoria.
template<typename T>
[[nodiscard]] T *allocator<T>::allocate(size_type size) {
    if (size > max_alloc_size) {
        throw exception(
            "psg::allocator::exception Bad alloc: No se pudo asignar la "
            "memoria, ha solicitado mas de la que puede manejar.");
    }

    pgsl::owner<T*> ptr = nullptr;
    ptr = static_cast<T *>(malloc(sizeof(T) * size)); // NOLINT
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
void allocator<T>::deallocate(pointer   ptr,
                              size_type size [[maybe_unused]]) noexcept {
    free(ptr);
}

}; // namespace psg

#endif
