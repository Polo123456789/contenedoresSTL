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
 *  LegacyInputIterator:
 *
 *      Es un iterador que puede leer de el elemento al que apunta. Este solo
 *      garantiza ser valido para algorimos de una pasada. Al ser el iterador I
 *      incrementado, todas las copias previas del mismo pueden llegar a ser
 *      invalidadas
 *
 *  Requisitos:
 *
 *      * Es un LegacyIterator
 *      * Es EqualityComparable (bool operator==)
 *
 * */

#ifndef PSG_ITERATOR_LEGACY_INPUT_ITERATOR_HPP
#define PSG_ITERATOR_LEGACY_INPUT_ITERATOR_HPP

#include "legacy_iterator.hpp"

namespace psg {
namespace imp {

template<typename Container, typename value_type>
class LegacyInputIterator : public LegacyIterator<Container, value_type> {
    using LegacyInpurIt = LegacyInputIterator<Container, value_type>;
   public:
    bool operator==(const LegacyInpurIt& other);
    bool operator!=(const LegacyInpurIt& other);
    // Requiere mas investigacion.
    value_type* operator->();
    LegacyInpurIt operator++(int);
};

}; // namespace imp
}; // namespace psg
#endif
