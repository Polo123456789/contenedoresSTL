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

#include <iterator_templates/legacy_iterator.hpp>

namespace psg {
namespace imp {

template<typename value_type>
class LegacyForwardIterator {
    using LegacyForwardIter = LegacyForwardIterator<value_type>;

   public:
    bool operator==(const LegacyForwardIter &other);
    bool operator!=(const LegacyForwardIter &other);

    value_type& operator*(void);
    value_type *operator->();
    LegacyForwardIter& operator++(void);
    LegacyForwardIter operator++(int);
};

}; // namespace imp
}; // namespace psg
#endif
