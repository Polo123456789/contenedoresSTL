#ifndef PSG_MEMORY_HPP
#define PSG_MEMORY_HPP

#include <cstddef>
#include <cstdlib>

#include "exception.hpp"
#include "utility.hpp"
#include "type_traits.hpp"

namespace psg {

/// Regresa la direccion de memoria de el argumento dado.
///
/// Sere completamente honesto, este lo copie de la posible implementacion que
/// se coloca en cppreference. Se me occuria una implementacion que solo fuera
/// `return &arg`, pero dice que tiene que funcionar aunque el operador & este
/// sobrecargado. Por ende, en lugar de romperme la cabeza tratando de buscar
/// como (Que no es el plan, el plan es implementar los contenedores), mejor
/// hago el buen copy paste y damos creditos.
///
/// [Link a el articulo de
/// cppreference](https://en.cppreference.com/w/cpp/memory/addressof)
template<typename T>
T *addressof(T &arg) noexcept {
    return reinterpret_cast<T *>(
        &const_cast<char &>(reinterpret_cast<const volatile char &>(arg)));
}

/// Construye un elemento en p, con el paquete de argumentos que se le hayan
/// dado.
/// 
/// Este recomendaria utilizarlo solo para elementos que asigno utilizando el
/// psg::allocator. Tendria que llamar al psg::destroy_at si utiliza este.
template<typename T, typename ...Args>
T* construct_at(T* p, Args&&... args) {
    new (p) T(forward<Args>(args)...);
    return p;
}

/// Destruye el elemento en la direccion p. 
/// 
/// Este seria el complemento del el construct_at
template<typename T>
void destroy_at(T* p) {
    p->~T();
}

/// Destruye todos los elementos en el rango first - last
template<typename ForwardIt>
void destroy(ForwardIt fist, ForwardIt last) {
    while(first != last) {
        destroy_at(addressof(*(first++)));
    }
}

/// Este es el encargado de asignar y limpiar memoria
///
/// Este es el que sera utilizado en todas las clases si el usuario no provee
/// uno. Este es carente de estado, esto significa que todas las instancias que
/// use de psg::allocator son intercabliables entre si.
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
    using propagate_on_container_copy_assingment = true_type;
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

    // Estos estan aqui solo por que si. Estan deprecados desde C++17.
    // Asi que ni me voy a molestar en definirlos.
    [[deprecated]] T *address(T &x) const noexcept;
    [[deprecated]] const T *address(const T &x) const noexcept;
    [[deprecated]] size_type max_size(void) const noexcept;
    template<typename U, typename... Args>
    [[deprecated]] void construct(U *p, Args &&... args);
    template<typename U>
    [[deprecated]] void destroy(U *p);
};

/// Asinga la memoria para un puntero tipo T.
///
/// La cantidad de memoria esta dada por sizeof(T)*size. Si la asignacion de la
/// memoria falla, lanza un psg::exception explicando que no pudo asingar la
/// memoria.
template<typename T>
[[nodiscard]] T *allocator<T>::allocate(size_type size) {
    T* ptr = nullptr;
    ptr = static_cast<T*>(malloc(sizeof(T) * size));
    if (ptr == nullptr) {
        throw exception("psg::allocator::exception Bad alloc: No se pudo "
                        "asignar la memoria");
    }
    return ptr;
}

/// Librera la memoria previamente asignada por el psg::allocator::allocate
//
/// El parametro de size es en relalidad uno que no utilizo, porque de fondo
/// solo uso malloc y free, pero lo mantengo para ser consistente con el
/// estandar. Ademas de que si vas a usar un allocator tuyo, puede que si lo
/// utilizes, asi que vamos a mantenerlo.
template<typename T>
void allocator<T>::deallocate(pointer ptr, size_type size [[maybe_unused]]) {
    free(ptr);
}

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
/// **NOTA:** De momento, solo usa el construct_at. Tendria que utilizar el
/// a.construct si incluyera el allcator, pero como no tengo ni idea de como
/// hacer eso, y quiero pasar ya al vector, pues me lo salto de momento y lo
/// implemento despues
template<typename Alloc>
template<typename... Args>
void allocator_traits<Alloc>::construct([[maybe_unused]] allocator_type &a,
    pointer p,
    Args &&... args) {

    construct_at(p, forward<Args>(args)...);
}

/// Destruye en un lugar dado.
///
/// **NOTA:** De momento, solo usa el destroy_at. Tendria que utilizar el
/// a.destroy si incluyera el allcator, pero como no tengo ni idea de como
/// hacer eso, y quiero pasar ya al vector, pues me lo salto de momento y lo
/// implemento despues
template<typename Alloc>
void allocator_traits<Alloc>::destroy([[maybe_unused]] allocator_type &a,
    pointer p) {

    destroy_at(p);
}

/// Regresa el tamaño maximo que puede asignar de un tiron.
template<typename Alloc>
constexpr typename allocator_traits<Alloc>::size_type
    allocator_traits<Alloc>::max_size(
        [[maybe_unused]] const Alloc &a) noexcept {

    return size_type(-1) / sizeof(value_type);
}

/// Regresa copia del allocator.
template<typename Alloc>
Alloc allocator_traits<Alloc>::select_on_container_copy_construction(
    const Alloc &a) {

    return a;
}

}; // namespace psg

#endif
