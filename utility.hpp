#ifndef PSG_UTILITY_HPP
#define PSG_UTILITY_HPP

#define PSG_S1(x) #x
#define PSG_S2(x) PSG_S1(x)
#define PSG_LOCATION __FILE__ " : " PSG_S2(__LINE__)

namespace psg {

/// Convierte un lvalue a un rvalue
template<typename T>
T&& move(T& t) {
    return static_cast<T&&>(t);
}

template<typename T>
T&& move(T&& t) {
    return move(t);
}

}; // namespace psg
#endif
