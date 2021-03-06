/*
 * Descripcion de la clase:
 *
 *  LegacyBidirectionalIterator:
 *
 *      Es un LegacyForwardIterator que se puede mover en ambas direcciones.
 *
 * */
#ifndef PSG_ITERATOR_LEGACY_BIDIRECTIONAL_ITERATOR_HPP
#define PSG_ITERATOR_LEGACY_BIDIRECTIONAL_ITERATOR_HPP

#include <psg/iterator_templates/legacy_forward_iterator.hpp>

namespace psg {
namespace imp {

template<typename value_type>
class LegacyBidirectionalIterator {

    using LegacyBidirectionalIter =
        LegacyBidirectionalIterator<value_type>;

   public:
    LegacyBidirectionalIterator &operator--(void);
    LegacyBidirectionalIterator operator--(int);
    LegacyBidirectionalIterator& operator++(void);
    LegacyBidirectionalIterator operator++(int);
    bool operator==(const LegacyBidirectionalIterator &other);
    bool operator!=(const LegacyBidirectionalIterator &other);
    value_type& operator*(void);
    value_type *operator->();
};

}; // namespace imp
}; // namespace psg
#endif
