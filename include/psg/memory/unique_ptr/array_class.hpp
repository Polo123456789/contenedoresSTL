#ifndef PSG_MEMORY_UNIQUE_PTR_ARRAY_CLASS_HPP
#define PSG_MEMORY_UNIQUE_PTR_ARRAY_CLASS_HPP

#include <psg/memory/unique_ptr/single_class.hpp>

namespace psg {

template<class T, class Deleter>
class unique_ptr<T[], Deleter> // NOLINT Tiene que ser de estilo C
{
   public:
    using pointer = T *;
    using element_type = T;
    using deleter_type = Deleter;

    constexpr unique_ptr() noexcept;
    unique_ptr(const unique_ptr &) = delete;
    template<class U>
    explicit unique_ptr(U p) noexcept;
    template<class U>
    unique_ptr(U p, const deleter_type &d) noexcept;
    template<class U>
    unique_ptr(U p, deleter_type &&d) noexcept;
    unique_ptr(unique_ptr &&u) noexcept;
    template<class U, class E>
    unique_ptr(unique_ptr<U, E> &&u) noexcept; // NOLINT [[implicit]]
    constexpr unique_ptr(nullptr_t) noexcept;  // NOLINT [[implicit]]
    ~unique_ptr();

    // assignment
    unique_ptr &operator=(const unique_ptr &) = delete;
    unique_ptr &operator=(unique_ptr &&u) noexcept;
    template<class U, class E>
    unique_ptr &operator=(unique_ptr<U, E> &&u) noexcept;
    unique_ptr &operator=(nullptr_t) noexcept;

    // observers
    T &                 operator[](size_t i) const;
    pointer             get() const noexcept;
    deleter_type &      get_deleter() noexcept;
    const deleter_type &get_deleter() const noexcept;
    explicit            operator bool() const noexcept;

    // modifiers
    pointer release() noexcept;
    template<class U>
    void reset(U p) noexcept;
    void reset(nullptr_t = nullptr) noexcept;
    void swap(unique_ptr &u) noexcept;

   private:
    pgsl::owner<T *> object = nullptr;
    deleter_type     deleter{};
};

} // namespace psg

#endif
