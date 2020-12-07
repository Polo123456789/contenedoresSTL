#ifndef PSG_COMMON_RANDOM_ACCESS_ITERATOR_FUNCTIONS_HPP
#define PSG_COMMON_RANDOM_ACCESS_ITERATOR_FUNCTIONS_HPP

namespace psg::imp {

/// Dado un contenedor, que mantiene sus objetos en memoria contigua, esta clase
/// da las funciones miembro para obtener el accesso random de los elementos.
///
/// Da las funciones:
///
/// * iterator begin(void) noexcept;
/// * iterator end(void) noexcept;
/// * const_iterator begin(void) const noexcept;
/// * const_iterator end(void) const noexcept;
/// * const_iterator cbegin(void) const noexcept;
/// * const_iterator cend(void) const noexcept;
/// * reverse_iterator rbegin(void) noexcept;
/// * reverse_iterator rend(void) noexcept;
/// * const_reverse_iterator crbegin(void) const noexcept;
/// * const_reverse_iterator crend(void) const noexcept;
///
/// Requiere que la clase que lo herede, tenga las siguientes funciones miebro:
///
/// * [[nodiscard]] size_type size(void) const noexcept;
/// * pointer data() noexcept;
/// * const_pointer data() const noexcept;
template<typename Container, typename ValueType, typename SizeType>
struct random_access_iterator_functions {
    // TODO(pablo): Simplificar los LRAI
    using value_type = ValueType;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using size_type = SizeType;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = psg::reverse_iterator<iterator>;
    using const_reverse_iterator = psg::reverse_iterator<const_iterator>;

    iterator               begin(void) noexcept;
    iterator               end(void) noexcept;
    const_iterator         begin(void) const noexcept;
    const_iterator         end(void) const noexcept;
    const_iterator         cbegin(void) const noexcept;
    const_iterator         cend(void) const noexcept;
    reverse_iterator       rbegin(void) noexcept;
    reverse_iterator       rend(void) noexcept;
    const_reverse_iterator rbegin(void) const noexcept;
    const_reverse_iterator rend(void) const noexcept;
    const_reverse_iterator crbegin(void) const noexcept;
    const_reverse_iterator crend(void) const noexcept;

   private:
    inline Container &underlying(void) {
        return static_cast<Container &>(*this);
    }
    inline const Container &underlying(void) const {
        return static_cast<const Container &>(*this);
    }
    inline size_type underlying_size() const {
        return this->underlying().size();
    }
    inline pointer underlying_data() {
        return this->underlying().data();
    }
    inline const_pointer underlying_const_data() const {
        return this->underlying().data();
    }
    random_access_iterator_functions() = default;
    friend Container;
};

};  // namespace psg::imp

namespace psg::imp::unused {

/// Dado un contenedor, que mantiene sus objetos en memoria contigua, esta clase
/// da las funciones miembro para obtener el accesso random de los elementos.
///
/// Da las funciones:
///
/// * iterator begin(void) noexcept;
/// * iterator end(void) noexcept;
/// * const_iterator begin(void) const noexcept;
/// * const_iterator end(void) const noexcept;
/// * const_iterator cbegin(void) const noexcept;
/// * const_iterator cend(void) const noexcept;
/// * reverse_iterator rbegin(void) noexcept;
/// * reverse_iterator rend(void) noexcept;
/// * const_reverse_iterator crbegin(void) const noexcept;
/// * const_reverse_iterator crend(void) const noexcept;
///
/// Requiere que la clase que lo herede, tenga las siguientes funciones miebro:
///
/// * [[nodiscard]] size_type size(void) const noexcept;
/// * pointer data() noexcept;
/// * const_pointer data() const noexcept;
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>

struct random_access_iterator_functions {
    using value_type = ValueType;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using size_type = SizeType;
    using iterator = Iterator;
    using const_iterator = ConstIterator;
    using reverse_iterator = ReverseIterator;
    using const_reverse_iterator = ConstReverseIterator;

    iterator               begin(void) noexcept;
    iterator               end(void) noexcept;
    const_iterator         begin(void) const noexcept;
    const_iterator         end(void) const noexcept;
    const_iterator         cbegin(void) const noexcept;
    const_iterator         cend(void) const noexcept;
    reverse_iterator       rbegin(void) noexcept;
    reverse_iterator       rend(void) noexcept;
    const_reverse_iterator rbegin(void) const noexcept;
    const_reverse_iterator rend(void) const noexcept;
    const_reverse_iterator crbegin(void) const noexcept;
    const_reverse_iterator crend(void) const noexcept;

   private:
    inline Container &underlying(void) {
        return static_cast<Container &>(*this);
    }
    inline const Container &underlying(void) const {
        return static_cast<const Container &>(*this);
    }
    inline size_type underlying_size() const {
        return this->underlying().size();
    }
    inline pointer underlying_data() {
        return this->underlying().data();
    }
    inline const_pointer underlying_const_data() const {
        return this->underlying().data();
    }
    random_access_iterator_functions() = default;
    friend Container;
};

/// Regresa un iterador al principio del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
Iterator random_access_iterator_functions<
    Container,
    ValueType,
    SizeType,
    Iterator,
    ConstIterator,
    ReverseIterator,
    ConstReverseIterator>::begin(void) noexcept {

    return Iterator(this->underlying_data(), 0);
}

/// Regresa un iterador pasado el final del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
Iterator
    random_access_iterator_functions<Container,
                                     ValueType,
                                     SizeType,
                                     Iterator,
                                     ConstIterator,
                                     ReverseIterator,
                                     ConstReverseIterator>::end(void) noexcept {

    return Iterator(this->underlying_data(), this->underlying_size());
}

/// Regresa un iterador constante al principio del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstIterator
    random_access_iterator_functions<Container,
                                     ValueType,
                                     SizeType,
                                     Iterator,
                                     ConstIterator,
                                     ReverseIterator,
                                     ConstReverseIterator>::begin(void)
        const noexcept {

    return ConstIterator(this->underlying_const_data(), 0);
}

/// Regresa un iterador cosntante pasado el final del array. Los valores
/// dereferenciados no pueden ser modificados.
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstIterator random_access_iterator_functions<Container,
                                               ValueType,
                                               SizeType,
                                               Iterator,
                                               ConstIterator,
                                               ReverseIterator,
                                               ConstReverseIterator>::end(void)
    const noexcept {

    return ConstIterator(this->underlying_const_data(),
                         this->underlying_size());
}

/// Regresa un iterador al principio del array. Los valores dereferenciados no
/// pueden ser modificados.
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstIterator
    random_access_iterator_functions<Container,
                                     ValueType,
                                     SizeType,
                                     Iterator,
                                     ConstIterator,
                                     ReverseIterator,
                                     ConstReverseIterator>::cbegin(void)
        const noexcept {

    return ConstIterator(this->underlying_const_data(), 0);
}

/// Regresa un iterador pasado el final del contendedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstIterator random_access_iterator_functions<Container,
                                               ValueType,
                                               SizeType,
                                               Iterator,
                                               ConstIterator,
                                               ReverseIterator,
                                               ConstReverseIterator>::cend(void)
    const noexcept {

    return ConstIterator(this->underlying_data(), this->underlying_size());
}

/// Regresa un iterador al final del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ReverseIterator random_access_iterator_functions<
    Container,
    ValueType,
    SizeType,
    Iterator,
    ConstIterator,
    ReverseIterator,
    ConstReverseIterator>::rbegin(void) noexcept {

    pointer last_element =
        this->underlying_data() + this->underlying_size() - 1;
    return ReverseIterator(last_element, 0);
}

/// Regresa un iterador pasado el principio del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ReverseIterator random_access_iterator_functions<
    Container,
    ValueType,
    SizeType,
    Iterator,
    ConstIterator,
    ReverseIterator,
    ConstReverseIterator>::rend(void) noexcept {

    pointer last_element =
        this->underlying_data() + this->underlying_size() - 1;
    return ReverseIterator(last_element, this->underlying_size());
}

/// Regresa un constante iterador al final del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstReverseIterator
    random_access_iterator_functions<Container,
                                     ValueType,
                                     SizeType,
                                     Iterator,
                                     ConstIterator,
                                     ReverseIterator,
                                     ConstReverseIterator>::crbegin(void)
        const noexcept {

    const_pointer last_element =
        this->underlying_const_data() + this->underlying_size() - 1;
    return ConstReverseIterator(last_element, 0);
}

/// Regresa un constante iterador pasado el principio del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstReverseIterator
    random_access_iterator_functions<Container,
                                     ValueType,
                                     SizeType,
                                     Iterator,
                                     ConstIterator,
                                     ReverseIterator,
                                     ConstReverseIterator>::crend(void)
        const noexcept {

    const_pointer last_element =
        this->underlying_data() + this->underlying_size() - 1;
    return ConstReverseIterator(last_element, this->underlying_size());
}

/// Regresa un constante iterador al final del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstReverseIterator
    random_access_iterator_functions<Container,
                                     ValueType,
                                     SizeType,
                                     Iterator,
                                     ConstIterator,
                                     ReverseIterator,
                                     ConstReverseIterator>::rbegin(void)
        const noexcept {

    const_pointer last_element =
        this->underlying_const_data() + this->underlying_size() - 1;
    return ConstReverseIterator(last_element, 0);
}

/// Regresa un constante iterador pasado el principio del contenedor
template<typename Container,
         typename ValueType,
         typename SizeType,
         typename Iterator,
         typename ConstIterator,
         typename ReverseIterator,
         typename ConstReverseIterator>
ConstReverseIterator
    random_access_iterator_functions<Container,
                                     ValueType,
                                     SizeType,
                                     Iterator,
                                     ConstIterator,
                                     ReverseIterator,
                                     ConstReverseIterator>::rend(void)
        const noexcept {

    const_pointer last_element =
        this->underlying_data() + this->underlying_size() - 1;
    return ConstReverseIterator(last_element, this->underlying_size());
}

}; // namespace psg::imp::unused

#endif
