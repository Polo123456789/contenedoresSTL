#ifndef PSG_MEMORY_ALLOCATOR_MEMBER_CHECKS_HPP
#define PSG_MEMORY_ALLOCATOR_MEMBER_CHECKS_HPP

namespace psg {

/*
 * Lo mas facil es que busques en google SFINAE. De todas maneras el primer
 * check se trata de explicar a si mismo.
 */

namespace imp {

template<typename Alloc, typename... Args>
struct allocator_has_construct {
    // Vamos a tener un struct que tiene como template un tipo, y un puntero a
    // una funcion miembro del tipo.
    template<typename T, void (T::*)(typename T::pointer, Args &&...)>
    struct SFINAE {};

    // Luego 2 funciones pueden los tipos que tu quieras, mientras tengan
    // tamaños diferentes
    //
    // Si tiene el metodo construct, va a llamar la funcion que regresa un char.
    template<typename T>
    static char Test(SFINAE<T, &T::construct> *);
    // Si no tiene el metodo struct, el template anterior falla, pero no nos da
    // error, solo va al siguiente overload. Este regresa un int.
    template<typename T>
    static int Test(...);

    // Entonces el tamaño del valor que regresa.
    static constexpr bool value = (sizeof(Test<Alloc>(0)) == sizeof(char));
};

// Ahora que ya sabemos que estamos haciendo, apliquemolo para los demas.

template<typename Alloc>
struct allocator_has_destroy {
    template<typename T, void (T::*)(typename T::pointer)>
    struct SFINAE {};

    template<typename T>
    static char Test(SFINAE<T, &T::destroy> *);
    template<typename T>
    static int Test(...);

    static constexpr bool value = (sizeof(Test<Alloc>(0)) == sizeof(char));
};

template<typename Alloc>
struct allocator_has_max_size {
    template<typename T, typename T::size_type (T::*)(void) const noexcept>
    struct SFINAE {};

    template<typename T>
    static char Test(SFINAE<T, &T::max_size> *);
    template<typename T>
    static int            Test(...);
    static constexpr bool value = (sizeof(Test<Alloc>(0)) == sizeof(char));
};

template<typename Alloc>
struct allocator_has_select_on_container_copy_construction {
    template<typename T, T (T::*)(void) const>
    struct SFINAE {};

    template<typename T>
    static char Test(SFINAE<T, &T::select_on_container_copy_construction> *);
    template<typename T>
    static int Test(...);

    static constexpr bool value = (sizeof(Test<Alloc>(0)) == sizeof(char));
};

template<typename Alloc>
constexpr bool allocator_has_construct_v =
    allocator_has_construct<Alloc>::value;

template<typename Alloc>
constexpr bool allocator_has_destroy_v = allocator_has_destroy<Alloc>::value;

template<typename Alloc>
constexpr bool allocator_has_max_size_v = allocator_has_max_size<Alloc>::value;

template<typename Alloc>
constexpr bool allocator_has_select_on_container_copy_construction_v =
    allocator_has_select_on_container_copy_construction<Alloc>::value;

}; // namespace imp

}; // namespace psg

#endif
