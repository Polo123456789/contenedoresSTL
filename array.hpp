#ifndef PSG_ARRAY_CPP
#define PSG_ARRAY_CPP

namespace algo {
  
template <typename T, const size_t arr_size>
class array {
  public:
    // Funcionen miembro
    array(void);
    array(const array<T, arr_size>& rhs);
    array(array<T, arr_size>&& rhs) noexcept;
    array& operator=(const array<T, arr_size>& rhs);
    array& operator=(array<T, arr_size>&& rhs) noexcept;
    ~array(void);

    // Acceso a elementos
    T& at(int position);
    T& operator[](int position);
    T& front(void);
    T& back(void);

    // Iteradores
    class iterator;
    class const_iterator;
    class reverse_iterator;

    // Capacidad
    bool empty(void);
    size_t size(void);
    size_t max_size(void);

    // Operaciones
    void fill(const T& value);
    void swap(array<T, arr_size>& other);
  private:
};

// TODO (pablo): Terminar la clase iterador. Puede ser mejor pasarla a una base

template <typename T, const size_t arr_size>
class array<T, arr_size>::iterator {
   public:
    // Funciones miembro
    iterator();
    ~iterator();
    iterator(const iterator& i);
    iterator(iterator&& i) noexcept;
    iterator& operator=(const iterator& i);
    iterator& operator=(iterator&& i) noexcept;

    // Operadores aritmeticos
    void operator++();
    iterator operator++(int);
    void operator--();
    iterator operator--(int);

    // Dereferencia
    iterator& operator*();
   private:
};


}  // namespace algo

#endif
