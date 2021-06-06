#ifndef PSG_MEMORY_ALLOCATO_TRAITS_HPP
#define PSG_MEMORY_ALLOCATO_TRAITS_HPP

#include <pgsl/assert.hpp>
#include <psg/memory/functions.hpp>
#include <psg/memory/allocator_member_checks.hpp>

namespace psg {

/**
 * Es la forma estandar de acceder a los atributos de un allocator.
 *
 * Los contenedores que se utilizen en van a acceder a los allcators mediante
 * esta clase. En este caso el allocator tiene que definir:
 *
 * * value_type
 * * pointer
 * * const_pointer
 * * difference_type
 * * size_type
 * * propagate_on_container_move_assingment
 * * propagate_on_container_copy_assingment
 * * is_allways_equal
 * * rebind
 *
 * Ademas de los metodos:
 *
 * * allocate
 * * deallocate
 *
 * Opcionalmente puede implementar:
 *
 * * construct
 *
 * Que serian las cosas que se utilizan.
 */
template<typename Alloc>
struct allocator_traits {
    using allocator_type = Alloc;
    using value_type = typename Alloc::value_type;
    using pointer = typename Alloc::pointer;
    using const_pointer = typename Alloc::const_pointer;
    using void_pointer = void *;
    using const_void_pointer = const void *;
    using difference_type = typename Alloc::difference_type;
    using size_type = typename Alloc::size_type;

    /**
     * Indica si el allocator tiene que moverse en caso de que el contenedor sea
     * movido
     */
    using propagate_on_container_move_assingment =
        typename Alloc::propagate_on_container_move_assingment;

    /**
     * Indica si el allocator tiene que copiarse en caso de que el contenedor
     * sea movido
     */
    using propagate_on_container_copy_assingment =
        typename Alloc::propagate_on_container_copy_assingment;

    using is_allways_equal = typename Alloc::is_allways_equal;

    template<typename T>
    using rebind_alloc = typename Alloc::template rebind<T>::other;

    template<typename T>
    using rebind_traits = allocator_traits<rebind_alloc<T>>;

    /**
     * Equivalente a `a.allocate(n)`
     */
    [[nodiscard]] static pointer allocate(Alloc &a, size_type n);

    /**
     * Equivalente a `a.deallocate(p, n)`
     */
    static void deallocate(allocator_type &a, pointer p, size_type n) noexcept;

    /**
     * Contruye un elemento en `p`
     *
     * Si el allocator tiene implementado el metodo construct, usa eso. De otro
     * modo es equivalente a usar `psg::construct_at`
     */
    template<typename... Args>
    static void construct(allocator_type &a, pointer p, Args &&...args);
    
    /**
     * Destruye un elemento en `p`
     *
     * Si el allocator tiene implementado el metodo destroy, usa eso. De otro
     * modo es equivalente a usar `psg::destroy_at`
     */
    static void destroy(allocator_type &a, pointer p) noexcept;

    /**
     * Indica la maxima cantidad de elementos que se pueden crear usando el
     * allocator
     *
     * Si el allocator implementa el metodo max_size se usa eso. De otro modo se
     * equivalente a `size_type(-1) / sizeof(value_type)`
     *
     * **Nota:** De no tener implementado un metodo max_size, se espera que el
     * `size_type` del allocator sea un tipo `unsigned`
     */
    static constexpr size_type max_size(const Alloc &a) noexcept;

    /**
     * Retorna el allocator a usar cuando se construya por copia.
     *
     * Si el allocator tiene un metodo `select_on_container_copy_construction`
     * se usa eso, de otro modo se retorna el allocator.
     */
    static Alloc select_on_container_copy_construction(const Alloc &a);
};

template<typename Alloc>
[[nodiscard]] auto allocator_traits<Alloc>::allocate(allocator_type &a,
                                                     size_type n) -> pointer {

    pointer ptr = a.allocate(n);
    return ptr;
}

template<typename Alloc>
void allocator_traits<Alloc>::deallocate(allocator_type &a,
                                         pointer         p,
                                         size_type       n) noexcept {
    a.deallocate(p, n);
}

template<typename Alloc>
template<typename... Args>
void allocator_traits<Alloc>::construct(allocator_type &a,
                                        pointer         p,
                                        Args &&...args) {

    if constexpr (imp::allocator_has_construct_v<Alloc>) {
        a.construct(p, forward<Args>(args)...);
    } else {
        construct_at(p, forward<Args>(args)...);
    }
}

template<typename Alloc>
void allocator_traits<Alloc>::destroy(allocator_type &a, pointer p) noexcept {

    if constexpr (imp::allocator_has_destroy_v<Alloc>) {
        a.destroy(p);
    } else {
        destroy_at(p);
    }
}

template<typename Alloc>
constexpr auto allocator_traits<Alloc>::max_size(const Alloc &a) noexcept
    -> size_type {

    if constexpr (imp::allocator_has_max_size_v<Alloc>) {
        return a.max_size();
    } else {
        Axiom(is_unsigned_v<size_type>); // TODO(pabsa): Implementar is_unsigned
                                         // para que sea un static_assert en
                                         // lugar de un Axiom.
        return size_type(-1) / sizeof(value_type);
    }
}

template<typename Alloc>
Alloc allocator_traits<Alloc>::select_on_container_copy_construction(
    const Alloc &a) {

    if constexpr (imp::allocator_has_select_on_container_copy_construction_v<
                      Alloc>) {
        return a.select_on_container_copy_construction();
    } else {
        return a;
    }
}

}; // namespace psg

#endif
