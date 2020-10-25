#ifndef PSG_ALGORITHM_HPP
#define PSG_ALGORITHM_HPP

namespace psg {

template<typename InputIt, typename OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt o_begin) {
    while (first != last) {
        *(o_begin++) = *(first++);
    }
    return o_begin;
}

template<typename InputIt, typename Size, typename OutputIt>
OutputIt copy_n(InputIt fist, Size count, OutputIt result) {
    for (int i=0; i<count; i++) {
        *(result++) = *(fist++);
    }
   return result;
}

template<typename InputIt, typename UnaryFunc>
void for_each(InputIt first, InputIt last, UnaryFunc f) {
    while (first != last) {
        f(*(first++));
    }
}

template<typename T>
void swap(T& a, T& b) noexcept {
    T tmp = a;
    a = b;
    b = tmp;
}

}; // namespace psg
#endif
