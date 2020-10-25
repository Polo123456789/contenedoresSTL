#ifndef PSG_ARRAY_ARRAY_ITERATOR_CLASS_HPP
#define PSG_ARRAY_ARRAY_ITERATOR_CLASS_HPP

#include "array_class.hpp"

namespace psg {

template<typename T, const size_t arr_size>
class array<T, arr_size>::iterator {
   public:
    iterator() = default;
    explicit iterator(T * /*first*/, int /*position*/);
    explicit iterator(T* /*pos*/);
    iterator &operator--(void);
    iterator operator--(int);
    iterator &operator++(void);
    iterator operator++(int);
    bool operator==(const iterator &other);
    bool operator!=(const iterator &other);
    T &operator*(void);
    T *operator->();
    iterator &operator+=(int /*val*/);
    iterator operator+(int /*val*/) const;
    iterator &operator-=(int /*val*/);
    iterator operator-(int /*val*/) const;
    int operator-(const iterator &rhs) const;
    bool operator<(const iterator &rhs) const;
    bool operator>(const iterator &rhs) const;
    bool operator<=(const iterator &rhs) const;
    bool operator>=(const iterator &rhs) const;
    T &operator[](int /*pos*/);

   private:
    T *object = nullptr;
};

template<typename T, const size_t arr_size>
array<T, arr_size>::iterator::iterator(T *first, int position) {
    object = first + position;
}

template<typename T, const size_t arr_size>
array<T, arr_size>::iterator::iterator(T *pos) {
    object = pos;
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> &array<T, arr_size>::iterator::operator--(void) {
    --object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::iterator::operator--(int) {
    ArrayIter<T, arr_size> tmp = *this;
    --object;
    return tmp;
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> &array<T, arr_size>::iterator::operator++(void) {
    ++object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::iterator::operator++(int) {
    ArrayIter<T, arr_size> tmp = *this;
    ++object;
    return tmp;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator==(const iterator &other) {
    return object == other.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator!=(const iterator &other) {
    return object != other.object;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::iterator::operator*(void) {
    return *object;
}

template<typename T, const size_t arr_size>
T *array<T, arr_size>::iterator::operator->() {
    return object;
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> &array<T, arr_size>::iterator::operator+=(int val) {
    object += val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::iterator::operator+(int val) const {
    return ArrayIter<T, arr_size>(object + val);
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> &array<T, arr_size>::iterator::operator-=(int val) {
    object -= val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::iterator::operator-(int val) const {
    return ArrayIter<T, arr_size>(object - val);
}

template<typename T, const size_t arr_size>
int array<T, arr_size>::iterator::operator-(const ArrayIter<T, arr_size> &rhs) const {
    return static_cast<int>(object - rhs.object);
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator<(const ArrayIter<T, arr_size> &rhs) const {
    return object < rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator>(const ArrayIter<T, arr_size> &rhs) const {
    return object > rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator<=(const ArrayIter<T, arr_size> &rhs) const {
    return object <= rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator>=(const ArrayIter<T, arr_size> &rhs) const {
    return object >= rhs.object;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::iterator::operator[](int pos) {
    return *(object + pos);
}

}; // namespace psg

#endif
