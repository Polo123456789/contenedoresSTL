#ifndef PGSL_UTILITIES_HPP
#define PGSL_UTILITIES_HPP

#include <cstddef>
#include <psg/exception.hpp>

namespace pgsl {

using index = size_t;

template<typename T, typename Input>
constexpr T narrow_cast(Input x) {
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

template<typename FinalAction>
class final_action { // NOLINT No los necesita
   public:
    constexpr explicit final_action(FinalAction f) : action(f) {}
    ~final_action() {
        action();
    }

   private:
    FinalAction action;
};

template<typename FinalAction>
constexpr final_action<FinalAction> finally(FinalAction f) {
    return final_action(f);
}

} // namespace pgsl

#endif
