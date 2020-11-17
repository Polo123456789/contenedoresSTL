#ifndef PSG_VECTOR_USING_DECL_HPP
#define PSG_VECTOR_USING_DECL_HPP

#include <psg/vector/class.hpp>

namespace psg::imp {

template<class T, class Allocator>
using vec_value_t = typename vector<T, Allocator>::value_type;
template<class T, class Allocator>
using vec_alloc_t = typename vector<T, Allocator>::allocator_type;
template<class T, class Allocator>
using vec_ptr_t = typename vector<T, Allocator>::pointer;
template<class T, class Allocator>
using vec_const_ptr_t = typename vector<T, Allocator>::const_pointer;
template<class T, class Allocator>
using vec_ref_t = typename vector<T, Allocator>::reference;
template<class T, class Allocator>
using vec_const_ref_t = typename vector<T, Allocator>::const_reference;
template<class T, class Allocator>
using vec_size_t = typename vector<T, Allocator>::size_type;
template<class T, class Allocator>
using vec_diff_t = typename vector<T, Allocator>::difference_type;
template<class T, class Allocator>
using vec_iter_t = typename vector<T, Allocator>::iterator;
template<class T, class Allocator>
using vec_const_iter_t = typename vector<T, Allocator>::const_iterator;
template<class T, class Allocator>
using vec_rev_iter_t = typename vector<T, Allocator>::reverse_iterator;
template<class T, class Allocator>
using vec_const_rev_iter_t =
    typename vector<T, Allocator>::const_reverse_iterator;

}; // namespace psg::imp

#endif
