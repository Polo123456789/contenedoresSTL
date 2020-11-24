#ifndef PSG_UTILITY_FUNCTIONS_HPP
#define PSG_UTILITY_FUNCTIONS_HPP

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
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

/// Le da a obj el valor dado, y regresa el valor anterior de obj
template<typename T, typename U = T>
T exchange(T& obj, U&& new_value) {
    T tmp = move(obj);
    obj = forward<U>(new_value);
    return tmp;
}

}; // namespace psg

#endif
