#ifndef PSG_ITERATOR_HPP
#define PSG_ITERATOR_HPP

#include <cstddef>

#include <psg/iterator/iterator_tags.hpp>
#include <psg/iterator/iterator_helper.hpp>
#include <psg/iterator/iterator_traits.hpp>

namespace psg {

namespace imp {

template<typename InputIt>
typename iterator_traits<InputIt>::difference_type
    distance(InputIt first,
             InputIt last,
             random_acces_iterator_tag /*unused*/) {

    return last - first;
}

template<typename InputIt>
typename iterator_traits<InputIt>::difference_type
    distance(InputIt first, InputIt last, input_iterator_tag /*unused*/) {

    typename iterator_traits<InputIt>::difference_type d = 0;
    while (*(first++) != last) {
        ++d;
    }
    return d;
}

}; // namespace imp

template<typename InputIt>
typename iterator_traits<InputIt>::difference_type distance(InputIt first,
                                                            InputIt last) {
    return imp::distance(
        first,
        last,
        typename iterator_traits<InputIt>::iterator_category());
}

}; // namespace psg

#endif
