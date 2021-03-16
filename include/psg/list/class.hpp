#ifndef PSG_LIST_CLASS_HPP
#define PSG_LIST_CLASS_HPP

#include <cstddef>
#include <psg/memory.hpp>
#include <psg/iterator.hpp>

#include <psg/list/node.hpp>

namespace psg {

namespace imp {

template<typename T>
class list_iterator;

template<typename T>
class const_list_iterator;

} // namespace imp

/// Double linked list
template<class T, class Allocator = allocator<T>>
class list {
   public:
    // types
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = typename allocator_traits<Allocator>::pointer;
    using const_pointer = typename allocator_traits<Allocator>::const_pointer;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using iterator = imp::list_iterator<T>;
    using const_iterator = imp::const_list_iterator<T>;
    using reverse_iterator = psg::reverse_iterator<iterator>;
    using const_reverse_iterator = psg::reverse_iterator<const_iterator>;

    // construct/copy/destroy
    list() : list(Allocator()) {}
    explicit list(const Allocator &);
    explicit list(size_type n, const Allocator & = Allocator());
    list(size_type n, const T &value, const Allocator & = Allocator());
    template<class InputIt>
    list(InputIt first, InputIt last, const Allocator & = Allocator());
    list(const list &x);
    list(list &&x) noexcept;
    list(const list &, const Allocator &);
    list(list &&, const Allocator &);
    ~list();
    list &operator=(const list &x);
    list &operator=(list &&x) noexcept;
    template<class InputIt>
    void           assign(InputIt first, InputIt last);
    void           assign(size_type n, const T &t);
    allocator_type get_allocator() const noexcept;

    // iterators
    iterator               begin() noexcept;
    const_iterator         begin() const noexcept;
    iterator               end() noexcept;
    const_iterator         end() const noexcept;
    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend() const noexcept;

    const_iterator         cbegin() const noexcept;
    const_iterator         cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;

    // capacity
    [[nodiscard]] bool      empty() const noexcept;
    [[nodiscard]] size_type size() const noexcept;
    [[nodiscard]] size_type max_size() const noexcept;
    void                    resize(size_type sz);
    void                    resize(size_type sz, const T &c);

    // element access
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    // modifiers
    template<class... Args>
    reference emplace_front(Args &&...args);
    template<class... Args>
    reference emplace_back(Args &&...args);
    void      push_front(const T &x);
    void      push_front(T &&x);
    void      pop_front();
    void      push_back(const T &x);
    void      push_back(T &&x);
    void      pop_back();

    template<class... Args>
    iterator emplace(const_iterator position, Args &&...args);
    iterator insert(const_iterator position, const T &x);
    iterator insert(const_iterator position, T &&x);
    iterator insert(const_iterator position, size_type n, const T &x);
    template<class InputIt>
    iterator insert(const_iterator position, InputIt first, InputIt last);

    iterator erase(const_iterator position);
    iterator erase(const_iterator position, const_iterator last);
    void     swap(list &) noexcept;
    void     clear() noexcept;

    // list operations
    void splice(const_iterator position, list &x);
    void splice(const_iterator position, list &&x);
    void splice(const_iterator position, list &x, const_iterator i);
    void splice(const_iterator position, list &&x, const_iterator i);

    void splice(const_iterator position,
                list &         x,
                const_iterator first,
                const_iterator last);

    void splice(const_iterator position,
                list &&        x,
                const_iterator first,
                const_iterator last);

    size_type remove(const T &value);
    template<class Predicate>
    size_type remove_if(Predicate pred);

    size_type unique();
    template<class BinaryPredicate>
    size_type unique(BinaryPredicate binary_pred);

    void merge(list &x);
    void merge(list &&x);
    template<class Compare>
    void merge(list &x, Compare comp);
    template<class Compare>
    void merge(list &&x, Compare comp);

    void sort();
    template<class Compare>
    void sort(Compare comp);

    void reverse() noexcept;

   private:
    using node = imp::list_node<T, Allocator>;

    static constexpr auto node_insert_before =
        imp::list_node<T, Allocator>::insert_before;
    static constexpr auto node_insert_after =
        imp::list_node<T, Allocator>::insert_after;
};
} // namespace psg

#endif
