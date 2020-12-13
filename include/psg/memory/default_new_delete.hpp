#ifndef PSG_MEMORY_DEFAULT_NEW_DELETE_HPP
#define PSG_MEMORY_DEFAULT_NEW_DELETE_HPP

#include <pgsl/gsl.hpp>
#include <psg/memory/allocator.hpp>

namespace psg {

/// El delete default que se usa para el unique_ptr.
///
/// Borra unicamente objetos creados con el default_new.
template<typename T>
struct default_delete {

    void operator()(T *p) noexcept {
        psg::allocator<T> a{};
        destroy_at(p);
        // It is unused because psg::allocator uses free, so the size of the
        // object is managed by the os
        typename psg::allocator<T>::size_type unused_val = 0;
        a.deallocate(p, unused_val);
    }
};

/// El reemplazo de el new estandar.
template<typename T>
struct default_new {
    template<typename... Args>
    T *operator()(size_t size, Args &&...args) {
        psg::allocator<T> a{};
        pgsl::owner<T *>  p = a.allocate(size);
        construct_at(p, psg::forward<Args>(args)...);
        return p;
    }
};

} // namespace psg
#endif
