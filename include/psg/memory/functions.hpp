#ifndef PSG_MEMORY_FUNCTIONS_HPP
#define PSG_MEMORY_FUNCTIONS_HPP

#include <psg/algorithm.hpp>
#include <psg/utility.hpp>

namespace psg {

namespace imp {

constexpr bool addresof_by_casting = true;

}

/**
 * @return La direccion de memoria de `arg`
 */
template<typename T>
T *addressof(T &arg) noexcept {
    if constexpr (imp::addresof_by_casting) {
        return reinterpret_cast<T *>(                           // NOLINT
            &const_cast<char &>(                                // NOLINT
                reinterpret_cast<const volatile char &>(arg))); // NOLINT
    } else {
        return &arg;
    }
}

/**
 * Contruye un elemento a en la direccion de memoria de `p` usando el paquete de
 * argumentos que se le dio.
 */
template<typename T, typename... Args>
T *construct_at(T *p, Args &&...args) {
    new (p) T(forward<Args>(args)...);
    return p;
}

/**
 * Destruye un elemento a en la direccion de memoria de `p`.
 */
template<typename T>
void destroy_at(T *p) noexcept {
    p->~T();
}

/**
 * Destruye todos los elementos en el rango first - last
 */
template<typename ForwardIt>
void destroy(ForwardIt first, ForwardIt last) {
    auto destroy_element = [](ForwardIt it) {
        destroy_at(addressof(*it));
    };
    for_each(first, last, destroy_element);
}

}; // namespace psg

#endif
