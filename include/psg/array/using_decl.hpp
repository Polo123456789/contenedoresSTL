#ifndef PSG_ARRAY_USING_DECL_HPP
#define PSG_ARRAY_USING_DECL_HPP

#include <psg/array/class.hpp>

namespace psg::imp {

template<typename T, const size_t arr_size>
using arr_value_t = typename array<T, arr_size>::value_type;
template<typename T, const size_t arr_size>
using arr_ptr_t = typename array<T, arr_size>::pointer;
template<typename T, const size_t arr_size>
using arr_const_ptr_t = typename array<T, arr_size>::const_pointer;
template<typename T, const size_t arr_size>
using arr_ref_t = typename array<T, arr_size>::reference;
template<typename T, const size_t arr_size>
using arr_const_ref_t = typename array<T, arr_size>::const_reference;
template<typename T, const size_t arr_size>
using arr_size_t = typename array<T, arr_size>::size_type;
template<typename T, const size_t arr_size>
using arr_diff_r = typename array<T, arr_size>::difference_type;
template<typename T, const size_t arr_size>
using arr_iter = typename array<T, arr_size>::iterator;
template<typename T, const size_t arr_size>
using arr_rev_iter = typename array<T, arr_size>::reverse_iterator;
template<typename T, const size_t arr_size>
using arr_const_iter = typename array<T, arr_size>::const_iterator;
template<typename T, const size_t arr_size>
using arr_const_rev_iter = typename array<T, arr_size>::const_reverse_iterator;

} // namespace psg::imp

#endif
