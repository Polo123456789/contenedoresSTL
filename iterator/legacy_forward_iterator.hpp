/*
 * .------..------..------..------..------.
 * |P.--. ||A.--. ||B.--. ||L.--. ||O.--. |
 * | :/\: || (\/) || :(): || :/\: || :/\: |
 * | (__) || :\/: || ()() || (__) || :\/: |
 * | '--'P|| '--'A|| '--'B|| '--'L|| '--'O|
 * `------'`------'`------'`------'`------'
 * .------..------..------..------..------..------..------.
 * |S.--. ||A.--. ||N.--. ||C.--. ||H.--. ||E.--. ||Z.--. |
 * | :/\: || (\/) || :(): || :/\: || :/\: || (\/) || :(): |
 * | :\/: || :\/: || ()() || :\/: || (__) || :\/: || ()() |
 * | '--'S|| '--'A|| '--'N|| '--'C|| '--'H|| '--'E|| '--'Z|
 * `------'`------'`------'`------'`------'`------'`------'
 *
 * Copyright (c) 2020 Pablo Sanchez Galdamez
 *
 * Descripcion de la clase:
 *
 *  LegacyForwardIterator:
 *
 *      Es un iterador que puede leer de el elemento al que apunta. Este es
 *      valido para algoritmos de mas de una pasada.
 *
 *  Requisitos:
 *
 *      * Es un LegacyIterator
 *      * Es EqualityComparable (bool operator==)
 *
 * */
#ifndef PSG_ITERATOR_LEGACY_FORWARD_ITERATOR_HPP
#define PSG_ITERATOR_LEGACY_FORWARD_ITERATOR_HPP

#include "legacy_iterator.hpp"

namespace psg {
namespace imp {

template<typename Container, typename value_type>
class LegacyForwardIterator : public LegacyIterator<Container, value_type> {
    using LegacyForwardIter = LegacyForwardIterator<Container, value_type>;

   public:
    bool operator==(const LegacyForwardIter &other);
    bool operator!=(const LegacyForwardIter &other);
    // Requiere mas investigacion.
    value_type *operator->();
    LegacyForwardIter operator++(int);
};

}; // namespace imp
}; // namespace psg
#endif
