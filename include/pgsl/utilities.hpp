#ifndef PGSL_UTILITIES_HPP
#define PGSL_UTILITIES_HPP

#include <cstddef>
#include <psg/exception.hpp>

namespace pgsl {

/**
 * Tag para las variables que se usan para indexar contenedores
 */
using index = size_t;

/**
 * Un static_cast que declara la intencion de que se haga el cast a un tipo de
 * menor tamaño.
 */
template<typename T, typename Input>
constexpr T narrow_cast(Input x) {
    return static_cast<T>(x);
}

/**
 * La clase que tira pgsl::narrow si la conversion fallo
 */
class narrowing_error : public psg::exception {
   public:
    inline explicit narrowing_error(const char *message)
        : psg::exception(message) {}
};

/**
 * Un static_cast que declara la intencion de que se haga el cast a un tipo de
 * menor tamaño.
 *
 * @throws pgsl::narrowing_error En caso de que el cast resulta en perdida de
 *                               datos
 */
template<typename T, typename Input>
T narrow(Input x) {
    T narrowed = static_cast<T>(x);
    if (narrowed != x) {
        throw narrowing_error(
            "pgsl::narrowing_error El cast resulto en perdida de datos");
    }
    return narrowed;
}

/**
 * Clase que en su destructor ejecuta la accion que se le dio.
 */
template<typename FinalAction>
class final_action { // NOLINT No los necesita
   public:
    constexpr explicit final_action(FinalAction f) : action(f) {}
    ~final_action() noexcept {
        action();
    }

   private:
    FinalAction action;
};

/**
 * Utilidad para crear acciones finales.
 *
 * **Nota:** Los destructores son `noexcept`, asi que el lambda no tiene que
 * tirar excepciones
 *
 * Uso:
 *
 * ~~~
 * auto clean_up = pgsl::finally([&]() noexcept {
 *      // Clean up code
 * });
 * ~~~
 */
template<typename FinalAction>
constexpr final_action<FinalAction> finally(FinalAction f) {
    return final_action(f);
}

} // namespace pgsl

#endif
