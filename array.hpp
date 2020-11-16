#ifndef PSG_ARRAY_HPP
#define PSG_ARRAY_HPP

#include <cstddef>

#include "utility.hpp"
#include "algorithm.hpp"
#include "exception.hpp"
#include "iterator_templates/legacy_random_acces_iterator.hpp"

namespace psg {

template<typename T, const size_t arr_size>
class array { // NOLINT No necesita los que son por movimiento
   public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using iterator = iterators::LegacyRandomAccesIterator<T>;
    using reverse_iterator =
        iterators::LegacyRandomAccesIterator<T, psg::minus<T>>;
    using const_iterator = iterators::constant::LegacyRandomAccesIterator<T>;
    using const_reverse_iterator =
        iterators::constant::LegacyRandomAccesIterator<T, psg::minus<T>>;

    array(void) = default;
    array(const array<T, arr_size> &rhs);
    array &operator=(const array<T, arr_size> &rhs);

    reference at(size_type position);
    const_reference at(size_type position) const;
    reference operator[](size_type position);
    const_reference operator[](size_type position) const;
    reference front(void);
    const_reference front(void) const;
    reference back(void);
    const_reference back(void) const;

    iterator begin(void) noexcept;
    iterator end(void) noexcept;
    const_iterator begin(void) const noexcept;
    const_iterator end(void) const noexcept;
    const_iterator cbegin(void) const noexcept;
    const_iterator cend(void) const noexcept;
    reverse_iterator rbegin(void) noexcept;
    reverse_iterator rend(void) noexcept;
    const_reverse_iterator crbegin(void) const noexcept;
    const_reverse_iterator crend(void) const noexcept;

    [[nodiscard]] constexpr bool empty(void) const noexcept;
    constexpr size_t size(void) const noexcept;
    constexpr size_t max_size(void) const noexcept;

    void fill(const T &value);
    void swap(array<T, arr_size> &other) noexcept;

    pointer data() noexcept;
    const_pointer data() const noexcept;

   private:
    T object[arr_size]; // NOLINT Tiene que ser un array estilo C
};

template<typename T, const size_t arr_size>
void swap(array<T, arr_size>& a, array<T, arr_size>& b) noexcept {
    a.swap(b);
}

/// Constructor por copia.
template<typename T, const size_t arr_size>
array<T, arr_size>::array(const array<T, arr_size> &rhs) {
    copy_n(rhs.cbegin(), arr_size, this->begin());
}

/// Asignacion por copia
template<typename T, const size_t arr_size>
array<T, arr_size> &array<T, arr_size>::operator=( // NOLINT Si lo maneja
    const array<T, arr_size> &rhs) {

    if (this == &rhs) {
        return *this;
    }
    copy_n(rhs.cbegin(), arr_size, this->begin());
    return *this;
}

/// Regresa el elemento en la posicion solicitada con checkeo.
///
/// Este regresa una referencia a el elemento revisando que este dentro del
/// array, si el elemento esta fuera de rango, esta lanza un psg::exception.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::at(
    typename array<T, arr_size>::size_type position) {

    if (position >= 0 && position < arr_size) {
        return object[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                    "elemento fuera de rango. ");
}

/// Regresa el elemento en la posicion solicitada con checkeo.
///
/// Este regresa una referencia constante a el elemento revisando que este
/// dentro del array, si el elemento esta fuera de rango, esta lanza un
/// psg::exception.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::at(
    typename array<T, arr_size>::size_type position) const {

    if (position >= 0 && position < arr_size) {
        return object[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                    "elemento fuera de rango. ");
}

/// Regresa una referencia a el elemento en la posicion solicitada sin
/// checkeo.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::operator[](
    typename array<T, arr_size>::size_type position) {

    return object[position];
}

/// Regresa una referencia constante a el elemento en la posicion solicitada
/// sin checkeo.
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::operator[](
    typename array<T, arr_size>::size_type position) const {

    return object[position];
}

/// Regresa una referencia al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::front(void) {
    return object[0];
}

/// Regresa una referencia constante al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::front(
    void) const {
    return object[0];
}

/// Regresa una referencia al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::reference array<T, arr_size>::back(void) {
    return object[arr_size - 1];
}

/// Regresa una referencia constante al el primer elemento del array
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_reference array<T, arr_size>::back(
    void) const {

    return object[arr_size - 1];
}

namespace imp {

template<typename T, const size_t arr_size>
using ArrayIter = typename array<T, arr_size>::iterator;

template<typename T, const size_t arr_size>
using ArrayConstIter = typename array<T, arr_size>::const_iterator;

template<typename T, const size_t arr_size>
using ArrayRevIter = typename array<T, arr_size>::reverse_iterator;

template<typename T, const size_t arr_size>
using ArrayConstRevIter = typename array<T, arr_size>::const_reverse_iterator;

} // namespace imp

/// Regresa un iterador al principio del array
template<typename T, const size_t arr_size>
imp::ArrayIter<T, arr_size> array<T, arr_size>::begin(void) noexcept {
    return imp::ArrayIter<T, arr_size>(object, 0);
}

/// Regresa un iterador pasado el final del array. NO SE DEBE SER DEREFERENCIADO
template<typename T, const size_t arr_size>
imp::ArrayIter<T, arr_size> array<T, arr_size>::end(void) noexcept {
    return imp::ArrayIter<T, arr_size>(object, arr_size);
}

/// Regresa un iterador constante al principio del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::begin(
    void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, 0);
}

/// Regresa un iterador cosntante pasado el final del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::end(void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, arr_size);
}

/// Regresa un iterador al principio del array. Los valores dereferenciados no
/// pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::cbegin(
    void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, 0);
}

/// Regresa un iterador pasado el final del array. Los valores dereferenciados
/// no pueden ser modificados.
template<typename T, const size_t arr_size>
imp::ArrayConstIter<T, arr_size> array<T, arr_size>::cend(void) const noexcept {
    return imp::ArrayConstIter<T, arr_size>(object, arr_size);
}

/// Regresa un iterador al final del array. Este lo recorrera de el final hacia
/// el inicio.
template<typename T, const size_t arr_size>
imp::ArrayRevIter<T, arr_size> array<T, arr_size>::rbegin(void) noexcept {
    T *last_element = object + arr_size - 1;
    return imp::ArrayRevIter<T, arr_size>(last_element, 0);
}

/// Regresa un iterador pasado el principio del array. NO DEBE SER
/// DEREFERENCIADO
template<typename T, const size_t arr_size>
imp::ArrayRevIter<T, arr_size> array<T, arr_size>::rend(void) noexcept {
    T *last_element = object + arr_size - 1;
    return imp::ArrayRevIter<T, arr_size>(last_element, arr_size);
}

/// Regresa un constante iterador al final del array. Este lo recorrera de el
/// final hacia el inicio.
template<typename T, const size_t arr_size>
imp::ArrayConstRevIter<T, arr_size> array<T, arr_size>::crbegin(
    void) const noexcept {
    const T *last_element = object + arr_size - 1;
    return imp::ArrayConstRevIter<T, arr_size>(last_element, 0);
}

/// Regresa un constante iterador pasado el principio del array. NO DEBE SER
/// DEREFERENCIADO
template<typename T, const size_t arr_size>
imp::ArrayConstRevIter<T, arr_size> array<T, arr_size>::crend(
    void) const noexcept {
    const T *last_element = object + arr_size - 1;
    return imp::ArrayConstRevIter<T, arr_size>(last_element, arr_size);
}

/// Indica si el array esta vacio
/// 
/// Este sera unicamente verdadero cuando el array tiene un tamaño de 0. No me
/// preguntes porque existe, no lo se.
template<typename T, const size_t arr_size>
[[nodiscard]] constexpr bool array<T, arr_size>::empty(void) const noexcept {
    return arr_size == 0;
}

/// Regresa el tamaño del array
template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::size(void) const noexcept {
    return arr_size;
}

/// Regresa el tamaño del array
template<typename T, const size_t arr_size>
constexpr size_t array<T, arr_size>::max_size(void) const noexcept {
    return arr_size;
}

/// Llena el array con el valor dado
template<typename T, const size_t arr_size>
void array<T, arr_size>::fill(const T &value) {
    auto assing_value = [&](T &element) -> void {
        element = value;
    };
    for_each(this->begin(), this->end(), assing_value);
}

/// Intercambia dos arrays
/// 
/// Este tambien se usa para especializar el psg::swap
template<typename T, const size_t arr_size>
void array<T, arr_size>::swap(array<T, arr_size> &other) noexcept {
    array<T, arr_size> tmp = *this;
    *this = other;
    other = tmp;
}

/// Regresa un puntero a los datos que este mantiene
template<typename T, const size_t arr_size>
typename array<T, arr_size>::pointer array<T, arr_size>::data() noexcept {
    return object;
}

/// Regresa un puntero constante a los datos que este sostiene
template<typename T, const size_t arr_size>
typename array<T, arr_size>::const_pointer
    array<T, arr_size>::data() const noexcept {

    return object;
}

}; // namespace psg

#endif
