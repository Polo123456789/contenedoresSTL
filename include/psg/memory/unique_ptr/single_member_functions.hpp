#ifndef PSG_MEMORY_UNIQUE_PTR_SINGLE_MEMBER_FUNCTION_HPP
#define PSG_MEMORY_UNIQUE_PTR_SINGLE_MEMBER_FUNCTION_HPP

#include <psg/memory/unique_ptr/single_class.hpp>

namespace psg {

template<class T, class Deleter>
unique_ptr<T, Deleter>::unique_ptr(pointer p) noexcept : object(p) {}

template<class T, class Deleter>
unique_ptr<T, Deleter>::unique_ptr(pointer p, Deleter d) noexcept
    : object(p), deleter(d) {}

template<class T, class Deleter>
template<class U, class E>
unique_ptr<T, Deleter>::unique_ptr(unique_ptr<U, E> &&u) noexcept {
    object = u.release();
    deleter = u.get_deleter();
}

template<class T, class Deleter>
unique_ptr<T, Deleter>::unique_ptr(unique_ptr &&u) noexcept {
    this->swap(u);
}

template<class T, class Deleter>
unique_ptr<T, Deleter>::~unique_ptr() noexcept {
    deleter(object);
}

template<class T, class Deleter>
auto unique_ptr<T, Deleter>::operator=(unique_ptr &&u) noexcept
    -> unique_ptr & {

    this->swap(u);
    return *this;
}

template<class T, class Deleter>
template<class U, class E>
auto unique_ptr<T, Deleter>::operator=(unique_ptr<U, E> &&u) noexcept
    -> unique_ptr & {

    reset(nullptr);
    object = u.release();
    deleter = u.get_deleter();
    return *this;
}

template<class T, class Deleter>
auto unique_ptr<T, Deleter>::operator=(std::nullptr_t) noexcept
    -> unique_ptr & {
    reset(nullptr);
    return *this;
}

}; // namespace psg

#endif
