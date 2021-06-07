#ifndef PSG_UTILITY_FUNCTIONS_HPP
#define PSG_UTILITY_FUNCTIONS_HPP

#include <psg/type_traits/reference_modifications.hpp>

namespace psg {

/**
 * Indica que los recursos se pueden "mover" de un objeto a otro.
 */
template<typename T>
remove_reference_t<T> move(T &&t) {
    return static_cast<remove_reference_t<T> &&>(t);
}

/**
 * @return lvalue o rvalue dependiendo de T
 */
template<typename T>
T &&forward(remove_reference_t<T> &t) {
    return static_cast<T &&>(t);
}

/**
 * @return lvalue o rvalue dependiendo de T
 */
template<typename T>
T &&forward(remove_reference_t<T> &&t) {
    return static_cast<T &&>(t);
}

/**
 * Intercambia `a` y `b`
 */
template<typename T>
void swap(T &a, T &b) noexcept {
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

/**
 * @param obj Objeto al que se le cambiara el valor
 * @param new_value Nuevo valor para objeto
 * @return El viejo valor de objeto
 */
template<typename T, typename U = T>
T exchange(T &obj, U &&new_value) {
    T tmp = move(obj);
    obj = forward<U>(new_value);
    return tmp;
}

}; // namespace psg

#endif
