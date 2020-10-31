#ifndef PSG_UTILITY_HPP
#define PSG_UTILITY_HPP

//#define PSG_S1(x) #x
//#define PSG_S2(x) PSG_S1(x)
//#define PSG_LOCATION __FILE__ " : " PSG_S2(__LINE__)

namespace psg {

/// Tiene el miemrbo type, que elimina la referencia.
///
/// Si T es una referencia, nos da un miembro type que la elimina. Se usan 3 de
/// estas:
///
/// * remove_reference<T>
/// * remove_reference<T&>
/// * remove_reference<T&&>
///
/// Entonces para las 3 se tiene el type que sera unicamente T.
template<typename T>
struct remove_reference {
    using type = T;
};

/// Ver psg::remove_reference
template<typename T>
struct remove_reference<T &> {
    using type = T;
};

/// Ver psg::remove_reference
template<typename T>
struct remove_reference<T &&> {
    using type = T;
};

/// Para hacer mas conveniente el acceso al tipo.
template<typename T>
using remove_reference_t = typename remove_reference<T>::type;

/// Convierte un lvalue a un rvalue
template<typename T>
remove_reference_t<T> move(T&& t) {
    return static_cast<remove_reference_t<T>&&>(t);
}

template<typename T>
T&& forward(remove_reference_t<T>& t) {
    return static_cast<T&&>(t);
}

template<typename T>
T&& forward(remove_reference_t<T>&& t) {
    return static_cast<T&&>(t);
}

}; // namespace psg
#endif
