#ifndef PSG_MEMORY_UNIQUE_PTR_SINGLE_CLASS_HPP
#define PSG_MEMORY_UNIQUE_PTR_SINGLE_CLASS_HPP

#include <cstddef>

#include <psg/type_traits/reference_modifications.hpp>
#include <psg/memory/default_delete.hpp>

namespace psg {

/**
 * Puntero inteligente encargado de manejar un objeto.
 *
 * **Nota:** Este no puede ser copiado, solo se puede mover.
 */
template<class T, class Deleter = default_delete<T>>
class unique_ptr {
   public:
    using pointer = T *;
    using element_type = T;
    using deleter_type = Deleter;

    constexpr unique_ptr() noexcept = default;
    explicit unique_ptr(pointer p) noexcept;

    constexpr unique_ptr(std::nullptr_t) noexcept {} // NOLINT [[implicit]]
    unique_ptr &operator=(std::nullptr_t) noexcept;

    unique_ptr(pointer p, Deleter d) noexcept;

    template<class U, class E>
    unique_ptr(unique_ptr<U, E> &&u) noexcept; // NOLINT [[implicit]]
    template<class U, class E>
    unique_ptr &operator=(unique_ptr<U, E> &&u) noexcept;

    unique_ptr(unique_ptr &&u) noexcept;
    unique_ptr &operator=(unique_ptr &&u) noexcept;

    ~unique_ptr() noexcept;

    unique_ptr(const unique_ptr &) = delete;
    unique_ptr &operator=(const unique_ptr &) = delete;

    /**
     * @return Una referencia al objeto que tiene
     */
    add_lvalue_reference_t<T> operator*() const;

    /**
     * Permite acceder a los miembros de T
     */
    pointer operator->() const noexcept;

    /**
     * @return Un puntero al objeto que tiene
     */
    pointer get() const noexcept;

    /**
     * @return El deleter que se usa para eliminar el objeto
     */
    deleter_type &get_deleter() noexcept;

    /**
     * @return Una referencia constante a el deleter que se usa para eliminar el
     * objeto
     */
    const deleter_type &get_deleter() const noexcept;

    /**
     * @return true si el objeto apunta a algo
     */
    explicit operator bool() const noexcept;

    /**
     * Deja de ser el dueño de el objeto que controlaba
     *
     * @return La direccion de memoria del objeto
     */
    pointer release() noexcept;

    /**
     * Intercambia objetos con `u`
     */
    void swap(unique_ptr &u) noexcept;

    /**
     * Destruye al objeto que tenia y pasa a tomar el control de `p`
     *
     * **Nota:** De usarse como `ptr.reset()` o `ptr.reset(nullptr)` unicamente
     * destruira el objeto que tenia
     */
    void reset(pointer p = pointer()) noexcept;

   private:
    pgsl::owner<pointer> object = nullptr;
    deleter_type         deleter{};
};

} // namespace psg

#endif
