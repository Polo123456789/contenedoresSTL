#ifndef PSG_MEMORY_UNIQUE_PTR_SINGLE_CLASS_HPP
#define PSG_MEMORY_UNIQUE_PTR_SINGLE_CLASS_HPP

#include <psg/type_traits/reference_modifications.hpp>
#include <psg/memory/default_delete.hpp>

namespace psg {

/// Clase para manejar recursos.
///
/// A diferencia de la de el estandar, este no se puede crear a base de un
/// puntero nada mas, ya que no usare new. Solo con make_unique
template<class T, class Deleter = default_delete<T>>
class unique_ptr {
   public:
    using pointer = T *;
    using element_type = T;
    using deleter_type = Deleter;

    constexpr unique_ptr() noexcept = default;
    constexpr unique_ptr(nullptr_t) noexcept {} // NOLINT [[implicit]]
    explicit unique_ptr(pointer p) noexcept;
    unique_ptr(pointer p, Deleter d) noexcept;
    template<class U, class E>
    unique_ptr(unique_ptr<U, E> &&u) noexcept; // NOLINT [[implicit]]
    unique_ptr(const unique_ptr &) = delete;
    unique_ptr(unique_ptr &&u) noexcept;
    ~unique_ptr() noexcept;

    unique_ptr &operator=(unique_ptr &&u) noexcept;
    template<class U, class E>
    unique_ptr &operator=(unique_ptr<U, E> &&u) noexcept;
    unique_ptr &operator=(nullptr_t) noexcept;
    unique_ptr &operator=(const unique_ptr &) = delete;

    add_lvalue_reference_t<T> operator*() const;
    pointer                   operator->() const noexcept;
    pointer                   get() const noexcept;
    deleter_type &            get_deleter() noexcept;
    const deleter_type &      get_deleter() const noexcept;
    explicit                  operator bool() const noexcept;

    pointer release() noexcept;
    void    swap(unique_ptr &u) noexcept;
    void    reset(pointer p = pointer()) noexcept;


   private:
    pgsl::owner<pointer> object = nullptr;
    deleter_type         deleter{};
};

} // namespace psg

#endif
