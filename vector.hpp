#ifndef PSG_VECTOR_HPP
#define PSG_VECTOR_HPP

#include <cstddef>

#include "iterator_templates/legacy_random_acces_iterator.hpp"
#include "memory.hpp"

namespace psg {

/// Array asignado dinamicamente, y que puede estar cambiando de tamaño
/// constantemente.
///
/// Este se encargara de asignar la memoria utilizando un psg::allocator. Si
/// quiere utilizar su propio allocator, puede ver las especificaciones de
/// implementacion de el psg::allocator. Si quiere utilizar cualquier otra clase
/// como allocator, tendra que especializar la clase psg::allocator_traits para
/// usarlo.
///
/// Este va a asignar 0 elementos al ser creados si no se le da un tamaño. Luego
/// de ingresar un elemento, va a duplicar su tamaño cada vez que se quede sin
/// espacio.
///
/// Los elementos que almacenes en el vector tiene que:
///
/// * Poder construirse por copia
template<class T, class Allocator = psg::allocator<T>>
class vector {
   public:
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using iterator = iterators::LegacyRandomAccesIterator<T>;
    using const_iterator = iterators::constant::LegacyRandomAccesIterator<T>;
    using reverse_iterator =
        iterators::LegacyRandomAccesIterator<T, psg::minus<T>>;
    using const_reverse_iterator =
        iterators::constant::LegacyRandomAccesIterator<T, psg::minus<T>>;

    /// Llama al vector(const Allocator & alloc)
    vector() noexcept : vector(Allocator()) {}
    explicit vector(const Allocator & alloc) noexcept;
    explicit vector(size_type n, const Allocator & alloc = Allocator());
    vector(size_type n,
        const T &value,
        const Allocator &  allocator = Allocator());

    template<class InputIt>
    vector(InputIt first,
        InputIt last,
        const Allocator & allocator = Allocator());

    constexpr vector(const vector &x);
    constexpr vector(vector &&) noexcept;
    constexpr vector(const vector &, const Allocator &);
    constexpr vector(vector &&, const Allocator &);
    ~vector();

    constexpr vector &operator=(const vector &x);
    constexpr vector &operator=(vector &&x) noexcept;
    template<class InputIt>
    constexpr void assign(InputIt first, InputIt last);
    constexpr void assign(size_type n, const T &u);
    constexpr allocator_type get_allocator() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    constexpr reverse_iterator rbegin() noexcept;
    constexpr const_reverse_iterator rbegin() const noexcept;
    constexpr reverse_iterator rend() noexcept;
    constexpr const_reverse_iterator rend() const noexcept;

    constexpr const_iterator cbegin() const noexcept;
    constexpr const_iterator cend() const noexcept;
    constexpr const_reverse_iterator crbegin() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;

    [[nodiscard]] constexpr bool empty() const noexcept;
    constexpr size_type size() const noexcept;
    constexpr size_type max_size() const noexcept;
    constexpr size_type capacity() const noexcept;
    constexpr void resize(size_type sz);
    constexpr void resize(size_type sz, const T &c);
    constexpr void reserve(size_type n);
    constexpr void shrink_to_fit();

    constexpr reference operator[](size_type n);
    constexpr const_reference operator[](size_type n) const;
    constexpr const_reference at(size_type n) const;
    constexpr reference at(size_type n);
    constexpr reference front();
    constexpr const_reference front() const;
    constexpr reference back();
    constexpr const_reference back() const;

    constexpr pointer data() noexcept;
    constexpr const_pointer data() const noexcept;

    // modifiers
    template<class... Args>
    constexpr reference emplace_back(Args &&... args);
    constexpr void push_back(const T &x);
    constexpr void push_back(T &&x);
    constexpr void pop_back();

    template<class... Args>
    constexpr iterator emplace(const_iterator position, Args &&... args);
    constexpr iterator insert(const_iterator position, const T &x);
    constexpr iterator insert(const_iterator position, T &&x);
    constexpr iterator insert(const_iterator position, size_type n, const T &x);
    template<class InputIt>
    constexpr iterator
        insert(const_iterator position, InputIt first, InputIt last);
    constexpr iterator erase(const_iterator position);
    constexpr iterator erase(const_iterator first, const_iterator last);
    constexpr void swap(vector &) noexcept;
    constexpr void clear() noexcept;

   private:

    static constexpr size_type allocated_space_on_creation = 0;
    // El valor por el que sera multiplicado el espacio que tengas asignado cada
    // vez que que llenes el contenedor.
    static constexpr size_type allocated_space_multiplier = 2;

    pointer object = nullptr;
    size_type allocated_space = 0;
    size_type last_valid_element = 0;
    allocator_type alloc{};
};

namespace imp {
template<typename T>
using VecIter = iterators::LegacyRandomAccesIterator<T>;

template<typename T>
using VecRevIter = iterators::LegacyRandomAccesIterator<T, psg::minus<T>>;

template<typename T>
using VecConstIter = iterators::constant::LegacyRandomAccesIterator<T>;

template<typename T>
using VecConstRevIter =
    iterators::constant::LegacyRandomAccesIterator<T, psg::minus<T>>;

} // namespace imp

/// Iterador al principio del contenedor.
template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() noexcept {
    return imp::VecIter<T>(object, 0);
}

/// Iterador constante al principio del contenedor.
template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::begin() const noexcept {

    return imp::VecConstIter<T>(object, 0);
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() noexcept {
    return imp::VecIter<T>(object, last_valid_element);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::end() const noexcept {

    return imp::VecConstIter<T>(object, last_valid_element);
}

/// Simplemente asigna el allocator.
template<class T, class Allocator>
vector<T, Allocator>::vector(const Allocator &alloc) noexcept : alloc(alloc) {}

// TODO (Pablo): Necesito los iteradores!!!!!!!!!!!!!!
/// Asigna n espacios en memoria y los llena con el valor default.
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type n, const Allocator &allocator)
    : alloc(allocator) {

    allocated_space = n;
    last_valid_element = n;
    object = allocator_traits<Allocator>::allocate(alloc, n);
}

/// Asina n espacios en memoria y copia el valor
template<class T, class Allocator>
vector<T, Allocator>::vector(size_type n,
    const T &value,
    const Allocator & allocator) 
: alloc{allocator} {

    allocated_space = n;
    object = allocator_traits<Allocator>::allocate(alloc, n);
    // TODO (Pablo): Hagamoslo con los iteradores mejor
    // for (size_type i=0; i<n; i++) {
    //     allocator_traits<Allocator>::construct(alloc, object + i, value);
    // }
    last_valid_element = n;
}

// TODO (Pablo): Necesito el psg::distance antes de continuar.
template<class T, class Allocator>
template<class InputIt>
vector<T, Allocator>::vector(InputIt first,
    InputIt last,
    const Allocator &allocator) {

    // Idea
    // size = distance(first, last)
    // allocated_space = size
    // object = allocate(size)
    // construimos todos
    // last_valid_element = size
}

}; // namespace psg

#endif
