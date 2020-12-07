#ifndef PSG_ITERATOR_ITERATOR_TRAITS
#define PSG_ITERATOR_ITERATOR_TRAITS

namespace psg {

/// Es la clase que se usa para acceder a las caracteristicas del iterador
///
/// Puede especializarla para usar sus propias clases como iteradores
template<typename Iter>
struct iterator_traits {
    using difference_type = typename Iter::difference_type;
    using value_type = typename Iter::value_type;
    using pointer = typename Iter::pointer;
    using reference = typename Iter::reference;
    using iterator_category = typename Iter::iterator_category;
};

}; // namespace psg

#endif
