#ifndef PSG_ALGORITHM_HPP
#define PSG_ALGORITHM_HPP

namespace psg {

/// Copia los valores.
///
/// Copia tantos valores como haya distance(first, last)
template<typename InputIt, typename OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt o_begin) {
    for (; first != last; ++first, ++o_begin) {
        *o_begin = *first;
    }

    if constexpr (false) {
        while (first != last) {
            *(o_begin++) = *(first++);
        }
        return o_begin;
    }
}

/// Copia n valores.
template<typename InputIt, typename Size, typename OutputIt>
OutputIt copy_n(InputIt fist, Size count, OutputIt result) {
    for (Size i = 0; i < count; i++, ++result, ++fist) {
        *result = *fist;
    }
    return result;
}

/// Ejecuta la funcion que se le dio en cada uno de los valores.
template<typename InputIt, typename UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f) {
    for (; first != last; ++first) {
        f(*first);
    }
    return f;

    if constexpr (false) {
        while (first != last) {
            f(*(first++));
        }
        return f;
    }
}

namespace extra {

/// Ejecuta la funcion para cada uno de los valores en el rango first, last. Va
/// añadiendo como segundo parametro other, que se ira incrementando tambien.
template<typename InputIt, typename OtherInputIt, typename BinaryFunc>
BinaryFunc
    for_each(InputIt first, InputIt last, OtherInputIt other, BinaryFunc f) {

    for (; first != last; ++first, ++other) {
        f(*first, *other);
    }
    return f;

    if constexpr (false) {
        while (first != last) {
            f(*(first++), *(other++));
        }
        return f;
    }
}

} // namespace extra

}; // namespace psg
#endif
