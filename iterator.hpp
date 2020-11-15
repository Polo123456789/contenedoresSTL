#ifndef PSG_ITERATOR_HPP
#define PSG_ITERATOR_HPP

#include <cstddef>

namespace psg {

/*---------------------- Categorias de los iteradores: ----------------------*/

///  LegacyInputIterator:
///
///      Es un iterador que puede leer de el elemento al que apunta. Este solo
///      garantiza ser valido para algorimos de una pasada. Al ser el iterador I
///      incrementado, todas las copias previas del mismo pueden llegar a ser
///      invalidadas
///
///  Requisitos:
///
///      * Es un LegacyIterator
///      * Es EqualityComparable (bool operator==)
struct input_iterator_tag {};

///  LegacyOutputIterator:
///
///      Es un iterador que puede escribir a el elemento al que apunta. Este
///      solo garantiza ser valido para algorimos de una pasada. Al ser el
///      iterador I incrementado, todas las copias previas del mismo pueden
///      llegar a ser invalidadas
///
///  Requisitos:
///
///      * Es un LegacyIterator
///      * Es EqualityComparable (bool operator==)
struct output_iterator_tag {};

///  LegacyForwardIterator:
///
///      Es un iterador que puede leer de el elemento al que apunta. Este es
///      valido para algoritmos de mas de una pasada.
///
///  Requisitos:
///
///      * Es un LegacyIterator
///      * Es EqualityComparable (bool operator==)
struct forward_iterator_tag : public input_iterator_tag {};

///  LegacyBidirectionalIterator:
///
///      Es un LegacyForwardIterator que se puede mover en ambas direcciones.
struct bidirectional_iterator_tag : public forward_iterator_tag {};

///  LegacyRandomAccesIterator
///
///      Es un LegacyRandAccesIter que se puede mover a cualquier
///      elemtento en timempo constante.
struct random_acces_iterator_tag : public bidirectional_iterator_tag {};

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

}; // namespace psg

#endif
