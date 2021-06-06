#ifndef PSG_MEMORY_POINTER_TRAITS
#define PSG_MEMORY_POINTER_TRAITS

#include <cstddef>
#include <psg/memory/functions.hpp>

namespace psg {

/**
 * La forma en la que la libreria estandar accede a las propiedades de los
 * punteros. Por default requiere:
 * 
 * * Ptr::element_type
 * * Ptr::difference_type
 * * Ptr::rebind<U>
 * * Ptr::pointer_to(element_type& e)
 *
 * Pero puede especializarla para que utilize sus punteros.
 */
template<typename Ptr>
struct pointer_traits {
    using pointer = Ptr;
    using element_type = typename Ptr::element_type;
    using difference_type = typename Ptr::difference_type;

    template<typename U>
    using rebind = typename Ptr::template rebind<U>;

    /**
     * @return La direccion de memoria de `e`
     */
    static pointer pointer_to(element_type& e);
};

template<typename Ptr>
auto pointer_traits<Ptr>::pointer_to(element_type &e) -> pointer {
    return Ptr::pointer_to(e);
}

/**
 * Especializacion de psg::pointer_traits para que funcione con punteros
 * normales
 */
template <typename T>
struct pointer_traits<T*> {
    using pointer = T*;
    using element_type = T;
    using difference_type = ptrdiff_t;

    template<typename U>
    using rebind = U*;

    static pointer pointer_to(element_type& e);
};

/**
 * @return `psg::addressof(e)`
 */
template <typename T>
T* pointer_traits<T*>::pointer_to(element_type& e) {
    return addressof(e);
}

}; // namespace psg

#endif
