#ifndef PSG_ARRAY_CLASS
#define PSG_ARRAY_CLASS

#include <cstddef>

#include <psg/utility.hpp>
#include <psg/algorithm.hpp>
#include <psg/exception.hpp>
#include <psg/common/random_access_iterator_functions.hpp>
#include <psg/common/random_access_functions.hpp>

#include <pgsl/assert.hpp>

namespace psg {

/**
 * Contenedor que encapsula un array de tamaño fijo.
 */
template<typename T, const size_t arr_size>
class array // NOLINT No necesita los que son por movimiento
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

    /**
     * @return `true` si el contenedor esta vacio.
     *
     * **Nota:** Para el array esto solo aplica si tiene un tamaño de 0
     */
    [[nodiscard]] constexpr bool   empty(void) const noexcept;

    /**
     * @return El tamaño del contenedor
     */
    [[nodiscard]] constexpr size_t size(void) const noexcept;

    /**
     * @return El tamaño máximo del contenedor.
     *
     * **Nota:** En el caso del psg::array, siempre es verdadero que `a.size()
     * == a.max_size()`.
     */
    [[nodiscard]] constexpr size_t max_size(void) const noexcept;

    /**
     * @param value Valor a ser copiado en todas las posiciones del contendedor.
     */
    void fill(const_reference value);

    /**
     * @param other psg::array con el que se intercambiaran los contenidos.
     */
    void swap(array<T, arr_size> &other) noexcept;

    /**
     * @return Puntero a el array utilizado
     */
    pointer       data() noexcept;

    /**
     * @return Puntero constante a el array utilizado
     */
    const_pointer data() const noexcept;

   private:
    T object[arr_size]; // NOLINT Tiene que ser un array estilo C
};

}; // namespace psg

#endif
