#ifndef PSG_UTILITY_HPP
#define PSG_UTILITY_HPP

#include <psg/type_traits/reference_modifications.hpp>

namespace psg {

/// Convierte un lvalue a un rvalue
template<typename T>
remove_reference_t<T> move(T&& t) {
    return static_cast<remove_reference_t<T>&&>(t);
}

/// Hace un perfect forwarding en los argumentos dados
template<typename T>
T&& forward(remove_reference_t<T>& t) {
    return static_cast<T&&>(t);
}

/// Hace un perfect forwarding en los argumentos dados
template<typename T>
T&& forward(remove_reference_t<T>&& t) {
    return static_cast<T&&>(t);
}

/// Intercambia los valores
template<typename T>
void swap(T& a, T& b) noexcept {
    T tmp = a;
    a = b;
    b = tmp;
}


}; // namespace psg

#endif
