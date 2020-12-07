#ifndef PSG_TYPE_TRAITS_PRIMARY_TYPES_HPP
#define PSG_TYPE_TRAITS_PRIMARY_TYPES_HPP

#include <psg/type_traits/integral_constant.hpp>
#include <psg/type_traits/const_volatile.hpp>

namespace psg {

template<class T>
struct is_void;

template<class T>
struct is_null_pointer;

template<class T>
struct is_integral;

template<class T>
struct is_floating_point;

template<class T>
struct is_array;

template<class T>
struct is_pointer_helper : public false_type {};

template<class T>
struct is_pointer_helper<T*> : public true_type {};

template<class T>
struct is_pointer : public is_pointer_helper<remove_cv_t<T>> {};

template<class T>
struct is_lvalue_reference;

template<class T>
struct is_rvalue_reference;

template<class T>
struct is_member_object_pointer;

template<class T>
struct is_member_function_pointer;

template<class T>
struct is_enum;

template<class T>
struct is_union;

template<class T>
struct is_class;

template<class T>
struct is_function;

} // namespace psg

#endif
