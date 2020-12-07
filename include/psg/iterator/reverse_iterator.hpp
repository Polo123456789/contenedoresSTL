#ifndef PSG_ITERATOR_REVERSE_ITERATOR_HPP
#define PSG_ITERATOR_REVERSE_ITERATOR_HPP

#include <psg/iterator/reverse_iterator/bidirectional_iterator.hpp>
#include <psg/iterator/reverse_iterator/random_access_iterator.hpp>

#include <psg/iterator/iterator_tags.hpp>
#include <psg/iterator/iterator_traits.hpp>

#include <psg/type_traits.hpp>

namespace psg {

/// Adaptador para que cualquier iterador, ya sea bidirectional o de random
/// access pueda utilizarse como iterador reverso
template<typename Iter>
using reverse_iterator =
    // clang-format off
    conditional_t<
        is_same_v<
            typename iterator_traits<Iter>::iterator_category,
            bidirectional_iterator_tag
        >,
        imp::reverce_bidirecitional_iterator<Iter>,
        imp::reverse_random_access_iterator<Iter>
    >;
// clang-format on

}; // namespace psg

#endif
