#ifndef PSG_MEMORY_ALLOCATOR_HPP
#define PSG_MEMORY_ALLOCATOR_HPP

#include <cstddef>
#include <cstdlib>

#include <psg/type_traits.hpp>
#include <psg/utility.hpp>
#include <psg/exception.hpp>

#include <psg/memory/allocator_traits.hpp>

#include <pgsl/assert.hpp>
#include <pgsl/views.hpp>

namespace psg {

/**
 * Clase encargada de asignar y liberar memoria
 * 
 * Este es el que sera utilizado en todas las clases si el usuario no provee
 * uno. Este es carente de estado, esto significa que todas las instancias que
 * use de psg::allocator son intercabliables entre si.
 */
template<typename T>
class allocator {
   public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using is_allways_equal = true_type;

    /**
     * Indica si tiene que ser copiado el allocator cuando el contenedor es
     * move assigned
     */
    using propagate_on_container_move_assingment = false_type;

    /**
     * Igual que antes pero para la copia
     */
    using propagate_on_container_copy_assingment = false_type;

    template<typename U>
    struct _rebind {
        using other = allocator<U>;
    };

    /**
     * Da un psg::allocator para un tipo diferente
     */
    template<typename U>
    using rebind = _rebind<U>;

    constexpr allocator() = default;

    /**
     * @param size Cantidad de elementos a asignar
     * @return Un puntero a `sizeof(T) * size` bytes de memoria
     * @throws psg::exception Si no se puede asignar la memoria, o si se piden
     * mas elementos de los que se pueden asignar.
     */
    [[nodiscard]] pointer allocate(size_type size);

    /**
     * @param ptr Direccion de memoria a ser liberada
     * @param size Cantidad de elemetos a liberar
     *
     * **Nota:** El psg::allocator no usa el parametro `size` ya  que
     * internamente usa malloc, pero conserva el parametro para ser consistente
     * con el estandar.
     */
    void deallocate(T *ptr, size_type size [[maybe_unused]]) noexcept;

    /*
     * Estos estan aqui solo por que si. Estan deprecados desde C++17.  Asi que
     * ni me voy a molestar en definirlos. Seria solo hacer una copia de la
     * solucion default que da el `psg::allocator_traits`
     *
     * [[deprecated]] T *address(T &x) const noexcept;
     *
     * [[deprecated]] const T *address(const T &x) const noexcept;
     *
     * [[deprecated]] [[nodiscard]] size_type max_size(void) const noexcept;
     *
     * template<typename U, typename... Args>
     * [[deprecated]] void construct(U *p, Args &&... args);
     *
     * template<typename U>
     * [[deprecated]] void destroy(U *p);
     */

   private:
    static constexpr size_type max_alloc_size =
        size_type(-1) / sizeof(value_type);
};

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

template<typename T>
void allocator<T>::deallocate(pointer   ptr,
                              size_type size [[maybe_unused]]) noexcept {
    Expects(ptr != nullptr);
    free(ptr);
}

}; // namespace psg

#endif
