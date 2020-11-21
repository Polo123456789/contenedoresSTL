/*
 * Descripcion de la clase:
 *
 *  LegacyRandomAccesIterator
 *
 *      Es un LegacyRandAccesIter que se puede mover a cualquier
 *      elemtento en timempo constante.
 *
 * */

#ifndef PSG_ITERATOR_LEGACY_RANDOM_ACCES_ITERATOR_HPP
#define PSG_ITERATOR_LEGACY_RANDOM_ACCES_ITERATOR_HPP

#include <cstddef>
#include <cstdint>

#include <psg/iterator.hpp>

namespace psg {
namespace iterators {

template<typename T>
class LegacyRandomAccesIterator {
    using LegacyRandAccesIter = LegacyRandomAccesIterator<T>;

   public:
    using value_type = T;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    LegacyRandomAccesIterator(pointer first_element,
        size_type position) noexcept;
    LegacyRandAccesIter &operator--(void) noexcept;
    LegacyRandAccesIter operator--(int) noexcept;
    LegacyRandAccesIter &operator++(void) noexcept;
    LegacyRandAccesIter operator++(int) noexcept;
    bool operator==(const LegacyRandAccesIter &other) noexcept;
    bool operator!=(const LegacyRandAccesIter &other) noexcept;
    reference operator*(void) noexcept;
    pointer operator->() noexcept;
    LegacyRandAccesIter &operator+=(size_type amount) noexcept;
    LegacyRandAccesIter operator+(size_type amount) const noexcept;
    LegacyRandAccesIter &operator-=(size_type amount) noexcept;
    LegacyRandAccesIter operator-(size_type amount) const noexcept;
    difference_type operator-(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator<(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator>(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator<=(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator>=(const LegacyRandAccesIter &rhs) const noexcept;
    reference operator[](size_type index) noexcept;
};

}; // namespace iterators
}; // namespace psg

#endif
