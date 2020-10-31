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
~~~
