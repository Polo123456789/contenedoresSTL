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
 *  LegacyRandomAccesIterator
 *
 *      Es un LegacyRandAccesIter que se puede mover a cualquier
 *      elemtento en timempo constante.
 *
 * */

#ifndef PSG_ITERATOR_LEGACY_RANDOM_ACCES_ITERATOR_HPP
#define PSG_ITERATOR_LEGACY_RANDOM_ACCES_ITERATOR_HPP

namespace psg {
namespace imp {

template<typename value_type>
class LegacyRandomAccesIterator {
    using LegacyRandAccesIter =
        LegacyRandomAccesIterator<value_type>;

   public:
    LegacyRandAccesIter &operator--(void);
    LegacyRandAccesIter operator--(int);
    LegacyRandAccesIter& operator++(void);
    LegacyRandAccesIter operator++(int);
    bool operator==(const LegacyRandAccesIter &other);
    bool operator!=(const LegacyRandAccesIter &other);
    value_type& operator*(void);
    value_type *operator->();
    LegacyRandAccesIter &operator+=(int);
    LegacyRandAccesIter operator+(int) const;
    LegacyRandAccesIter &operator-=(int);
    LegacyRandAccesIter operator-(int) const;
    int operator-(const LegacyRandAccesIter& rhs) const;
    bool operator<(const LegacyRandAccesIter& rhs) const;
    bool operator>(const LegacyRandAccesIter& rhs) const;
    bool operator<=(const LegacyRandAccesIter& rhs) const;
    bool operator>=(const LegacyRandAccesIter& rhs) const;
    value_type& operator[](int);
};

}; // namespace imp
}; // namespace psg

#endif
