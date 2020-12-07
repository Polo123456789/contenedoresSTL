#ifndef PSG_ITERATOR_ITERATOR_TAGS_HPP
#define PSG_ITERATOR_ITERATOR_TAGS_HPP

namespace psg {

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

}; // namespace psg

#endif
