#ifndef PSG_ARRAY_OPERATIONS_HPP
#define PSG_ARRAY_OPERATIONS_HPP

#include <psg/array/class.hpp>

namespace psg {

template<typename T, const size_t arr_size>
[[nodiscard]] constexpr bool array<T, arr_size>::empty(void) const noexcept {
    return arr_size == 0;
}

template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::size(void) const noexcept {
    return arr_size;
}

template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::max_size(void) const noexcept {
    return this->size();
}

template<typename T, const size_t arr_size>
void array<T, arr_size>::fill(const_reference value) {
    auto assing_value = [&](reference element) -> void {
        element = value;
    };
    for_each(this->begin(), this->end(), assing_value);
}

template<typename T, const size_t arr_size>
void array<T, arr_size>::swap(array<T, arr_size> &other) noexcept {
    Expects(this != &other);

    array<T, arr_size> tmp = *this;
    *this = other;
    other = tmp;
}

template<typename T, const size_t arr_size>
auto array<T, arr_size>::data() noexcept -> pointer {
    return object;
}

template<typename T, const size_t arr_size>
auto array<T, arr_size>::data() const noexcept -> const_pointer {
    return object;
}

} // namespace psg

#endif
