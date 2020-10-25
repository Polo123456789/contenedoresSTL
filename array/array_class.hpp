#ifndef PSG_ARRAY_ARRAY_CLASS_HPP
#define PSG_ARRAY_ARRAY_CLASS_HPP

#include "../algorithm.hpp"
#include "../exception.hpp"

namespace psg {

template<typename T, const size_t arr_size>
class array { //NOLINT No necesita move constructor.
   public:
    // Funcionen miembro
    array(void) = default;
    array(const array<T, arr_size> &rhs);
    array &operator=(const array<T, arr_size> &rhs);
    ~array(void) = default;

    // Acceso a elementos
    T &at(int position);
    T &operator[](int position);
    T &front(void);
    T &back(void);

    class iterator;
    class const_iterator;
    class reverse_iterator;
    class const_reverse_iterator;
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    // Capacidad
    constexpr bool empty(void) const;
    constexpr size_t size(void) const;
    constexpr size_t max_size(void) const;

    // Operaciones
    void fill(const T &value);
    void swap(array<T, arr_size> &other) noexcept;

   private:
    T data[arr_size];//NOLINT Tiene que ser un array del estilo C
};

template<typename T, const size_t arr_size>
array<T, arr_size>::array(const array<T, arr_size> &rhs) {
    copy_n(rhs.cbegin(), arr_size, this->begin());
}

template<typename T, const size_t arr_size>
//NOLINTNEXTLINE Si maneja el self assigment
array<T, arr_size> &array<T, arr_size>::operator=( 
    const array<T, arr_size> &rhs) {

    if (this == &rhs) {
        return *this;
    }
    copy_n(rhs.cbegin(), arr_size, this->begin()); 
    return *this;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::at(int position) {
    if (position >= 0 && position < arr_size) {
        return data[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                   "elemento fuera de rango");
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::operator[](int position) {
    return data[position];
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::front(void) {
    return data[0];
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::back(void) {
    return data[arr_size-1];
}

template<typename T, const size_t arr_size>
using ArrayIter = typename array<T, arr_size>::iterator;

template<typename T, const size_t arr_size>
using ArrayConstIter = typename array<T, arr_size>::const_iterator;

template<typename T, const size_t arr_size>
using ArrayRevIter = typename array<T, arr_size>::reverse_iterator;

template<typename T, const size_t arr_size>
using ArrayConstRevIter = typename array<T, arr_size>::const_reverse_iterator;

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::begin() {
    return ArrayIter<T, arr_size>(data, 0);
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::end() {
    return ArrayIter<T, arr_size>(data, arr_size);
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::cbegin() const {
    return ArrayConstIter<T, arr_size>(data, 0);
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::cend() const {
    return ArrayConstIter<T, arr_size>(data, arr_size);
}

//
//TODO (pablo): Implementar las demas funciones de los iteradores.
//

template<typename T, const size_t arr_size>
constexpr bool array<T, arr_size>::empty(void) const {
    return arr_size == 0;
}

template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::size(void) const {
    return arr_size;
}

template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::max_size(void) const {
    return arr_size;
}

template<typename T, const size_t arr_size>
void array<T, arr_size>::fill(const T &value) {
    auto assing_value = [&](T &element) -> void {
        element = value;
    };
    for_each(this->begin(), this->end(), assing_value);
}

template<typename T, const size_t arr_size>
void array<T, arr_size>::swap(array<T, arr_size> &other) noexcept {
    array<T, arr_size> tmp = *this;
    *this = other;
    other = tmp;
}

} // namespace psg

#endif
