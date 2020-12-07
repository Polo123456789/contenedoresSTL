#ifndef PSG_TYPE_TRAITS_CONST_VOLATILE_HPP
#define PSG_TYPE_TRAITS_CONST_VOLATILE_HPP

#include <psg/type_traits/integral_constant.hpp>

namespace psg {

template<class T>
struct remove_const {
    using type = T;
};

template<class T>
struct remove_const<const T> {
    using type = T;
};

template<class T>
struct remove_volatile {
    using type = T;
};

template<class T>
struct remove_volatile<volatile T> {
    using type = T;
};

template<class T>
struct remove_cv {
    using type = typename remove_const<typename remove_volatile<T>::type>::type;
};

template<class T>
struct add_const;

template<class T>
struct add_volatile;

template<class T>
struct add_cv;

template<class T>
using remove_const_t = typename remove_const<T>::type;

template<class T>
using remove_volatile_t = typename remove_volatile<T>::type;

template<class T>
using remove_cv_t = typename remove_cv<T>::type;

template<class T>
using add_const_t = typename add_const<T>::type;

template<class T>
using add_volatile_t = typename add_volatile<T>::type;

template<class T>
using add_cv_t = typename add_cv<T>::type;

} // namespace psg

#endif
