#ifndef PSG_MEMORY_UNIQUE_PTR_SINGLE_MODIFIERS_HPP
#define PSG_MEMORY_UNIQUE_PTR_SINGLE_MODIFIERS_HPP

#include <psg/memory/unique_ptr/single_class.hpp>

#include <psg/utility.hpp>

namespace psg {

template<class T, class Deleter>
auto unique_ptr<T, Deleter>::release() noexcept -> pointer {
    pointer old_obj = object;
    object = nullptr;
    return old_obj;
}

template<class T, class Deleter>
void unique_ptr<T, Deleter>::swap(unique_ptr &u) noexcept {
    psg::swap(u.object, object);
    psg::swap(u.deleter, deleter);
}

template<class T, class Deleter>
void unique_ptr<T, Deleter>::reset(pointer p) noexcept {
    if (object != nullptr) {
        deleter(object);
    }
    object = p;
}

} // namespace psg

#endif
