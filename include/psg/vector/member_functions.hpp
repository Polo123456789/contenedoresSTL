#ifndef PSG_VECTOR_MEMBER_FUNCTIONS_HPP
#define PSG_VECTOR_MEMBER_FUNCTIONS_HPP

#include <psg/vector/class.hpp>

namespace psg {

template<class T, class Allocator>
vector<T, Allocator>::~vector() noexcept {
}

template<class T, class Allocator>
Allocator vector<T, Allocator>::get_allocator() const noexcept {
}

template<class T, class Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(const vector &x) {
}

template<class T, class Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(vector &&x) noexcept {
}

template<class T, class Allocator>
template<class InputIt>
void vector<T, Allocator>::assign(InputIt first, InputIt last) {
}

template<class T, class Allocator>
void vector<T, Allocator>::assign(size_type n, const T &u) {
}

}; // namespace psg

#endif
