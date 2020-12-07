#ifndef PSG_ITERATOR_ITERATOR_HELPER
#define PSG_ITERATOR_ITERATOR_HELPER

#include <cstddef>

namespace psg {

/// Es una clase base que sirve como ayuda para la creacion de los iteradores
///
/// Yo la verdad es que solo la declaro aqui, porque esta, porque la verdad es
/// que no planeo usarla. El estandar tampoco, si la deprecaron en C++17
template<typename Category,
         typename T,
         typename Distance = ptrdiff_t,
         typename Pointer = T *,
         typename Reference = T &>
struct [[deprecated(
    R"(
La idea del iterator es heredarlo para dar las caracteristicas:

* value_type
* difference_type
* iterator_category
* pointer 
* reference

Tendra de dar esas caracteristicas manualmente si es que asi lo decea. O
puede especializar los iterator_traits si asi lo decea.
)")]] iterator {
    using iterator_category = Category;
    using value_type = T;
    using difference_type = Distance;
    using pointer = Pointer;
    using reference = Reference;
};

} // namespace psg

#endif
