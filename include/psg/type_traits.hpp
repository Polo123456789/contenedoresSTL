#ifndef PSG_TYPE_TRAITS_HPP
#define PSG_TYPE_TRAITS_HPP

#include <psg/type_traits/integral_constant.hpp>
#include <psg/type_traits/reference_modifications.hpp>
#include <psg/type_traits/const_volatile.hpp>
#include <psg/type_traits/primary_types.hpp>
#include <psg/type_traits/transformations.hpp>

// Copy paste grande desde cppreference, los ire incluyendo conforme me hagan
// falta.

namespace psg {

// composite type categories:
template<class T>
struct is_reference;
template<class T>
struct is_arithmetic;
template<class T>
struct is_fundamental;
template<class T>
struct is_object;
template<class T>
struct is_scalar;
template<class T>
struct is_compound;
template<class T>
struct is_member_pointer;

// type properties:
template<class T>
struct is_const;
template<class T>
struct is_volatile;
template<class T>
struct is_trivial;
template<class T>
struct is_trivially_copyable;
template<class T>
struct is_standard_layout;
template<class T>
struct is_pod;
template<class T>
struct is_empty;
template<class T>
struct is_polymorphic;
template<class T>
struct is_abstract;
template<class T>
struct is_final;
template<class T>
struct is_aggregate;
template<class T>
struct is_signed;
template<class T>
struct is_unsigned;
template<class T>
struct is_bounded_array;
template<class T>
struct is_unbounded_array;
template<class T, class... Args>
struct is_constructible;
template<class T>
struct is_default_constructible;
template<class T>
struct is_copy_constructible;
template<class T>
struct is_move_constructible;
template<class T, class U>
struct is_assignable;
template<class T>
struct is_copy_assignable;
template<class T>
struct is_move_assignable;
template<class T, class U>
struct is_swappable_with;
template<class T>
struct is_swappable;
template<class T>
struct is_destructible;
template<class T, class... Args>
struct is_trivially_constructible;
template<class T>
struct is_trivially_default_constructible;
template<class T>
struct is_trivially_copy_constructible;
template<class T>
struct is_trivially_move_constructible;
template<class T, class U>
struct is_trivially_assignable;
template<class T>
struct is_trivially_copy_assignable;
template<class T>
struct is_trivially_move_assignable;
template<class T>
struct is_trivially_destructible;
template<class T, class... Args>
struct is_nothrow_constructible;
template<class T>
struct is_nothrow_default_constructible;
template<class T>
struct is_nothrow_copy_constructible;
template<class T>
struct is_nothrow_move_constructible;
template<class T, class U>
struct is_nothrow_assignable;
template<class T>
struct is_nothrow_copy_assignable;
template<class T>
struct is_nothrow_move_assignable;
template<class T, class U>
struct is_nothrow_swappable_with;
template<class T>
struct is_nothrow_swappable;
template<class T>
struct is_nothrow_destructible;
template<class T>
struct has_virtual_destructor;
template<class T>
struct has_unique_object_representations;

// type property queries:
template<class T>
struct alignment_of;
template<class T>
struct rank;
template<class T, unsigned I = 0>
struct extent;

// type relations:
template<class T, class U>
struct is_same : public false_type {};
template<class T>
struct is_same<T, T> : public true_type {};

template<class Base, class Derived>
struct is_base_of;
template<class From, class To>
struct is_convertible;
template<class From, class To>
struct is_nothrow_convertible;
template<class T, class U>
struct is_layout_compatible;
template<class Base, class Derived>
struct is_pointer_interconvertible_base_of;
template<class Fn, class... ArgTypes>
struct is_invocable;
template<class R, class Fn, class... ArgTypes>
struct is_invocable_r;
template<class Fn, class... ArgTypes>
struct is_nothrow_invocable;
template<class R, class Fn, class... ArgTypes>
struct is_nothrow_invocable_r;

// sign modifications:
template<class T>
struct make_signed;
template<class T>
struct make_unsigned;
template<class T>
using make_signed_t = typename make_signed<T>::type;
template<class T>
using make_unsigned_t = typename make_unsigned<T>::type;

// array modifications:
template<class T>
struct remove_extent;
template<class T>
struct remove_all_extents;
template<class T>
using remove_extent_t = typename remove_extent<T>::type;
template<class T>
using remove_all_extents_t = typename remove_all_extents<T>::type;

// pointer modifications:
template<class T>
struct remove_pointer;
template<class T>
struct add_pointer;
template<class T>
using remove_pointer_t = typename remove_pointer<T>::type;
template<class T>
using add_pointer_t = typename add_pointer<T>::type;

// template<size_t Len, size_t Align = /*default-alignment*/>
// using aligned_storage_t = typename aligned_storage<Len, Align>::type;
template<size_t Len, class... Types>
using aligned_union_t = typename aligned_union<Len, Types...>::type;
template<class T>
using decay_t = typename decay<T>::type;
template<class T>
using remove_cvref_t = typename remove_cvref<T>::type;
template<bool b, class T = void>
using enable_if_t = typename enable_if<b, T>::type;
template<bool b, class T, class F>
using conditional_t = typename conditional<b, T, F>::type;
template<class... T>
using common_type_t = typename common_type<T...>::type;
template<class T>
using underlying_type_t = typename underlying_type<T>::type;
template<class T>
using result_of_t = typename result_of<T>::type;
template<class F, class... ArgTypes>
using invoke_result_t = typename invoke_result<F, ArgTypes...>::type;
template<class...>
using void_t = void;

// logical operator traits:
template<class... B>
struct conjunction;
template<class... B>
struct disjunction;
template<class B>
struct negation;

// primary type categories
template<class T>
constexpr bool is_void_v = is_void<T>::value;
template<class T>
constexpr bool is_null_pointer_v = is_null_pointer<T>::value;
template<class T>
constexpr bool is_integral_v = is_integral<T>::value;
template<class T>
constexpr bool is_floating_point_v = is_floating_point<T>::value;
template<class T>
constexpr bool is_array_v = is_array<T>::value;
template<class T>
constexpr bool is_pointer_v = is_pointer<T>::value;
template<class T>
constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;
template<class T>
constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;
template<class T>
constexpr bool is_member_object_pointer_v = is_member_object_pointer<T>::value;
template<class T>
constexpr bool is_member_function_pointer_v =
    is_member_function_pointer<T>::value;
template<class T>
constexpr bool is_enum_v = is_enum<T>::value;
template<class T>
constexpr bool is_union_v = is_union<T>::value;
template<class T>
constexpr bool is_class_v = is_class<T>::value;
template<class T>
constexpr bool is_function_v = is_function<T>::value;

// composite type categories
template<class T>
constexpr bool is_reference_v = is_reference<T>::value;
template<class T>
constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
template<class T>
constexpr bool is_fundamental_v = is_fundamental<T>::value;
template<class T>
constexpr bool is_object_v = is_object<T>::value;
template<class T>
constexpr bool is_scalar_v = is_scalar<T>::value;
template<class T>
constexpr bool is_compound_v = is_compound<T>::value;
template<class T>
constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

// type properties
template<class T>
constexpr bool is_const_v = is_const<T>::value;
template<class T>
constexpr bool is_volatile_v = is_volatile<T>::value;
template<class T>
constexpr bool is_trivial_v = is_trivial<T>::value;
template<class T>
constexpr bool is_trivially_copyable_v = is_trivially_copyable<T>::value;
template<class T>
constexpr bool is_standard_layout_v = is_standard_layout<T>::value;
template<class T>
constexpr bool is_pod_v = is_pod<T>::value;
template<class T>
constexpr bool is_empty_v = is_empty<T>::value;
template<class T>
constexpr bool is_polymorphic_v = is_polymorphic<T>::value;
template<class T>
constexpr bool is_abstract_v = is_abstract<T>::value;
template<class T>
constexpr bool is_final_v = is_final<T>::value;
template<class T>
constexpr bool is_aggregate_v = is_aggregate<T>::value;
template<class T>
constexpr bool is_signed_v = is_signed<T>::value;
template<class T>
constexpr bool is_unsigned_v = is_unsigned<T>::value;
template<class T>
constexpr bool is_bounded_array_v = is_bounded_array<T>::value;
template<class T>
constexpr bool is_unbounded_array_v = is_unbounded_array<T>::value;
template<class T, class... Args>
constexpr bool is_constructible_v = is_constructible<T, Args...>::value;
template<class T>
constexpr bool is_default_constructible_v = is_default_constructible<T>::value;
template<class T>
constexpr bool is_copy_constructible_v = is_copy_constructible<T>::value;
template<class T>
constexpr bool is_move_constructible_v = is_move_constructible<T>::value;
template<class T, class U>
constexpr bool is_assignable_v = is_assignable<T, U>::value;
template<class T>
constexpr bool is_copy_assignable_v = is_copy_assignable<T>::value;
template<class T>
constexpr bool is_move_assignable_v = is_move_assignable<T>::value;
template<class T, class U>
constexpr bool is_swappable_with_v = is_swappable_with<T, U>::value;
template<class T>
constexpr bool is_swappable_v = is_swappable<T>::value;
template<class T>
constexpr bool is_destructible_v = is_destructible<T>::value;
template<class T, class... Args>
constexpr bool is_trivially_constructible_v =
    is_trivially_constructible<T, Args...>::value;
template<class T>
constexpr bool is_trivially_default_constructible_v =
    is_trivially_default_constructible<T>::value;
template<class T>
constexpr bool is_trivially_copy_constructible_v =
    is_trivially_copy_constructible<T>::value;
template<class T>
constexpr bool is_trivially_move_constructible_v =
    is_trivially_move_constructible<T>::value;
template<class T, class U>
constexpr bool is_trivially_assignable_v = is_trivially_assignable<T, U>::value;
template<class T>
constexpr bool is_trivially_copy_assignable_v =
    is_trivially_copy_assignable<T>::value;
template<class T>
constexpr bool is_trivially_move_assignable_v =
    is_trivially_move_assignable<T>::value;
template<class T>
constexpr bool is_trivially_destructible_v =
    is_trivially_destructible<T>::value;
template<class T, class... Args>
constexpr bool is_nothrow_constructible_v =
    is_nothrow_constructible<T, Args...>::value;
template<class T>
constexpr bool is_nothrow_default_constructible_v =
    is_nothrow_default_constructible<T>::value;
template<class T>
constexpr bool is_nothrow_copy_constructible_v =
    is_nothrow_copy_constructible<T>::value;
template<class T>
constexpr bool is_nothrow_move_constructible_v =
    is_nothrow_move_constructible<T>::value;
template<class T, class U>
constexpr bool is_nothrow_assignable_v = is_nothrow_assignable<T, U>::value;
template<class T>
constexpr bool is_nothrow_copy_assignable_v =
    is_nothrow_copy_assignable<T>::value;
template<class T>
constexpr bool is_nothrow_move_assignable_v =
    is_nothrow_move_assignable<T>::value;
template<class T, class U>
constexpr bool is_nothrow_swappable_with_v =
    is_nothrow_swappable_with<T, U>::value;
template<class T>
constexpr bool is_nothrow_swappable_v = is_nothrow_swappable<T>::value;
template<class T>
constexpr bool is_nothrow_destructible_v = is_nothrow_destructible<T>::value;
template<class T>
constexpr bool has_virtual_destructor_v = has_virtual_destructor<T>::value;
template<class T>
constexpr bool has_unique_object_representations_v =
    has_unique_object_representations<T>::value;

// type property queries
template<class T>
constexpr size_t alignment_of_v = alignment_of<T>::value;
template<class T>
constexpr size_t rank_v = rank<T>::value;
template<class T, unsigned I = 0>
constexpr size_t extent_v = extent<T, I>::value;

// type relations
template<class T, class U>
constexpr bool is_same_v = is_same<T, U>::value;
template<class Base, class Derived>
constexpr bool is_base_of_v = is_base_of<Base, Derived>::value;
template<class From, class To>
constexpr bool is_convertible_v = is_convertible<From, To>::value;
template<class From, class To>
constexpr bool is_nothrow_convertible_v =
    is_nothrow_convertible<From, To>::value;
template<class T, class U>
constexpr bool is_layout_compatible_v = is_layout_compatible<T, U>::value;
template<class Base, class Derived>
constexpr bool is_pointer_interconvertible_base_of_v =
    is_pointer_interconvertible_base_of<Base, Derived>::value;

template<class Fn, class... ArgTypes>
constexpr bool is_invocable_v = is_invocable<Fn, ArgTypes...>::value;
template<class R, class Fn, class... ArgTypes>
constexpr bool is_invocable_r_v = is_invocable_r<R, Fn, ArgTypes...>::value;
template<class Fn, class... ArgTypes>
constexpr bool is_nothrow_invocable_v =
    is_nothrow_invocable<Fn, ArgTypes...>::value;
template<class R, class Fn, class... ArgTypes>
constexpr bool is_nothrow_invocable_r_v =
    is_nothrow_invocable_r<R, Fn, ArgTypes...>::value;

// logical operator traits:
template<class... B>
constexpr bool conjunction_v = conjunction<B...>::value;
template<class... B>
constexpr bool disjunction_v = disjunction<B...>::value;
template<class B>
constexpr bool negation_v = negation<B>::value;

// member relationships
template<class S, class M>
constexpr bool is_pointer_interconvertible_with_class(M S::*m) noexcept;
template<class S1, class S2, class M1, class M2>
constexpr bool is_corresponding_member(M1 S1::*m1, M2 S2::*m2) noexcept;

// constant evaluation context
constexpr bool is_constant_evaluated() noexcept;
}; // namespace psg

#endif
