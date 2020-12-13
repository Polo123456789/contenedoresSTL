#ifndef PSG_COMMON_RANDOM_ACCESS_ITERATOR_FUNCTIONS_HPP
#define PSG_COMMON_RANDOM_ACCESS_ITERATOR_FUNCTIONS_HPP

#include <psg/iterator/reverse_iterator.hpp>

namespace psg {

/// Especialisazion para poder usar los reverse_iterator con punteros
template<typename T>
struct iterator_traits<T *> {
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = random_acces_iterator_tag;
};

}; // namespace psg

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
    inline const_pointer underlying_data() const {
        return this->underlying().data();
    }
    random_access_iterator_functions() = default;
    friend Container;
};

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::begin(
    void) noexcept -> iterator {

    return this->underlying_data();
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::end(
    void) noexcept -> iterator {

    return this->underlying_data() + this->underlying_size();
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::begin(
    void) const noexcept -> const_iterator {

    return this->underlying_data();
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::end(
    void) const noexcept -> const_iterator {

    return this->underlying_data() + this->underlying_size();
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::cbegin(
    void) const noexcept -> const_iterator {

    return this->underlying_data();
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::cend(
    void) const noexcept -> const_iterator {

    return this->underlying_data() + this->underlying_size();
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::rbegin(
    void) noexcept -> reverse_iterator {

    return this->underlying_data() + this->underlying_size() - 1;
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::rend(
    void) noexcept -> reverse_iterator {

    return this->underlying_data() - 1;
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::rbegin(
    void) const noexcept -> const_reverse_iterator {

    return this->underlying_data() + this->underlying_size() - 1;
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::rend(
    void) const noexcept -> const_reverse_iterator {

    return this->underlying_data() - 1;
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::crbegin(
    void) const noexcept -> const_reverse_iterator {

    return this->underlying_data() + this->underlying_size() - 1;
}

template<typename Container, typename ValueType, typename SizeType>
auto random_access_iterator_functions<Container, ValueType, SizeType>::crend(
    void) const noexcept -> const_reverse_iterator {

    return this->underlying_data() - 1;
}

}; // namespace psg::imp

#endif
