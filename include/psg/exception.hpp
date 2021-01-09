/*
 * .------..------..------..------..------.
 * |P.--. ||A.--. ||B.--. ||L.--. ||O.--. |
 * | :/\: || (\/) || :(): || :/\: || :/\: |
 * | (__) || :\/: || ()() || (__) || :\/: |
 * | '--'P|| '--'A|| '--'B|| '--'L|| '--'O|
 * `------'`------'`------'`------'`------'
 * .------..------..------..------..------..------..------.
 * |S.--. ||A.--. ||N.--. ||C.--. ||H.--. ||E.--. ||Z.--. |
 * | :/\: || (\/) || :(): || :/\: || :/\: || (\/) || :(): |
 * | :\/: || :\/: || ()() || :\/: || (__) || :\/: || ()() |
 * | '--'S|| '--'A|| '--'N|| '--'C|| '--'H|| '--'E|| '--'Z|
 * `------'`------'`------'`------'`------'`------'`------'
 *
 * Copyright (c) 2020 Pablo Sanchez Galdamez
 *
 * Mantengamos las excepciones sencillas. Para que tener toda una jerarquia
 * cuando una basta
 * */

#ifndef PSG_EXCEPTION_HPP
#define PSG_EXCEPTION_HPP

#include <exception>

namespace psg {

class exception : public std::exception {
    const char *message = "psg::exception";

   public:
    exception() = default;
    explicit exception(const char *message) : message(message) {}
    [[nodiscard]] const char *what(void) const noexcept override {
        return message;
    }
};

}; // namespace psg

#endif
