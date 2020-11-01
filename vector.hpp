#ifndef PSG_VECTOR_HPP
#define PSG_VECTOR_HPP

#include <cstddef>

#include "iterator_templates/legacy_random_acces_iterator.hpp"
#include "memory.hpp"

namespace psg {

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

    constexpr vector() noexcept : vector(Allocator()) {}
    constexpr explicit vector(const Allocator &) noexcept;
    constexpr explicit vector(size_type n, const Allocator & = Allocator());
    constexpr vector(size_type n,
        const T &value,
        const Allocator & = Allocator());

    template<class InputIt>
    constexpr vector(InputIt first,
        InputIt last,
        const Allocator & = Allocator());

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

    constexpr iterator begin() noexcept;
    constexpr const_iterator begin() const noexcept;
    constexpr iterator end() noexcept;
    constexpr const_iterator end() const noexcept;
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
    pointer object = nullptr;
    size_type allocated_space = 0;
    size_type last_valid_element = 0;
    allocator_type alloc{};
};

}; // namespace psg

#endif
