#ifndef PSG_MEMORY_POINTER_SAFETY_HPP
#define PSG_MEMORY_POINTER_SAFETY_HPP

namespace psg {

enum class pointer_safety {
    relaxed,   // Todos los punteros son validos
    preferred, // Todos los punteros son validos, puede que haya un leak
               // detector
    strict // Solo punteros que se dieron con new pueden ser utilizados, puede
           // que haya un recolector de basura activo
};

inline constexpr pointer_safety get_pointer_safety(void) noexcept {
    return pointer_safety::relaxed;
}

}; // namespace psg

#endif
