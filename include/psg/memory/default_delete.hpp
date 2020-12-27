#ifndef PSG_MEMORY_DEFAULT_NEW_DELETE_HPP
#define PSG_MEMORY_DEFAULT_NEW_DELETE_HPP

#include <pgsl/gsl.hpp>
#include <psg/memory/allocator.hpp>

namespace psg {

/// El delete default que se usa para el unique_ptr.
template<typename T>
struct default_delete {
    void operator()(pgsl::owner<T> *p) noexcept {
        delete p; // NOLINT
    }
};

template<typename T>
struct default_delete<T[]> {
    void operator()(pgsl::owner<T> *p) noexcept {
        delete[] p; // NOLINT
    }
};

} // namespace psg
#endif
