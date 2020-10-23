#ifndef PSG_ARRAY_CPP
#define PSG_ARRAY_CPP

#include "iterator.hpp"

namespace psg {

template<typename T, const size_t arr_size>
class array {
   public:
    // Funcionen miembro
    array(void) = default;
    array(const array<T, arr_size> &rhs);
    array(array<T, arr_size> &&rhs) noexcept = delete;
    array &operator=(const array<T, arr_size> &rhs);
    array &operator=(array<T, arr_size> &&rhs) noexcept = delete;
    ~array(void) = default;

    // Acceso a elementos
    T &at(int position);
    T &operator[](int position);
    T &front(void);
    T &back(void);

    // Iteradores
    using iterator = imp::LegacyRandomAccesIterator<array<T, arr_size>, T>;
    using const_iterator =
        imp::LegacyRandomAccesIterator<array<T, arr_size>, const T>;
    using reverse_iterator =
        imp::LegacyRandomAccesIterator<array<T, arr_size>, T>;
    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();
    reverse_iterator rbegin();
    reverse_iterator rend();

    // Capacidad
    bool empty(void);
    size_t size(void);
    size_t max_size(void);

    // Operaciones
    void fill(const T &value);
    void swap(array<T, arr_size> &other);

   private:
};

}; // namespace psg

#endif
