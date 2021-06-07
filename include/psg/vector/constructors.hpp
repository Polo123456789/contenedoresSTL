#ifndef PSG_VECTOR_CONSTRUCTOR_HPP
#define PSG_VECTOR_CONSTRUCTOR_HPP

#include <psg/vector/class.hpp>

#include <psg/algorithm.hpp>

namespace psg {

template<class T, class Allocator>
vector<T, Allocator>::vector(const Allocator &allocator) noexcept
    : alloc(allocator) {

    object = resource_handler(nullptr, alloc);
}

template<class T, class Allocator>
vector<T, Allocator>::vector(size_type n, const Allocator &allocator)
    : alloc(allocator), allocated_space(n),
      object(traits::allocate(alloc, allocated_space), alloc, allocated_space) {
}

template<class T, class Allocator>
vector<T, Allocator>::vector(size_type        n,
                             const T &        value,
                             const Allocator &allocator)
    : alloc(allocator), allocated_space(n),
      object(traits::allocate(alloc, allocated_space), alloc, allocated_space) {

    try {

        for_each(this->begin(), this->begin() + n, [&](reference r) {
            traits::construct(alloc, addressof(r), value);
            ++last_valid_element;
        });

    } catch (...) {
        // Destroy constructed objects and free the memory
        this->clear();
        object.reset();
        throw;
    }
}

template<class T, class Allocator>
template<class InputIt>
vector<T, Allocator>::vector(InputIt          first,
                             InputIt          last,
                             const Allocator &allocator) {}

template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &other)
    : vector(other,
             allocator_traits<Allocator>::select_on_container_copy_construction(
                 other.get_allocator())) {}

template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &other, const Allocator &a) {}

template<class T, class Allocator>
vector<T, Allocator>::vector(vector &&other) noexcept {}

template<class T, class Allocator>
vector<T, Allocator>::vector(vector &&other, const Allocator &a) {}

}; // namespace psg

#endif
