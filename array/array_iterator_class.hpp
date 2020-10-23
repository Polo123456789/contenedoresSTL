#ifndef PSG_ARRAY_ARRAY_ITERATOR_CLASS_HPP
#define PSG_ARRAY_ARRAY_ITERATOR_CLASS_HPP

#include "array_class.hpp"

namespace psg {

template <typename T, const size_t arr_size>
class  array<T, arr_size>::iterator {
   public:
    iterator &operator--(void);
    iterator operator--(int);
    iterator& operator++(void);
    iterator operator++(int);
    bool operator==(const iterator &other);
    bool operator!=(const iterator &other);
    T& operator*(void);
    T *operator->();
    iterator &operator+=(int);
    iterator operator+(int) const;
    iterator &operator-=(int);
    iterator operator-(int) const;
    int operator-(const iterator& rhs) const;
    bool operator<(const iterator& rhs) const;
    bool operator>(const iterator& rhs) const;
    bool operator<=(const iterator& rhs) const;
    bool operator>=(const iterator& rhs) const;
    T& operator[](int);
};
}; // namespace psg

#endif
