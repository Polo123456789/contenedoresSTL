#ifndef PGSL_UTILITIES_HPP
#define PGSL_UTILITIES_HPP

#include <cstddef>
#include <psg/exception.hpp>

namespace pgsl {

using index = ptrdiff_t;

template<typename T, typename Input>
T narrow_cast(Input x) {
    return static_cast<T>(x);
}

class narrowing_error : public psg::exception {
   public:
    explicit narrowing_error(const char *message) : psg::exception(message) {}
};

template<typename T, typename Input>
T narrow(Input x) {
    T narrowed = static_cast<T>(x);
    if (narrowed != x) {
        throw narrowing_error(
            "pgsl::narrowing_error El cast resulto en perdida de datos");
    }
    return narrowed;
}

} // namespace pgsl

#endif
