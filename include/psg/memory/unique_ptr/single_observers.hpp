#ifndef PSG_MEMORY_UNIQUE_PTR_SINGLE_OBSERVERS_HPP
#define PSG_MEMORY_UNIQUE_PTR_SINGLE_OBSERVERS_HPP

#include <psg/memory/unique_ptr/single_class.hpp>

namespace psg {
template<class T, class Deleter>
auto unique_ptr<T, Deleter>::operator*() const -> add_lvalue_reference_t<T> {
    return *object;
}

template<class T, class Deleter>
auto unique_ptr<T, Deleter>::operator->() const noexcept -> pointer {
    return object;
}

template<class T, class Deleter>
auto unique_ptr<T, Deleter>::get() const noexcept -> pointer {
    return object;
}

template<class T, class Deleter>
auto unique_ptr<T, Deleter>::get_deleter() noexcept -> deleter_type& {
    return deleter;
}

template<class T, class Deleter>
auto unique_ptr<T, Deleter>::get_deleter() const noexcept -> const deleter_type & {
    return deleter;
}

template<class T, class Deleter>
unique_ptr<T, Deleter>::operator bool() const noexcept {
    return (object != nullptr);
}

} // namespace psg

#endif
