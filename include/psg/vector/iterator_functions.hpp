#ifndef PSG_VECTOR_ITERATOR_FUNCTIONS
#define PSG_VECTOR_ITERATOR_FUNCTIONS

#include <psg/vector/class.hpp>

namespace psg {

namespace imp {

template<typename T>
using VecIter = iterators::LegacyRandomAccesIterator<T>;

template<typename T>
using VecRevIter = iterators::LegacyRandomAccesIterator<T, psg::minus<T>>;

template<typename T>
using VecConstIter = iterators::constant::LegacyRandomAccesIterator<T>;

template<typename T>
using VecConstRevIter =
    iterators::constant::LegacyRandomAccesIterator<T, psg::minus<T>>;

}; // namespace imp

/// Iterador al principio del contenedor.
template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() noexcept {
    return imp::VecIter<T>(object, 0);
}

/// Iterador constante al principio del contenedor.
template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::begin() const noexcept {

    return imp::VecConstIter<T>(object, 0);
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() noexcept {
    return imp::VecIter<T>(object, last_valid_element);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::end() const noexcept {

    return imp::VecConstIter<T>(object, last_valid_element);
}

};  // namespace psg

#endif
