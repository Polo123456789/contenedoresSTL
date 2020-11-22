#ifndef PSG_COMMON_RANDOM_ACCESS_FUNCTIONS_HPP
#define PSG_COMMON_RANDOM_ACCESS_FUNCTIONS_HPP

#include <psg/exception.hpp>

namespace psg::imp {

/// Dado un contenedor, que mantiene sus objetos en memoria contigua, esta clase
/// da las funciones miembro para obtener el accesso random de los elementos.
///
/// Da las funciones:
///
/// * reference at(size_type position);
/// * const_reference at(size_type position) const;
/// * reference operator[](size_type position);
/// * const_reference operator[](size_type position) const;
/// * reference front(void);
/// * const_reference front(void) const;
/// * reference back(void);
/// * const_reference back(void) const;
///
/// Requiere que la clase que lo herede, tenga las siguientes funciones miebro:
///
/// * [[nodiscard]] size_type size(void) const noexcept;
/// * pointer data() noexcept;
/// * const_pointer data() const noexcept;
template<typename Container, typename ValueType, typename SizeType>
struct random_access_functions {
    using value_type = ValueType;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using size_type = SizeType;

    reference at(size_type position);
    const_reference at(size_type position) const;
    reference operator[](size_type position);
    const_reference operator[](size_type position) const;
    reference front(void);
    const_reference front(void) const;
    reference back(void);
    const_reference back(void) const;

   private:
    inline Container &underlying(void) {
        return static_cast<Container &>(*this);
    }
    inline const Container &underlying(void) const  {
        return static_cast<const Container &>(*this);
    }
    inline size_type underlying_size() {
        return this->underlying().size();
    }
    inline pointer underlying_data() {
        return this->underlying().data();
    }
    inline const_pointer underlying_const_data() {
        return this->underlying().data();
    }
    random_access_functions() = default;
    friend Container;
};

/// Regresa el elemento en la posicion solicitada con checkeo.
///
/// Este regresa una referencia a el elemento revisando que este dentro del
/// array, si el elemento esta fuera de rango, esta lanza un psg::exception.
template<typename Container, typename ValueType, typename SizeType>
ValueType &random_access_functions<Container, ValueType, SizeType>::at(
    size_type position) {

    if (position < this->underlying_size()) {
        return this->underlying_data()[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                    "elemento fuera de rango. ");
}

/// Regresa el elemento en la posicion solicitada con checkeo.
///
/// Este regresa una referencia constante a el elemento revisando que este
/// dentro del array, si el elemento esta fuera de rango, esta lanza un
/// psg::exception.
template<typename Container, typename ValueType, typename SizeType>
const ValueType &random_access_functions<Container, ValueType, SizeType>::at(
    size_type position) const {

    if (position < this->underlying_size()) {
        this->underlying_const_data()[position];
    }
    throw exception("exception en el psg::array al llamar la funcion at(), "
                    "elemento fuera de rango. ");
}

/// Regresa una referencia a el elemento en la posicion solicitada sin
/// checkeo.
template<typename Container, typename ValueType, typename SizeType>
ValueType &random_access_functions<Container, ValueType, SizeType>::operator[](
    size_type position) {

    return this->underlying_data()[position];
}

/// Regresa una referencia constante a el elemento en la posicion solicitada
/// sin checkeo.
template<typename Container, typename ValueType, typename SizeType>
const ValueType &
    random_access_functions<Container, ValueType, SizeType>::operator[](
        size_type position) const {

    return this->underlying_const_data()[position];
}

/// Regresa una referencia al el primer elemento del array
template<typename Container, typename ValueType, typename SizeType>
ValueType &random_access_functions<Container, ValueType, SizeType>::front(
    void) {

    return this->underlying_data()[0];
}

/// Regresa una referencia constante al el primer elemento del array
template<typename Container, typename ValueType, typename SizeType>
const ValueType &random_access_functions<Container, ValueType, SizeType>::front(
    void) const {

    return this->underlying_const_data()[0];
}

/// Regresa una referencia al el primer elemento del array
template<typename Container, typename ValueType, typename SizeType>
ValueType &random_access_functions<Container, ValueType, SizeType>::back(void) {

    return this->underlying_data()[underlying_size() - 1];
}

/// Regresa una referencia constante al el primer elemento del array
template<typename Container, typename ValueType, typename SizeType>
const ValueType &random_access_functions<Container, ValueType, SizeType>::back(
    void) const {

    return this->underlying_const_data()[underlying_size() - 1];
}

} // namespace psg::imp

#endif
