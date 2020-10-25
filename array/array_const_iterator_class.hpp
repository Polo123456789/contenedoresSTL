#ifndef PSG_ARRAY_ARRAY_CONST_ITERATOR_CLASS_HPP
#define PSG_ARRAY_ARRAY_CONST_ITERATOR_CLASS_HPP

#include "array_class.hpp"

namespace psg {

template <typename T, const size_t arr_size>
class array<T, arr_size>::const_iterator {
   public:
    const_iterator() = default;
    explicit const_iterator(const T * /*first*/, int /*position*/);
    explicit const_iterator(const T* /*pos*/);
    const_iterator &operator--(void);
    const_iterator operator--(int);
    const_iterator &operator++(void);
    const_iterator operator++(int);
    bool operator==(const const_iterator &other);
    bool operator!=(const const_iterator &other);
    const T &operator*(void);
    const T *operator->();
    const_iterator &operator+=(int /*val*/);
    const_iterator operator+(int /*val*/) const;
    const_iterator &operator-=(int /*val*/);
    const_iterator operator-(int /*val*/) const;
    int operator-(const const_iterator &rhs) const;
    bool operator<(const const_iterator &rhs) const;
    bool operator>(const const_iterator &rhs) const;
    bool operator<=(const const_iterator &rhs) const;
    bool operator>=(const const_iterator &rhs) const;
    T &operator[](int);

   private:
    const T *object = nullptr;
};


template<typename T, const size_t arr_size>
array<T, arr_size>::const_iterator::const_iterator(const T *first, int position) {
    object = first + position;
}

template<typename T, const size_t arr_size>
array<T, arr_size>::const_iterator::const_iterator(const T *pos) {
    object = pos;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator--(void) {
    --object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator--(int) {
    ArrayConstIter<T, arr_size> tmp = *this;
    --object;
    return tmp;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator++(void) {
    ++object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator++(int) {
    ArrayConstIter<T, arr_size> tmp = *this;
    ++object;
    return tmp;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator==(const const_iterator &other) {
    return object == other.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator!=(const const_iterator &other) {
    return object != other.object;
}

template<typename T, const size_t arr_size>
const T &array<T, arr_size>::const_iterator::operator*(void) {
    return *object;
}

template<typename T, const size_t arr_size>
const T *array<T, arr_size>::const_iterator::operator->() {
    return object;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator+=(int val) {
    object += val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator+(int val) const {
    return ArrayConstIter<T, arr_size>(object + val);
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator-=(int val) {
    object -= val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator-(int val) const {
    return ArrayConstIter<T, arr_size>(object - val);
}

template<typename T, const size_t arr_size>
int array<T, arr_size>::const_iterator::operator-(const ArrayConstIter<T, arr_size> &rhs) const {
    return static_cast<int>(object - rhs.object);
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator<(const ArrayConstIter<T, arr_size> &rhs) const {
    return object < rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator>(const ArrayConstIter<T, arr_size> &rhs) const {
    return object > rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator<=(const ArrayConstIter<T, arr_size> &rhs) const {
    return object <= rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator>=(const ArrayConstIter<T, arr_size> &rhs) const {
    return object >= rhs.object;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::const_iterator::operator[](int pos) {
    return *(object + pos);
}

}; // namespace psg

#endif
