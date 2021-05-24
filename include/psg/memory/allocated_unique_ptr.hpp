#ifndef PSG_MEMORY_ALLOCATED_UNIQUE_PTR_HPP
#define PSG_MEMORY_ALLOCATED_UNIQUE_PTR_HPP

#include <cstddef>

#include <pgsl/owners.hpp>

#include <psg/type_traits/reference_modifications.hpp>
#include <psg/memory/allocator_traits.hpp>

#include <psg/utility/functions.hpp>

namespace psg::imp {

///
/// Objeto encargado de manejar manejar memoria dada por un allocator.
///
/// **Nota:** Este no construye los elementos
///
/// Este tiene la responsabilidad unica de liberar la memoria asignada. El
/// contenedor que lo utiliza sera responsable de la construccion y destruccion
/// de los elementos.
///
template<typename Allocator>
class allocated_unique_ptr {
    using traits = psg::allocator_traits<Allocator>;

   public:
    using pointer = typename traits::pointer;
    using element_type = typename traits::value_type;
    using size_type = typename traits::size_type;
    using allocator_type = Allocator;

    /// No hace nada
    constexpr allocated_unique_ptr() noexcept = default;

    /// No hace nada
    // NOLINTNEXTLINE [[implicit]]
    constexpr allocated_unique_ptr(nullptr_t) noexcept {}

    allocated_unique_ptr(pointer p, Allocator &a, size_type size) noexcept
        : object(p), alloc(a), size(size) {}

    allocated_unique_ptr(const allocated_unique_ptr &) = delete;

    /// Mueve el allocated_unique_ptr que se le da
    allocated_unique_ptr(allocated_unique_ptr &&u) noexcept {
        alloc = u.alloc;
        object = u.release();
        size = u.size;
    }

    ~allocated_unique_ptr() noexcept {
        this->reset();
    }

    allocated_unique_ptr &operator=(allocated_unique_ptr &&u) noexcept {
        this->swap(u);
    }

    allocated_unique_ptr &operator=(nullptr_t) noexcept {
        this->reset();
    }

    allocated_unique_ptr &operator=(const allocated_unique_ptr &) = delete;

    /// Dereferenciar al puntero
    add_lvalue_reference_t<element_type> operator*() const {
        return *object;
    }

    pointer operator->() const noexcept {
        return object;
    }

    pointer get() const noexcept {
        return object;
    }

    size_type get_size() const noexcept {
        return size;
    }

    void set_size(size_type s) noexcept {
        size = s;
    }

    allocator_type &get_allocator() noexcept {
        return alloc;
    }

    const allocator_type &get_allocator() const noexcept {
        return alloc;
    }

    explicit operator bool() const noexcept {
        return object != nullptr;
    }

    /// Libera la responsabilidad que tiene sobre el objeto asignado
    pointer release() noexcept {
        pointer copy = object;
        object = nullptr;
        size = 0;
        return copy;
    }

    /// Intercambia los 2 allocated_unique_ptr
    void swap(allocated_unique_ptr &u) noexcept {
        psg::swap(object, u.object);
        psg::swap(size, u.size);
        psg::swap(alloc, u.alloc);
    }

    /// Libera el objeto que se tenga, y toma la responsabilidad por el nuevo
    /// objeto
    void reset(pointer p = pointer()) noexcept {
        if (object != nullptr) {
            traits::deallocate(alloc, object, size);
        }
        object = p;
    }

   private:
    pgsl::owner<pointer> object = nullptr;
    allocator_type &     alloc;
    size_type            size;
};

} // namespace psg::imp

#endif
