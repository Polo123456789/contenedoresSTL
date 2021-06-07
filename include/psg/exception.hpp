#ifndef PSG_EXCEPTION_HPP
#define PSG_EXCEPTION_HPP

#include <exception>

namespace psg {

/**
 * Clase encargada de las excepciones en la libreira
 */
class exception : public std::exception {
    const char *message = "psg::exception";

   public:
    exception() = default;

    inline explicit exception(const char *message) : message(message) {}

    [[nodiscard]] const char *what(void) const noexcept override {
        return message;
    }
};

}; // namespace psg

#endif
