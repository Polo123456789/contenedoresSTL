#ifndef PSG_UTILITY_HPP
#define PSG_UTILITY_HPP

namespace psg {

template<typename T>
T&& move(T& t) {
    return static_cast<T&&>(t);
}

}; // namespace psg
#endif
