#ifndef PSG_ARRAY_ARRAY_CONST_REVERSE_ITERATOR_HPP
#define PSG_ARRAY_ARRAY_CONST_REVERSE_ITERATOR_HPP

#include "array_class.hpp"

//TODO (Pablo): Hacerle un buen debug le hace falta. A ver cuando me entran
//ganas

namespace psg {

template<typename T, const size_t arr_size>
class array<T, arr_size>::const_reverse_iterator {
   public:
    const_reverse_iterator() = default;
    explicit const_reverse_iterator(const T *last, int back_position);
    explicit const_reverse_iterator(const T *pos);
    const_reverse_iterator &operator--(void);
    const_reverse_iterator operator--(int);
    const_reverse_iterator &operator++(void);
    const_reverse_iterator operator++(int);
    bool operator==(const const_reverse_iterator &other);
    bool operator!=(const const_reverse_iterator &other);
    const T &operator*(void);
    const T *operator->();
    const_reverse_iterator &operator+=(int /*val*/);
    const_reverse_iterator operator+(int /*val*/) const;
    const_reverse_iterator &operator-=(int /*val*/);
    const_reverse_iterator operator-(int /*val*/) const;
    int operator-(const const_reverse_iterator &rhs) const;
    bool operator<(const const_reverse_iterator &rhs) const;
    bool operator>(const const_reverse_iterator &rhs) const;
    bool operator<=(const const_reverse_iterator &rhs) const;
    bool operator>=(const const_reverse_iterator &rhs) const;
    const T &operator[](int /*pos*/);

   private:
    const T *object = nullptr;
};

template<typename T, const size_t arr_size>
array<T, arr_size>::const_reverse_iterator::const_reverse_iterator(
    const T *last,
    int back_position) {
    object = last - back_position;
}

template<typename T, const size_t arr_size>
array<T, arr_size>::const_reverse_iterator::const_reverse_iterator(
    const T *pos) {
    object = pos;
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size> &
    array<T, arr_size>::const_reverse_iterator::operator--(void) {
    ++object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size>
    array<T, arr_size>::const_reverse_iterator::operator--(int) {
    ArrayConstRevIter<T, arr_size> tmp = *this;
    ++object;
    return tmp;
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size> &
    array<T, arr_size>::const_reverse_iterator::operator++(void) {
    --object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size>
    array<T, arr_size>::const_reverse_iterator::operator++(int) {
    ArrayConstRevIter<T, arr_size> tmp = *this;
    --object;
    return tmp;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_reverse_iterator::operator==(
    const const_reverse_iterator &other) {
    return object == other.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_reverse_iterator::operator!=(
    const const_reverse_iterator &other) {
    return object != other.object;
}

template<typename T, const size_t arr_size>
const T &array<T, arr_size>::const_reverse_iterator::operator*(void) {
    return *object;
}

template<typename T, const size_t arr_size>
const T *array<T, arr_size>::const_reverse_iterator::operator->() {
    return object;
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size> &
    array<T, arr_size>::const_reverse_iterator::operator+=(int val) {
    object -= val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size>
    array<T, arr_size>::const_reverse_iterator::operator+(int val) const {
    return ArrayConstRevIter<T, arr_size>(object - val);
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size> &
    array<T, arr_size>::const_reverse_iterator::operator-=(int val) {
    object += val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size>
    array<T, arr_size>::const_reverse_iterator::operator-(int val) const {
    return ArrayConstRevIter<T, arr_size>(object + val);
}

template<typename T, const size_t arr_size>
int array<T, arr_size>::const_reverse_iterator::operator-(
    const ArrayConstRevIter<T, arr_size> &rhs) const {
    return static_cast<int>(rhs.object - object);
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_reverse_iterator::operator<(
    const ArrayConstRevIter<T, arr_size> &rhs) const {
    return object > rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_reverse_iterator::operator>(
    const ArrayConstRevIter<T, arr_size> &rhs) const {
    return object < rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_reverse_iterator::operator<=(
    const ArrayConstRevIter<T, arr_size> &rhs) const {
    return object >= rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_reverse_iterator::operator>=(
    const ArrayConstRevIter<T, arr_size> &rhs) const {
    return object <= rhs.object;
}

template<typename T, const size_t arr_size>
const T &array<T, arr_size>::const_reverse_iterator::operator[](int pos) {
    return *(object - pos);
}

}; // namespace psg

#endif
