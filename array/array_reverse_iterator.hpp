#ifndef PSG_ARRAY_ARRAY_REVERSE_ITERATOR_HPP
#define PSG_ARRAY_ARRAY_REVERSE_ITERATOR_HPP

#include "array_class.hpp"

namespace psg {

template<typename T, const size_t arr_size>
class array<T, arr_size>::reverse_iterator {
   public:
    reverse_iterator() = default;
    explicit reverse_iterator(T * last, int back_position);
    explicit reverse_iterator(T* pos);
    reverse_iterator &operator--(void);
    reverse_iterator operator--(int);
    reverse_iterator &operator++(void);
    reverse_iterator operator++(int);
    bool operator==(const reverse_iterator &other);
    bool operator!=(const reverse_iterator &other);
    T &operator*(void);
    T *operator->();
    reverse_iterator &operator+=(int /*val*/);
    reverse_iterator operator+(int /*val*/) const;
    reverse_iterator &operator-=(int /*val*/);
    reverse_iterator operator-(int /*val*/) const;
    int operator-(const reverse_iterator &rhs) const;
    bool operator<(const reverse_iterator &rhs) const;
    bool operator>(const reverse_iterator &rhs) const;
    bool operator<=(const reverse_iterator &rhs) const;
    bool operator>=(const reverse_iterator &rhs) const;
    T &operator[](int /*pos*/);

   private:
    T *object = nullptr;
};

template<typename T, const size_t arr_size>
array<T, arr_size>::reverse_iterator::reverse_iterator(T *last,
    int back_position) {
    object = last - back_position;
}

template<typename T, const size_t arr_size>
array<T, arr_size>::reverse_iterator::reverse_iterator(T *pos) {
    object = pos;
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> &array<T, arr_size>::reverse_iterator::operator--(
    void) {
    ++object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> array<T, arr_size>::reverse_iterator::operator--(
    int) {
    ArrayRevIter<T, arr_size> tmp = *this;
    ++object;
    return tmp;
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> &array<T, arr_size>::reverse_iterator::operator++(
    void) {
    --object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> array<T, arr_size>::reverse_iterator::operator++(
    int) {
    ArrayRevIter<T, arr_size> tmp = *this;
    --object;
    return tmp;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::reverse_iterator::operator==(
    const reverse_iterator &other) {
    return object == other.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::reverse_iterator::operator!=(
    const reverse_iterator &other) {
    return object != other.object;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::reverse_iterator::operator*(void) {
    return *object;
}

template<typename T, const size_t arr_size>
T *array<T, arr_size>::reverse_iterator::operator->() {
    return object;
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> &array<T, arr_size>::reverse_iterator::operator+=(
    int val) {
    object -= val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> array<T, arr_size>::reverse_iterator::operator+(
    int val) const {
    return ArrayRevIter<T, arr_size>(object - val);
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> &array<T, arr_size>::reverse_iterator::operator-=(
    int val) {
    object += val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> array<T, arr_size>::reverse_iterator::operator-(
    int val) const {
    return ArrayRevIter<T, arr_size>(object + val);
}

template<typename T, const size_t arr_size>
int array<T, arr_size>::reverse_iterator::operator-(
    const ArrayRevIter<T, arr_size> &rhs) const {
    return static_cast<int>(rhs.object - object);
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::reverse_iterator::operator<(
    const ArrayRevIter<T, arr_size> &rhs) const {
    return object > rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::reverse_iterator::operator>(
    const ArrayRevIter<T, arr_size> &rhs) const {
    return object < rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::reverse_iterator::operator<=(
    const ArrayRevIter<T, arr_size> &rhs) const {
    return object >= rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::reverse_iterator::operator>=(
    const ArrayRevIter<T, arr_size> &rhs) const {
    return object <= rhs.object;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::reverse_iterator::operator[](int pos) {
    return *(object - pos);
}

}; // namespace psg

#endif
