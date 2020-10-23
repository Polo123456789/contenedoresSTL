#ifndef PSG_ARRAY_ARRAY_CLASS_HPP
#define PSG_ARRAY_ARRAY_CLASS_HPP

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

    class iterator;
    class const_iterator;
    class reverse_iterator;
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
    T data[arr_size];
};

template<typename T, const size_t arr_size>
using ArrayIter = typename array<T, arr_size>::iterator;

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::begin() {
    return ArrayIter<T, arr_size>(data, 0);
}

template<typename T, const size_t arr_size>
ArrayIter<T, arr_size> array<T, arr_size>::end() {
    return ArrayIter<T, arr_size>(data, arr_size);
}

} // namespace psg

#endif
