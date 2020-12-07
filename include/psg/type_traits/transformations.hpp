#ifndef PSG_TYPE_TRAITS_TRANSFORMATIONS_HPP
#define PSG_TYPE_TRAITS_TRANSFORMATIONS_HPP

#include <cstddef>

namespace psg {

// template<size_t Len, size_t Align = /*default-alignment*/>
// struct aligned_storage;
template<size_t Len, class... Types>
struct aligned_union;

template<class T>
struct decay;

template<class T>
struct remove_cvref;

template<bool B, class T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T> {
    using type = T;
};

template<bool B, class T, class F>
struct conditional;

template<typename T, typename F>
struct conditional<true, T, F> {
    using type = T;
};

template<typename T, typename F>
struct conditional<false, T, F> {
    using type = F;
};

template<class... T>
struct common_type;

template<class T>
struct underlying_type;

template<class>
class result_of; // not defined

template<class F, class... ArgTypes>
class result_of<F(ArgTypes...)>;

template<class F, class... ArgTypes>
class invoke_result;

} // namespace psg

#endif
