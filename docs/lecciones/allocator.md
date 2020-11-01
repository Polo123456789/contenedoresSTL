---
title: "Allocators en C++"
author: "Pablo Sanchez"
---

Allocator
=========

Este va a ser el encargado de gestionar la memoria que se requiera
dinamicamente durante el transcurso del programa. El `std::allocator` es el que
utilizan todos los contenedores de la `STL`.

Este seria un template de el allocator:

~~~c++
template<typename T>
class allocator {
   public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    /// Indica si tiene que ser copiado el allocator cuando el contenedor es
    /// move assigned
    using propagate_on_container_move_assingment = true_type;
    template<typename U>
    struct _rebind {
        using other = allocator<U>;
    };
    /// El rebind nos da una forma para obtener un allocator para un tipo
    /// diferente
    template<typename U>
    using rebind = _rebind<U>;
    using difference_type = ptrdiff_t;
    using is_allways_equal = true_type;

    [[nodiscard]] T *allocate(size_type size);
    void deallocate(T *ptr, size_type size [[maybe_unused]]);
};
~~~

Allocator traits
================

Este provee la forma estandar de acceder a los `allocator`, de este modo los
contendedores de la `STL` acceden a los allocators. Esto hace posible utilizar
cualquier clase como un allocator siempre y cuando la especializacion del
usuario de `allocator_traits` cumpla con las especificaciones.

El default sin especializar es de la siguiente forma:

~~~c++

template<typename Alloc = allocator<int>>
struct allocator_traits {
    using allocator_type = Alloc;
    using value_type = typename Alloc::value_type;
    using pointer = typename Alloc::pointer;
    using const_pointer = typename Alloc::const_pointer;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using difference_type = typename Alloc::difference_type;
    using size_type = typename Alloc::size_type;
    /// Indica si tiene que ser copiado el allocator al mover el contenedor.
    using propagate_on_container_move_assingment =
        typename Alloc::propagate_on_container_move_assingment;
    // Indica si tiene que ser copiado el allocator al mover el contenedor.
    using propagate_on_container_copy_assingment =
        typename Alloc::propagate_on_container_copy_assingment;
    using is_allways_equal = typename Alloc::is_allways_equal;
    template<typename T>
    using rebind_alloc = typename Alloc::template rebind<T>::other;
    template<typename T>
    using rebind_traits = allocator_traits<rebind_alloc<T>>;

    [[nodiscard]] static pointer allocate(Alloc& a, size_type n);
    static void deallocate(allocator_type& a, pointer p, size_type n);
    template<typename T, typename ...Args>
    static void construct(allocator_type& a, T* p, Args&& ...args);
    template<typename T>
    static void destroy(allocator_type &a, T* p);
    static constexpr size_type max_size(const Alloc& a) noexcept;
    static Alloc select_on_container_copy_construction(const Alloc& a);
};
~~~
