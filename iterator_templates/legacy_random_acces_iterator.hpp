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

namespace psg {

template<typename T>
class plus {
    T *operator()(T *a, size_t b) {
        return a + b;
    }

    T *operator()(T *a, int64_t b) {
        return a + b;
    }
};

template<typename T>
class minus {
    T *operator()(T *a, size_t b) {
        return a - b;
    }

    T *operator()(T *a, int64_t b) {
        return a - b;
    }
};

namespace imp {

template<typename T, typename Operation = psg::plus<T>>
class LegacyRandomAccesIterator {
    using LegacyRandAccesIter = LegacyRandomAccesIterator<T, Operation>;

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

   private:
    pointer object = nullptr;
    Operation operation{};
};

template<typename T, typename Operation>
using LRAI = LegacyRandomAccesIterator<T, Operation>;

template<typename T, typename Operation>
LRAI<T, Operation>::LegacyRandomAccesIterator(T *first_element,
    size_t position) noexcept
    : object(operation(first_element, position)) {}

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

    return *this;
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

namespace tmp {

template<typename T, typename Operation = psg::plus<T>>
class LegacyConstRandomAccesIterator {
    using LegacyConstRandAccesIter = LegacyConstRandomAccesIterator<T, Operation>;

   public:
    using value_type = T;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    LegacyConstRandomAccesIterator(pointer first_element,
        size_type position) noexcept;
    LegacyConstRandAccesIter &operator--(void) noexcept;
    LegacyConstRandAccesIter operator--(int) noexcept;
    LegacyConstRandAccesIter &operator++(void) noexcept;
    LegacyConstRandAccesIter operator++(int) noexcept;
    bool operator==(const LegacyConstRandAccesIter &other) noexcept;
    bool operator!=(const LegacyConstRandAccesIter &other) noexcept;
    reference operator*(void) noexcept;
    pointer operator->() noexcept;
    LegacyConstRandAccesIter &operator+=(size_type amount) noexcept;
    LegacyConstRandAccesIter operator+(size_type amount) const noexcept;
    LegacyConstRandAccesIter &operator-=(size_type amount) noexcept;
    LegacyConstRandAccesIter operator-(size_type amount) const noexcept;
    difference_type operator-(const LegacyConstRandAccesIter &rhs) const noexcept;
    bool operator<(const LegacyConstRandAccesIter &rhs) const noexcept;
    bool operator>(const LegacyConstRandAccesIter &rhs) const noexcept;
    bool operator<=(const LegacyConstRandAccesIter &rhs) const noexcept;
    bool operator>=(const LegacyConstRandAccesIter &rhs) const noexcept;
    reference operator[](size_type index) noexcept;

   private:
    pointer object = nullptr;
    Operation operation{};
};

template<typename T, typename Operation>
using LCRAI = LegacyConstRandomAccesIterator<T, Operation>;

template<typename T, typename Operation>
LCRAI<T, Operation>::LegacyConstRandomAccesIterator(T *first_element,
    size_t position) noexcept
    : object(operation(first_element, position)) {}

template<typename T, typename Operation>
LCRAI<T, Operation> &LCRAI<T, Operation>::operator--() noexcept {
    object = operation(object, -1LL);
}

template<typename T, typename Operation>
LCRAI<T, Operation> LCRAI<T, Operation>::operator--(int) noexcept {
    LCRAI<T, Operation> tmp = *this;
    this->operator--();
    return tmp;
}

template<typename T, typename Operation>
LCRAI<T, Operation> &LCRAI<T, Operation>::operator++() noexcept {
    object = operation(object, 1LL);
}

template<typename T, typename Operation>
LCRAI<T, Operation> LCRAI<T, Operation>::operator++(int) noexcept {
    LCRAI<T, Operation> tmp = *this;
    this->operator++();
    return tmp;
}

template<typename T, typename Operation>
bool LCRAI<T, Operation>::operator==(const LegacyConstRandAccesIter &other) noexcept {
    return object == other.object;
}

template<typename T, typename Operation>
bool LCRAI<T, Operation>::operator!=(const LegacyConstRandAccesIter &other) noexcept {
    return object != other.object;
}

template<typename T, typename Operation>
typename LCRAI<T, Operation>::reference LCRAI<T, Operation>::operator*(
    void) noexcept {

    return *this;
}

template<typename T, typename Operation>
typename LCRAI<T, Operation>::pointer LCRAI<T, Operation>::operator->() noexcept {
    return object;
}

template<typename T, typename Operation>
LCRAI<T, Operation> &LCRAI<T, Operation>::operator+=(size_type amount) noexcept {
    object = operation(object, amount);
    return *this;
}

template<typename T, typename Operation>
LCRAI<T, Operation> LCRAI<T, Operation>::operator+(
    size_type amount) const noexcept {
    LCRAI<T, Operation> tmp;
    tmp += amount;
    return tmp;
}

template<typename T, typename Operation>
LCRAI<T, Operation> &LCRAI<T, Operation>::operator-=(size_type amount) noexcept {
    object = operation(object, -1 * amount);
    return *this;
}

template<typename T, typename Operation>
LCRAI<T, Operation> LCRAI<T, Operation>::operator-(
    size_type amount) const noexcept {
    LCRAI<T, Operation> tmp;
    tmp -= amount;
    return tmp;
}

template<typename T, typename Operation>
typename LCRAI<T, Operation>::difference_type LCRAI<T, Operation>::operator-(
    const LegacyConstRandAccesIter &rhs) const noexcept {
    return object - rhs.object;
}

template<typename T, typename Operation>
bool LCRAI<T, Operation>::operator<(
    const LegacyConstRandAccesIter &rhs) const noexcept {
    return object < rhs.object;
}

template<typename T, typename Operation>
bool LCRAI<T, Operation>::operator>(
    const LegacyConstRandAccesIter &rhs) const noexcept {
    return object > rhs.object;
}

template<typename T, typename Operation>
bool LCRAI<T, Operation>::operator<=(
    const LegacyConstRandAccesIter &rhs) const noexcept {
    return object <= rhs.object;
}

template<typename T, typename Operation>
bool LCRAI<T, Operation>::operator>=(
    const LegacyConstRandAccesIter &rhs) const noexcept {
    return object >= rhs.object;
}

template<typename T, typename Operation>
typename LCRAI<T, Operation>::reference LCRAI<T, Operation>::operator[](
    size_type index) noexcept {
    return object[index];
}

}  // namespace tmp 

}; // namespace imp
}; // namespace psg

#endif
