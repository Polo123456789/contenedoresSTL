#ifndef PSG_MEMORY_POINTER_TRAITS
#define PSG_MEMORY_POINTER_TRAITS

#include <cstddef>
#include <psg/memory/functions.hpp>

namespace psg {

/// Version no especializada, que requiere que se defina:
///
/// * Ptr::element_type
/// * Ptr::difference_type
/// * Ptr::rebind<U>
/// * Ptr::pointer_to(element_type& e)
template<typename Ptr>
struct pointer_traits {
    using pointer = Ptr;
    using element_type = typename Ptr::element_type;
    using difference_type = typename Ptr::difference_type;

    template<typename U>
    using rebind = typename Ptr::template rebind<U>;

    static pointer pointer_to(element_type& e);
};

template<typename Ptr>
typename pointer_traits<Ptr>::pointer
    pointer_traits<Ptr>::pointer_to(element_type &e) {

    return Ptr::pointer_to(e);
}

/// Version especializada para los punteros normales
template <typename T>
struct pointer_traits<T*> {
    using pointer = T*;
    using element_type = T;
    using difference_type = ptrdiff_t;

    template<typename U>
    using rebind = U*;

    static pointer pointer_to(element_type& e);
};

template <typename T>
T* pointer_traits<T*>::pointer_to(element_type& e) {
    return addressof(e);
}

}; // namespace psg

#endif
