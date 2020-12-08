#ifndef PSG_ARRAY_CLASS
#define PSG_ARRAY_CLASS

#include <cstddef>

#include <psg/utility.hpp>
#include <psg/algorithm.hpp>
#include <psg/exception.hpp>
#include <psg/common/random_access_iterator_functions.hpp>
#include <psg/common/random_access_functions.hpp>

namespace psg {

template<typename T, const size_t arr_size>
// NOLINTNEXTLINE No necesita los que son por movimiento
class array
    : public imp::random_access_functions<array<T, arr_size>, T, size_t>,
      public imp::
          random_access_iterator_functions<array<T, arr_size>, T, size_t> {

   public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = psg::reverse_iterator<iterator>;
    using const_reverse_iterator = psg::reverse_iterator<const_iterator>;

    array(void) = default;
    array(const array<T, arr_size> &rhs);
    array &operator=(const array<T, arr_size> &rhs);

    // Estas salen de random_access_functions
    //
    // reference at(size_type position);
    // const_reference at(size_type position) const;
    // reference operator[](size_type position);
    // const_reference operator[](size_type position) const;
    // reference front(void);
    // const_reference front(void) const;
    // reference back(void);
    // const_reference back(void) const;

    // Estas salen de random_access_iterator_functions
    //
    // iterator begin(void) noexcept;
    // iterator end(void) noexcept;
    // const_iterator begin(void) const noexcept;
    // const_iterator end(void) const noexcept;
    // const_iterator cbegin(void) const noexcept;
    // const_iterator cend(void) const noexcept;
    // reverse_iterator rbegin(void) noexcept;
    // reverse_iterator rend(void) noexcept;
    // const_reverse_iterator crbegin(void) const noexcept;
    // const_reverse_iterator crend(void) const noexcept;

    [[nodiscard]] constexpr bool   empty(void) const noexcept;
    [[nodiscard]] constexpr size_t size(void) const noexcept;
    [[nodiscard]] constexpr size_t max_size(void) const noexcept;

    void fill(const_reference value);
    void swap(array<T, arr_size> &other) noexcept;

    pointer       data() noexcept;
    const_pointer data() const noexcept;

   private:
    T object[arr_size]; // NOLINT Tiene que ser un array estilo C
};

}; // namespace psg

#endif
