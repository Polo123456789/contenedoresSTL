#ifndef PSG_INITIALIZER_LIST_HPP
#define PSG_INITIALIZER_LIST_HPP

#include <initializer_list>

namespace psg {
    /// Este si es el initializer_list de la STL. Parece que se necesita una
    /// manita del compilador para usarla, asi que lo siento, pero la STL no es
    /// opcional.
    template <typename T>
    using initializer_list = std::initializer_list<T>;
}

#endif
