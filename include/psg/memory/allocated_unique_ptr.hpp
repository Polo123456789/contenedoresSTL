#ifndef PSG_MEMORY_ALLOCATED_UNIQUE_PTR_HPP
#define PSG_MEMORY_ALLOCATED_UNIQUE_PTR_HPP

#include <cstddef>

#include <pgsl/owners.hpp>

#include <psg/type_traits/reference_modifications.hpp>
#include <psg/memory/allocator_traits.hpp>

namespace psg::imp {

//
// TODO(Pablo): Implementar
//
// 1. Se le pide al vector x espacios
// 2. El constructor llama al create resource_handler indicando la cantidad de
//    elementos
// 3. Usando los allocator_traits y el allocator creado se asigna la memoria
// 4. El allocated_unique_ptr recive:
//      * El puntero a la memoria asignada
//      * Una referencia al allocator utilizado
//      * La cantidad de memoria asignada
// 5. ...
// 6. El vector destruye los objetos
// 7. El allocated_unique_ptr libera la memoria asignada
//

///
/// Objeto encargado de manejar manejar memoria dada por un allocator.
///
/// **Nota:** Este no construye los elementos
///
/// Este tiene la responsabilidad unica de liberar la memoria asignada. El
/// contenedor que lo utiliza sera responsable de la construccion y destruccion
/// de los elementos.
///
template<typename Allocator>
class allocated_unique_ptr {
    using traits = psg::allocator_traits<Allocator>;

   public:
    using pointer = typename traits::pointer;
    using element_type = typename traits::value_type;
    using size_type = typename traits::size_type;
    using allocator_type = Allocator;

    constexpr allocated_unique_ptr() noexcept = default;
    constexpr allocated_unique_ptr(nullptr_t) noexcept {} // NOLINT [[implicit]]
    allocated_unique_ptr(pointer p, Allocator &d) noexcept;
    template<typename U>
    explicit allocated_unique_ptr(
        allocated_unique_ptr<U> &&u) noexcept; // NOLINT [[implicit]]
    allocated_unique_ptr(const allocated_unique_ptr &) = delete;
    allocated_unique_ptr(allocated_unique_ptr &&u) noexcept;
    ~allocated_unique_ptr() noexcept;

    allocated_unique_ptr &operator=(allocated_unique_ptr &&u) noexcept;
    template<typename U>
    allocated_unique_ptr &operator=(allocated_unique_ptr<U> &&u) noexcept;
    allocated_unique_ptr &operator=(nullptr_t) noexcept;
    allocated_unique_ptr &operator=(const allocated_unique_ptr &) = delete;

    add_lvalue_reference_t<Allocator> operator*() const;
    pointer                           operator->() const noexcept;
    pointer                           get() const noexcept;
    allocator_type &                  get_allocator() noexcept;
    const allocator_type &            get_allocator() const noexcept;
    explicit                          operator bool() const noexcept;

    pointer release() noexcept;
    void    swap(allocated_unique_ptr &u) noexcept;
    void    reset(pointer p = pointer()) noexcept;

   private:
    pgsl::owner<pointer> object = nullptr;
    allocator_type &     deleter{};

};

} // namespace psg::imp

#endif
