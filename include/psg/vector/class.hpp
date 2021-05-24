#ifndef PSG_VECTOR_CLASS_HPP
#define PSG_VECTOR_CLASS_HPP

#include <psg/memory.hpp>
#include <psg/memory/allocated_unique_ptr.hpp>
#include <psg/common/random_access_functions.hpp>
#include <psg/common/random_access_iterator_functions.hpp>

#include <pgsl/views.hpp>

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
/// * Poder copiarse
/// * Poder moverse
template<class T, class Allocator = psg::allocator<T>>
class vector
    : public imp::random_access_functions<vector<T, Allocator>, T, size_t>,
      public imp::
          random_access_iterator_functions<vector<T, Allocator>, T, size_t> {
   public:
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = psg::reverse_iterator<iterator>;
    using const_reverse_iterator = psg::reverse_iterator<const_iterator>;

    vector(void) noexcept : alloc(Allocator{}), object(nullptr, alloc){};
    explicit vector(const Allocator &alloc) noexcept;
    explicit vector(size_type n, const Allocator &alloc = Allocator());
    vector(size_type        n,
           const T &        value,
           const Allocator &allocator = Allocator());

    template<class InputIt>
    vector(InputIt          first,
           InputIt          last,
           const Allocator &allocator = Allocator());

    vector(const vector &other);
    vector(vector &&other) noexcept;
    vector(const vector &other, const Allocator &a);
    vector(vector &&other, const Allocator &a);
    ~vector() noexcept;

    vector &operator=(const vector &x);
    vector &operator=(vector &&x) noexcept;
    template<class InputIt>
    void           assign(InputIt first, InputIt last);
    void           assign(size_type n, const T &u);
    allocator_type get_allocator() const noexcept;

    // Estos estan dados por los random_access_iterator_functions
    //
    // iterator begin() noexcept;
    // const_iterator begin() const noexcept;
    // iterator end() noexcept;
    // const_iterator end() const noexcept;
    // reverse_iterator rbegin() noexcept;
    // const_reverse_iterator rbegin() const noexcept;
    // reverse_iterator rend() noexcept;
    // const_reverse_iterator rend() const noexcept;
    // const_iterator cbegin() const noexcept;
    // const_iterator cend() const noexcept;
    // const_reverse_iterator crbegin() const noexcept;
    // const_reverse_iterator crend() const noexcept;

    [[nodiscard]] bool      empty() const noexcept;
    [[nodiscard]] size_type size() const noexcept;
    [[nodiscard]] size_type max_size() const noexcept;
    [[nodiscard]] size_type capacity() const noexcept;
    void                    resize(size_type sz);
    void                    resize(size_type sz, const T &c);
    void                    reserve(size_type n);
    void                    shrink_to_fit();

    // Estos estan dados por los random_access_functions
    //
    // reference operator[](size_type n);
    // const_reference operator[](size_type n) const;
    // const_reference at(size_type n) const;
    // reference at(size_type n);
    // reference front();
    // const_reference front() const;
    // reference back();
    // const_reference back() const;

    pointer       data() noexcept;
    const_pointer data() const noexcept;

    // modifiers
    template<class... Args>
    constexpr reference emplace_back(Args &&...args);
    constexpr void      push_back(const T &x);
    constexpr void      push_back(T &&x);
    constexpr void      pop_back();

    template<class... Args>
    constexpr iterator emplace(const_iterator position, Args &&...args);
    constexpr iterator insert(const_iterator position, const T &x);
    constexpr iterator insert(const_iterator position, T &&x);
    constexpr iterator insert(const_iterator position, size_type n, const T &x);
    template<class InputIt>
    constexpr iterator
        insert(const_iterator position, InputIt first, InputIt last);
    constexpr iterator erase(const_iterator position);
    constexpr iterator erase(const_iterator first, const_iterator last);
    void               swap(vector &) noexcept;
    void               clear(void) noexcept;

   private:
    using resource_handler = imp::allocated_unique_ptr<Allocator>;
    using traits = allocator_traits<Allocator>;

    allocator_type   alloc{};
    size_type        allocated_space = 0;
    resource_handler object; // No default value, needs an allocator
    size_type        last_valid_element = 0;
};

}; // namespace psg

#endif
