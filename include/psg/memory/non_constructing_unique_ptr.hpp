#ifndef PSG_MEMORY_NON_CONSTRUCTING_UNIQUE_PTR_HPP
#define PSG_MEMORY_NON_CONSTRUCTING_UNIQUE_PTR_HPP

#include <cstddef>
#include <psg/utility.hpp>
#include <psg/type_traits.hpp>
#include <pgsl/views.hpp>

namespace psg::imp {

template<typename T>
struct default_free {
    void operator()(pgsl::owner<T *> p) noexcept {
        free(p);
    }
    template<typename U>
    void operator()(pgsl::owner<U *> p) noexcept {
        operator()(static_cast<T *>(p));
    }
    template<typename U>
    default_free &operator=(const default_free<U> & /*unused*/) {
        return *this;
    }
};


/// Non constructing unique ptr. Es para usar con malloc y free, y que los
/// necesito para el vector
template<class T, class Deleter = default_free<T>>
class nc_unique_ptr {
   public:
    using pointer = T *;
    using element_type = T;
    using deleter_type = Deleter;

    constexpr nc_unique_ptr() noexcept = default;

    constexpr nc_unique_ptr(nullptr_t) noexcept {} // NOLINT [[implicit]]

    explicit nc_unique_ptr(pointer p) noexcept : object(p) {}

    nc_unique_ptr(nc_unique_ptr &&u) noexcept
        : object(psg::exchange(u.object, nullptr)) {}

    nc_unique_ptr(pointer p, Deleter d) noexcept : object(p), deleter(d) {}

    template<class U, class E>
    nc_unique_ptr(nc_unique_ptr<U, E> &&u) noexcept { // NOLINT [[implicit]]
        object = u.object;
        deleter = u.deleter;
    }

    nc_unique_ptr(const nc_unique_ptr &) = delete;

    ~nc_unique_ptr() noexcept {
        this->reset(nullptr);
    }

    nc_unique_ptr &operator=(nc_unique_ptr &&u) noexcept {
        this->swap(u);
    }

    template<class U, class E>
    nc_unique_ptr &operator=(nc_unique_ptr<U, E> &&u) noexcept {
        psg::swap(object, u.object);
        psg::swap(deleter, u.deleter);
    }

    nc_unique_ptr &operator=(nullptr_t) noexcept {
        this->reset(nullptr);
    }

    nc_unique_ptr &operator=(const nc_unique_ptr &) = delete;

    add_lvalue_reference_t<T> operator[](size_t position) const {
        return object[position];
    }

    pointer get() const noexcept {
        return object;
    }

    deleter_type &get_deleter() noexcept {
        return deleter;
    }

    const deleter_type &get_deleter() const noexcept {
        return deleter;
    }

    explicit operator bool() const noexcept {
        return object != nullptr;
    }

    pointer release() noexcept {
        pointer old = object;
        object = nullptr;
        return old;
    }

    void swap(nc_unique_ptr &u) noexcept {
        psg::swap(this->object, u.object);
        psg::swap(this->deleter, u.deleter);
    }

    void reset(pointer p = pointer()) noexcept {
        if (object != nullptr) {
            deleter(object);
        }
        object = p;
    }

   private:
    pgsl::owner<pointer> object = nullptr;
    deleter_type         deleter{};
};

}; // namespace psg::imp

#endif
