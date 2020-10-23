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
 *  LegacyBidirectionalIterator:
 *
 *      Es un LegacyForwardIterator que se puede mover en ambas direcciones.
 *
 * */
#ifndef PSG_ITERATOR_LEGACY_BIDIRECTIONAL_ITERATOR_HPP
#define PSG_ITERATOR_LEGACY_BIDIRECTIONAL_ITERATOR_HPP

#include "legacy_forward_iterator.hpp"

namespace psg {
namespace imp {

template<typename Container, typename value_type>
class LegacyBidirectionalIterator
    : public LegacyForwardIterator<Container, value_type> {

    using LegacyBidirectionalIter =
        LegacyBidirectionalIterator<Container, value_type>;

   public:
    LegacyBidirectionalIter &operator--(void);
    LegacyBidirectionalIter operator--(int);
};

}; // namespace imp
}; // namespace psg
#endif
