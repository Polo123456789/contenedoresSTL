#ifndef PSG_MEMORY_UNIQUE_PTR_SINGLE_CLASS_HPP
#define PSG_MEMORY_UNIQUE_PTR_SINGLE_CLASS_HPP

#include <psg/memory/default_new_delete.hpp>

namespace psg {

template<class T, class Deleter = default_delete<T>>
class unique_ptr {
   public:
    using pointer = T *;
    using element_type = T;
    using deleter_type = Deleter;

    constexpr unique_ptr() noexcept;
    explicit unique_ptr(pointer p) noexcept;
    unique_ptr(pointer p, const deleter_type &d) noexcept;
    unique_ptr(pointer p, deleter_type &&d) noexcept;
    unique_ptr(unique_ptr &&u) noexcept;
    constexpr unique_ptr(nullptr_t) noexcept; // NOLINT [[implicit]]
    template<class U, class E>
    unique_ptr(unique_ptr<U, E> &&u) noexcept; // NOLINT [[implicit]]
    ~unique_ptr() noexcept;

    unique_ptr &operator=(unique_ptr &&u) noexcept;
    template<class U, class E>
    unique_ptr &operator=(unique_ptr<U, E> &&u) noexcept;
    unique_ptr &operator=(nullptr_t) noexcept;

    add_lvalue_reference_t<T> operator*() const;
    pointer                   operator->() const noexcept;
    pointer                   get() const noexcept;
    deleter_type &            get_deleter() noexcept;
    const deleter_type &      get_deleter() const noexcept;
    explicit                  operator bool() const noexcept;

    pointer release() noexcept;
    void    reset(pointer p = pointer()) noexcept;
    void    swap(unique_ptr &u) noexcept;

    unique_ptr(const unique_ptr &) = delete;
    unique_ptr &operator=(const unique_ptr &) = delete;

   private:
    pgsl::owner<T *> object = nullptr;
};

} // namespace psg

#endif
