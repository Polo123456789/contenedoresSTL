/*
 * .------..------..------..------..------.
 * |P.--. ||A.--. ||B.--. ||L.--. ||O.--. |
 * | :/\: || (\/) || :(): || :/\: || :/\: |
 * | (__) || :\/: || ()() || (__) || :\/: |
 * | '--'P|| '--'A|| '--'B|| '--'L|| '--'O|
 * `------'`------'`------'`------'`------'
 * .------..------..------..------..------..------..------.
 * |S.--. ||A.--. ||N.--. ||C.--. ||H.--. ||E.--. ||Z.--. |
 * | :/\: || (\/) || :(): || :/\: || :/\: || (\/) || :(): |
 * | :\/: || :\/: || ()() || :\/: || (__) || :\/: || ()() |
 * | '--'S|| '--'A|| '--'N|| '--'C|| '--'H|| '--'E|| '--'Z|
 * `------'`------'`------'`------'`------'`------'`------'
 *
 * Copyright (c) 2020 Pablo Sanchez Galdamez
 *
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

#include <iterator.hpp>

namespace psg {

///Especializacion del plus para utilizarlo con el legacy random acces iterator
template<typename T>
struct plus {
    T *operator()(T *a, size_t b) {
        return a + b;
    }

    T *operator()(T *a, int64_t b) {
        return a + b;
    }
    const T *operator()(const T *a, size_t b) {
        return a + b;
    }

    const T *operator()(const T *a, int64_t b) {
        return a + b;
    }
};

///Especializacion del minus para utilizarlo con el legacy random acces iterator
template<typename T>
struct minus {
    T *operator()(T *a, size_t b) {
        return a - b;
    }

    T *operator()(T *a, int64_t b) {
        return a - b;
    }
    const T *operator()(const T *a, size_t b) {
        return a - b;
    }

    const T *operator()(const T *a, int64_t b) {
        return a - b;
    }
};

namespace iterators {

template<typename T, typename Operation = psg::plus<T>>
class LegacyRandomAccesIterator {
    using LegacyRandAccesIter = LegacyRandomAccesIterator<T, Operation>;

   public:
    using iterator_category = random_acces_iterator_tag;
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

   private:
    pointer object = nullptr;
    Operation operation{};
};

template<typename T, typename Operation>
using LRAI = LegacyRandomAccesIterator<T, Operation>;

template<typename T, typename Operation>
LRAI<T, Operation>::LegacyRandomAccesIterator(T *first_element,
    size_t position) noexcept {

    object = operation(first_element, position);
}

template<typename T, typename Operation>
LRAI<T, Operation> &LRAI<T, Operation>::operator--() noexcept {
    object = operation(object, -1LL);
}

template<typename T, typename Operation>
LRAI<T, Operation> LRAI<T, Operation>::operator--(int) noexcept {
    LRAI<T, Operation> tmp = *this;
    this->operator--();
    return tmp;
}

template<typename T, typename Operation>
LRAI<T, Operation> &LRAI<T, Operation>::operator++() noexcept {
    object = operation(object, 1LL);
    return *this;
}

template<typename T, typename Operation>
LRAI<T, Operation> LRAI<T, Operation>::operator++(int) noexcept {
    LRAI<T, Operation> tmp = *this;
    this->operator++();
    return tmp;
}

template<typename T, typename Operation>
bool LRAI<T, Operation>::operator==(const LegacyRandAccesIter &other) noexcept {
    return object == other.object;
}

template<typename T, typename Operation>
bool LRAI<T, Operation>::operator!=(const LegacyRandAccesIter &other) noexcept {
    return object != other.object;
}

template<typename T, typename Operation>
typename LRAI<T, Operation>::reference LRAI<T, Operation>::operator*(
    void) noexcept {

    return *object;
}

template<typename T, typename Operation>
typename LRAI<T, Operation>::pointer LRAI<T, Operation>::operator->() noexcept {
    return object;
}

template<typename T, typename Operation>
LRAI<T, Operation> &LRAI<T, Operation>::operator+=(size_type amount) noexcept {
    object = operation(object, amount);
    return *this;
}

template<typename T, typename Operation>
LRAI<T, Operation> LRAI<T, Operation>::operator+(
    size_type amount) const noexcept {
    LRAI<T, Operation> tmp;
    tmp += amount;
    return tmp;
}

template<typename T, typename Operation>
LRAI<T, Operation> &LRAI<T, Operation>::operator-=(size_type amount) noexcept {
    object = operation(object, -1 * amount);
    return *this;
}

template<typename T, typename Operation>
LRAI<T, Operation> LRAI<T, Operation>::operator-(
    size_type amount) const noexcept {
    LRAI<T, Operation> tmp;
    tmp -= amount;
    return tmp;
}

template<typename T, typename Operation>
typename LRAI<T, Operation>::difference_type LRAI<T, Operation>::operator-(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object - rhs.object;
}

template<typename T, typename Operation>
bool LRAI<T, Operation>::operator<(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object < rhs.object;
}

template<typename T, typename Operation>
bool LRAI<T, Operation>::operator>(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object > rhs.object;
}

template<typename T, typename Operation>
bool LRAI<T, Operation>::operator<=(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object <= rhs.object;
}

template<typename T, typename Operation>
bool LRAI<T, Operation>::operator>=(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object >= rhs.object;
}

template<typename T, typename Operation>
typename LRAI<T, Operation>::reference LRAI<T, Operation>::operator[](
    size_type index) noexcept {
    return object[index];
}

namespace constant {

template<typename T, typename Operation = psg::plus<T>>
class LegacyRandomAccesIterator {
    using LegacyRandAccesIter = LegacyRandomAccesIterator<T, Operation>;

   public:
    using iterator_category = random_acces_iterator_tag;
    using value_type = T;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    LegacyRandomAccesIterator(const_pointer first_element,
        size_type position) noexcept;
    LegacyRandAccesIter &operator--(void) noexcept;
    LegacyRandAccesIter operator--(int) noexcept;
    LegacyRandAccesIter &operator++(void) noexcept;
    LegacyRandAccesIter operator++(int) noexcept;
    bool operator==(const LegacyRandAccesIter &other) noexcept;
    bool operator!=(const LegacyRandAccesIter &other) noexcept;
    const_reference operator*(void) noexcept;
    const_pointer operator->() noexcept;
    LegacyRandAccesIter &operator+=(size_type amount) noexcept;
    LegacyRandAccesIter operator+(size_type amount) const noexcept;
    LegacyRandAccesIter &operator-=(size_type amount) noexcept;
    LegacyRandAccesIter operator-(size_type amount) const noexcept;
    difference_type operator-(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator<(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator>(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator<=(const LegacyRandAccesIter &rhs) const noexcept;
    bool operator>=(const LegacyRandAccesIter &rhs) const noexcept;
    const_reference operator[](size_type index) noexcept;

   private:
    const_pointer object = nullptr;
    Operation operation{};
};

template<typename T, typename Operation>
using CLRAI = LegacyRandomAccesIterator<T, Operation>;

template<typename T, typename Operation>
CLRAI<T, Operation>::LegacyRandomAccesIterator(const T *first_element,
    size_t position) noexcept
{
    object = operation(first_element, position);
}

template<typename T, typename Operation>
CLRAI<T, Operation> &CLRAI<T, Operation>::operator--() noexcept {
    object = operation(object, -1LL);
}

template<typename T, typename Operation>
CLRAI<T, Operation> CLRAI<T, Operation>::operator--(int) noexcept {
    CLRAI<T, Operation> tmp = *this;
    this->operator--();
    return tmp;
}

template<typename T, typename Operation>
CLRAI<T, Operation> &CLRAI<T, Operation>::operator++() noexcept {
    object = operation(object, 1LL);
    return *this;
}

template<typename T, typename Operation>
CLRAI<T, Operation> CLRAI<T, Operation>::operator++(int) noexcept {
    CLRAI<T, Operation> tmp = *this;
    this->operator++();
    return tmp;
}

template<typename T, typename Operation>
bool CLRAI<T, Operation>::operator==(const LegacyRandAccesIter &other) noexcept {
    return object == other.object;
}

template<typename T, typename Operation>
bool CLRAI<T, Operation>::operator!=(const LegacyRandAccesIter &other) noexcept {
    return object != other.object;
}

template<typename T, typename Operation>
typename CLRAI<T, Operation>::const_reference CLRAI<T, Operation>::operator*(
    void) noexcept {

    return *object;
}

template<typename T, typename Operation>
typename CLRAI<T, Operation>::const_pointer CLRAI<T, Operation>::operator->() noexcept {
    return object;
}

template<typename T, typename Operation>
CLRAI<T, Operation> &CLRAI<T, Operation>::operator+=(size_type amount) noexcept {
    object = operation(object, amount);
    return *this;
}

template<typename T, typename Operation>
CLRAI<T, Operation> CLRAI<T, Operation>::operator+(
    size_type amount) const noexcept {
    CLRAI<T, Operation> tmp;
    tmp += amount;
    return tmp;
}

template<typename T, typename Operation>
CLRAI<T, Operation> &CLRAI<T, Operation>::operator-=(size_type amount) noexcept {
    object = operation(object, -1 * amount);
    return *this;
}

template<typename T, typename Operation>
CLRAI<T, Operation> CLRAI<T, Operation>::operator-(
    size_type amount) const noexcept {
    CLRAI<T, Operation> tmp;
    tmp -= amount;
    return tmp;
}

template<typename T, typename Operation>
typename CLRAI<T, Operation>::difference_type CLRAI<T, Operation>::operator-(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object - rhs.object;
}

template<typename T, typename Operation>
bool CLRAI<T, Operation>::operator<(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object < rhs.object;
}

template<typename T, typename Operation>
bool CLRAI<T, Operation>::operator>(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object > rhs.object;
}

template<typename T, typename Operation>
bool CLRAI<T, Operation>::operator<=(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object <= rhs.object;
}

template<typename T, typename Operation>
bool CLRAI<T, Operation>::operator>=(
    const LegacyRandAccesIter &rhs) const noexcept {
    return object >= rhs.object;
}

template<typename T, typename Operation>
typename CLRAI<T, Operation>::const_reference CLRAI<T, Operation>::operator[](
    size_type index) noexcept {
    return object[index];
}

}; // namespace constant

}; // namespace iterators
}; // namespace psg

#endif
