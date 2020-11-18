/*
 * Descripcion de la clase:
 *
 *  LegacyIterator:
 *
 *      Este se puede utilizar para pasar por los elementos de un contenedor.
 *  
 *  Requisitos:
 *      
 *      * Se pude construir por copia.
 *      * Se puede asignar por copia.
 *      * Se puede destruir.
 *      * Los lvalues se pueden hacer swap.
 *      * Es dereferenciable y se pueden incrementar.
 *
 * */

#ifndef PSG_ITERATOR_LEGACY_ITERATOR_HPP
#define PSG_ITERATOR_LEGACY_ITERATOR_HPP
namespace psg {
namespace imp {

template<typename Conatainer, typename value_type>
class LegacyIterator {
    using LegacyIter = LegacyIterator<Conatainer, value_type>;

   public:
    value_type& operator*(void);
    LegacyIter& operator++(void);
};

}; // namespace imp
}; // namespace psg
#endif
