#ifndef PSG_ARRAY_HPP
#define PSG_ARRAY_HPP

#include "utility.hpp"
#include "algorithm.hpp"
#include "exception.hpp"

namespace psg {

template<typename T, const size_t arr_size>
class array { //NOLINT No necesita los que son por movimiento
   public:
    array(void) = default;
    array(const array<T, arr_size> &rhs);
    array &operator=(const array<T, arr_size> &rhs);

    T &at(int position);
    T &operator[](int position);
    T &front(void);
    T &back(void);

    class iterator;
    class const_iterator;
    class reverse_iterator;
    class const_reverse_iterator;
    iterator begin(void);
    iterator end(void);
    const_iterator cbegin(void) const;
    const_iterator cend(void) const;
    reverse_iterator rbegin(void);
    reverse_iterator rend(void);
    const_reverse_iterator crbegin(void) const;
    const_reverse_iterator crend(void) const;

    [[nodiscard]] constexpr bool empty(void) const;
    constexpr size_t size(void) const;
    constexpr size_t max_size(void) const;

    void fill(const T &value);
    void swap(array<T, arr_size> &other) noexcept;

   private:
    T data[arr_size]; // NOLINT Tiene que ser un array estilo C
};

template<typename T, const size_t arr_size>
array<T, arr_size>::array(const array<T, arr_size> &rhs) {
    copy_n(rhs.cbegin(), arr_size, this->begin());
}

template<typename T, const size_t arr_size>
array<T, arr_size> &array<T, arr_size>::operator=( //NOLINT Si lo maneja
    const array<T, arr_size> &rhs) {

    if (this == &rhs) {
        return *this;
    }
    copy_n(rhs.cbegin(), arr_size, this->begin());
    return *this;
}

/* Accede a un elemento del array. Verifica si la posición esta dentro del
 * array. Si no lo esta lanza un psg::exception
 *
 * Parametros:
 *  - Posición: Posicion a la que se quiere acceder
 */
template<typename T, const size_t arr_size>
T &array<T, arr_size>::at(int position) {
    if (position >= 0 && position < arr_size) {
        return data[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                    "elemento fuera de rango. ");
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::operator[](int position) {
    return data[position];
}

/*
 * Accede al primer elemento del array
 */
template<typename T, const size_t arr_size>
T &array<T, arr_size>::front(void) {
    return data[0];
}

/*
 * Accede al ultimo elemento del array
 */
template<typename T, const size_t arr_size>
T &array<T, arr_size>::back(void) {
    return data[arr_size - 1];
}

template<typename T, const size_t arr_size>
using ArrayIter = typename array<T, arr_size>::iterator;

template<typename T, const size_t arr_size>
using ArrayConstIter = typename array<T, arr_size>::const_iterator;

template<typename T, const size_t arr_size>
using ArrayRevIter = typename array<T, arr_size>::reverse_iterator;

template<typename T, const size_t arr_size>
using ArrayConstRevIter = typename array<T, arr_size>::const_reverse_iterator;

// Regresa un iterador al principio del array 
template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::begin(void) {
    return ArrayIter<T, arr_size>(data, 0);
}

// Regresa un iterador pasado el final del array. NO SE DEBE ACCEDER AL ITERADOR
template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::end(void) {
    return ArrayIter<T, arr_size>(data, arr_size);
}

/* Regresa un iterador al principio del array. Los valores dereferenciados no
 * pueden ser modificados.
 */
template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::cbegin(void) const {
    return ArrayConstIter<T, arr_size>(data, 0);
}

/* Regresa un iterador pasado el final del array. Los valores dereferenciados no
 * pueden ser modificados.
 */
template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::cend(void) const {
    return ArrayConstIter<T, arr_size>(data, arr_size);
}

/* Regresa un iterador al final del array. Este lo recorrera de el final hacia
 * el inicio.
 */
template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> array<T, arr_size>::rbegin(void) {
    T *last_element = data + arr_size - 1;
    return ArrayRevIter<T, arr_size>(last_element, 0);
}

/* Regresa un iterador pasado el principio del array. NO DEBE ACCEDER AL
 * ITERADOR
 */
template<typename T, const size_t arr_size>
ArrayRevIter<T, arr_size> array<T, arr_size>::rend(void) {
    T *last_element = data + arr_size - 1;
    return ArrayRevIter<T, arr_size>(last_element, arr_size);
}

/* Regresa un constante iterador al final del array. Este lo recorrera de el
 * final hacia el inicio.
 */
template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size> array<T, arr_size>::crbegin(void) const {
    const T *last_element = data + arr_size - 1;
    return ArrayConstRevIter<T, arr_size>(last_element, 0);
}

/* Regresa un constante iterador pasado el principio del array. NO DEBE ACCEDER
 * AL ITERADOR
 */
template<typename T, const size_t arr_size>
ArrayConstRevIter<T, arr_size> array<T, arr_size>::crend(void) const {
    const T *last_element = data + arr_size - 1;
    return ArrayConstRevIter<T, arr_size>(last_element, arr_size);
}

// Indica si el array esta vacio. Unicamente verdadero cuando el tamaño es 0
template<typename T, const size_t arr_size>
[[nodiscard]] constexpr bool array<T, arr_size>::empty(void) const {
    return arr_size == 0;
}

// Regresa el tamaño del array
template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::size(void) const {
    return arr_size;
}

// Regresa el tamaño del array
template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::max_size(void) const {
    return arr_size;
}

// Llena el array con el valor dado
template<typename T, const size_t arr_size>
void array<T, arr_size>::fill(const T &value) {
    auto assing_value = [&](T &element) -> void {
        element = value;
    };
    for_each(this->begin(), this->end(), assing_value);
}

// Intercambia dos arrays
template<typename T, const size_t arr_size>
void array<T, arr_size>::swap(array<T, arr_size> &other) noexcept {
    array<T, arr_size> tmp = *this;
    *this = other;
    other = tmp;
}

template<typename T, const size_t arr_size>
class array<T, arr_size>::iterator {
   public:
    iterator() = default;
    explicit iterator(T * first, int position);
    explicit iterator(T * pos);
    iterator &operator--(void);
    iterator operator--(int);
    iterator &operator++(void);
    iterator operator++(int);
    bool operator==(const iterator &other);
    bool operator!=(const iterator &other);
    T &operator*(void);
    T *operator->();
    iterator &operator+=(int val);
    iterator operator+(int val) const;
    iterator &operator-=(int val);
    iterator operator-(int val) const;
    int operator-(const iterator &rhs) const;
    bool operator<(const iterator &rhs) const;
    bool operator>(const iterator &rhs) const;
    bool operator<=(const iterator &rhs) const;
    bool operator>=(const iterator &rhs) const;
    T &operator[](int pos);

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
int array<T, arr_size>::iterator::operator-(
    const ArrayIter<T, arr_size> &rhs) const {
    return static_cast<int>(object - rhs.object);
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator<(
    const ArrayIter<T, arr_size> &rhs) const {
    return object < rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator>(
    const ArrayIter<T, arr_size> &rhs) const {
    return object > rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator<=(
    const ArrayIter<T, arr_size> &rhs) const {
    return object <= rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::iterator::operator>=(
    const ArrayIter<T, arr_size> &rhs) const {
    return object >= rhs.object;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::iterator::operator[](int pos) {
    return *(object + pos);
}

template<typename T, const size_t arr_size>
class array<T, arr_size>::const_iterator {
   public:
    const_iterator() = default;
    explicit const_iterator(const T * first, int position);
    explicit const_iterator(const T * pos);
    const_iterator &operator--(void);
    const_iterator operator--(int);
    const_iterator &operator++(void);
    const_iterator operator++(int);
    bool operator==(const const_iterator &other);
    bool operator!=(const const_iterator &other);
    const T &operator*(void);
    const T *operator->();
    const_iterator &operator+=(int val);
    const_iterator operator+(int val) const;
    const_iterator &operator-=(int val);
    const_iterator operator-(int val) const;
    int operator-(const const_iterator &rhs) const;
    bool operator<(const const_iterator &rhs) const;
    bool operator>(const const_iterator &rhs) const;
    bool operator<=(const const_iterator &rhs) const;
    bool operator>=(const const_iterator &rhs) const;
    T &operator[](int pos);

   private:
    const T *object = nullptr;
};

template<typename T, const size_t arr_size>
array<T, arr_size>::const_iterator::const_iterator(const T *first,
    int position) {
    object = first + position;
}

template<typename T, const size_t arr_size>
array<T, arr_size>::const_iterator::const_iterator(const T *pos) {
    object = pos;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator--(
    void) {
    --object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator--(
    int) {
    ArrayConstIter<T, arr_size> tmp = *this;
    --object;
    return tmp;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator++(
    void) {
    ++object;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator++(
    int) {
    ArrayConstIter<T, arr_size> tmp = *this;
    ++object;
    return tmp;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator==(
    const const_iterator &other) {
    return object == other.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator!=(
    const const_iterator &other) {
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
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator+=(
    int val) {
    object += val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator+(
    int val) const {
    return ArrayConstIter<T, arr_size>(object + val);
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> &array<T, arr_size>::const_iterator::operator-=(
    int val) {
    object -= val;
    return *this;
}

template<typename T, const size_t arr_size>
ArrayConstIter<T, arr_size> array<T, arr_size>::const_iterator::operator-(
    int val) const {
    return ArrayConstIter<T, arr_size>(object - val);
}

template<typename T, const size_t arr_size>
int array<T, arr_size>::const_iterator::operator-(
    const ArrayConstIter<T, arr_size> &rhs) const {
    return static_cast<int>(object - rhs.object);
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator<(
    const ArrayConstIter<T, arr_size> &rhs) const {
    return object < rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator>(
    const ArrayConstIter<T, arr_size> &rhs) const {
    return object > rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator<=(
    const ArrayConstIter<T, arr_size> &rhs) const {
    return object <= rhs.object;
}

template<typename T, const size_t arr_size>
bool array<T, arr_size>::const_iterator::operator>=(
    const ArrayConstIter<T, arr_size> &rhs) const {
    return object >= rhs.object;
}

template<typename T, const size_t arr_size>
T &array<T, arr_size>::const_iterator::operator[](int pos) {
    return *(object + pos);
}

template<typename T, const size_t arr_size>
class array<T, arr_size>::reverse_iterator {
   public:
    reverse_iterator() = default;
    explicit reverse_iterator(T *last, int back_position);
    explicit reverse_iterator(T *pos);
    reverse_iterator &operator--(void);
    reverse_iterator operator--(int);
    reverse_iterator &operator++(void);
    reverse_iterator operator++(int);
    bool operator==(const reverse_iterator &other);
    bool operator!=(const reverse_iterator &other);
    T &operator*(void);
    T *operator->();
    reverse_iterator &operator+=(int val);
    reverse_iterator operator+(int val) const;
    reverse_iterator &operator-=(int val);
    reverse_iterator operator-(int val) const;
    int operator-(const reverse_iterator &rhs) const;
    bool operator<(const reverse_iterator &rhs) const;
    bool operator>(const reverse_iterator &rhs) const;
    bool operator<=(const reverse_iterator &rhs) const;
    bool operator>=(const reverse_iterator &rhs) const;
    T &operator[](int pos);

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
    const_reverse_iterator &operator+=(int val);
    const_reverse_iterator operator+(int val) const;
    const_reverse_iterator &operator-=(int val);
    const_reverse_iterator operator-(int val) const;
    int operator-(const const_reverse_iterator &rhs) const;
    bool operator<(const const_reverse_iterator &rhs) const;
    bool operator>(const const_reverse_iterator &rhs) const;
    bool operator<=(const const_reverse_iterator &rhs) const;
    bool operator>=(const const_reverse_iterator &rhs) const;
    const T &operator[](int pos);

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
