#ifndef PSG_TYPE_TRAITS_REFERENCE_MODIFICATIONS_HPP
#define PSG_TYPE_TRAITS_REFERENCE_MODIFICATIONS_HPP

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

namespace imp {

// https://en.cppreference.com/w/cpp/types/add_reference
template<class T>
struct type_identity {
    using type = T;
};

template<class T>
auto try_add_lvalue_reference(int) -> type_identity<T &>;
template<class T>
auto try_add_lvalue_reference(...) -> type_identity<T>;

template<class T>
auto try_add_rvalue_reference(int) -> type_identity<T &&>;
template<class T>
auto try_add_rvalue_reference(...) -> type_identity<T>;

}; // namespace imp

template<class T>
struct add_lvalue_reference : decltype(imp::try_add_lvalue_reference<T>(0)) {};

template<class T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template<class T>
struct add_rvalue_reference : decltype(imp::try_add_rvalue_reference<T>(0)) {};

template<class T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

}; // namespace psg

#endif
