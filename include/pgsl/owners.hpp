#ifndef PGSL_OWNERS_HPP
#define PGSL_OWNERS_HPP

#include <psg/memory.hpp>
#include <psg/array.hpp>
#include <psg/vector.hpp>

namespace pgsl {

using psg::unique_ptr;
// using psg::shared_ptr;

template<typename T, size_t size>
using stack_array = psg::array<T, size>;

template<typename T, typename Alloc>
using dyn_array = psg::vector<T, Alloc>;

} // namespace pgsl

#endif
