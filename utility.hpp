#ifndef PSG_UTILITY_HPP
#define PSG_UTILITY_HPP

#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION __FILE__ " : " S2(__LINE__)

namespace psg {

template<typename T>
T&& move(T& t) {
    return static_cast<T&&>(t);
}

}; // namespace psg
#endif
