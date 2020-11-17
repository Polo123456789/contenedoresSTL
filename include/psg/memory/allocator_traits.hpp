#ifndef PSG_MEMORY_ALLOCATO_TRAITS_HPP
#define PSG_MEMORY_ALLOCATO_TRAITS_HPP

#include <psg/memory/allocator_member_checks.hpp>
#include <psg/utility.hpp>

namespace psg {

/// Es la forma estandar de acceder a los atributos de un allocator.
///
/// Los contenedores que se utilizen en van a acceder a los allcators mediante
/// esta clase. En este caso el allocator tiene que definir:
///
/// * value_type
/// * pointer
/// * const_pointer
/// * difference_type
/// * size_type
/// * propagate_on_container_move_assingment
/// * propagate_on_container_copy_assingment
/// * is_allways_equal
/// * rebind
///
/// Ademas de los metodos:
///
/// * allocate
/// * deallocate
///
/// Que serian las cosas que se utilizan.
template<typename Alloc>
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
    template<typename ...Args>
    static void construct(allocator_type& a, pointer p, Args&& ...args);
    static void destroy(allocator_type &a, pointer p);
    static constexpr size_type max_size(const Alloc& a) noexcept;
    static Alloc select_on_container_copy_construction(const Alloc& a);
};

/// Asigna memoria utilizando el allocator.
template<typename Alloc>
[[nodiscard]] typename allocator_traits<Alloc>::pointer
    allocator_traits<Alloc>::allocate(allocator_type &a, size_type n) {

    pointer ptr = a.allocate(n);
    return ptr;
}

/// Libera memoria utilizando el allocator.
template<typename Alloc>
void allocator_traits<Alloc>::deallocate(allocator_type &a,
    pointer p,
    size_type n) {

    a.deallocate(p, n);
}


/// Construye en el lugar dado.
///
/// Usa el allocator::construct si existe, y si no, usa el emplace new
template<typename Alloc>
template<typename... Args>
void allocator_traits<Alloc>::construct(allocator_type &a,
    pointer p,
    Args &&... args) {

    if constexpr (imp::allocator_has_construct_v<Alloc>) {
        a.construct(p, forward<Args>(args)...);
    } else {
        construct_at(p, forward<Args>(args)...);
    }
}

/// Destruye en un lugar dado.
///
/// Usa allocator::destroy si existe, y si no usa destroy_at.
template<typename Alloc>
void allocator_traits<Alloc>::destroy([[maybe_unused]] allocator_type &a,
    pointer p) {

    if constexpr (imp::allocator_has_destroy_v<Alloc>) {
        a.destroy(p);
    } else {
        destroy_at(p);
    }
}

/// Regresa el tamaño maximo que puede asignar de un tiron.
template<typename Alloc>
constexpr typename allocator_traits<Alloc>::size_type
    allocator_traits<Alloc>::max_size(const Alloc &a) noexcept {

    if constexpr (imp::allocator_has_max_size_v<Alloc>) {
        return a.max_size();
    } else {
        return size_type(-1) / sizeof(value_type);
    }
}

/// Regresa copia del allocator usando select_on_container_copy_construction si
/// esta definido.
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


};  // namespace psg

#endif
