#ifndef PSG_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP
#define PSG_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP

namespace psg {

/**
 * Envuelve una constante de un tipo
 */
template<class T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr value_type operator()() const noexcept {
        return value;
    }
    constexpr operator value_type() const noexcept /*NOLINT [[implicit]]*/ {
        return value;
    }
};

/**
 * Envuelve una constante booleana
 */
template<bool B>
using bool_constant = integral_constant<bool, B>;

/**
 * Tipo cuyo valor siempre evaluara a verdadero
 */
using true_type = bool_constant<true>;

/**
 * Tipo cuyo valor siempre evaluara a falso
 */
using false_type = bool_constant<false>;

}; // namespace psg

#endif
