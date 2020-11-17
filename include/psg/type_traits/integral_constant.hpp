#ifndef PSG_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP
#define PSG_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP

namespace psg {

template<class T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr value_type operator()() const noexcept {
        return value;
    }
    // NOLINTNEXTLINE Este intencionalmente quiero que no sea explicito
    constexpr operator value_type() const noexcept {
        return value;
    }
};

template<bool B>
using bool_constant = integral_constant<bool, B>;
using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

}; // namespace psg

#endif
