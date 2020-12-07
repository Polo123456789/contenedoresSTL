#ifndef PGSL_VIEWS_HPP
#define PGSL_VIEWS_HPP

#include <psg/type_traits.hpp>

namespace pgsl {

template<typename T, psg::enable_if_t<psg::is_pointer_v<T>, bool> dummie = true>
using owner = T;

}

#endif
