#ifndef PSG_ITERATOR_ITERATOR_TRAITS
#define PSG_ITERATOR_ITERATOR_TRAITS

namespace psg {

/**
 * Clase utilizada por los contenedores de la libreria estandar para acceder a
 * las propiedades de los iteradores.
 */
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
