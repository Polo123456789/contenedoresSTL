#ifndef PSG_ALGORITHM_HPP
#define PSG_ALGORITHM_HPP

namespace psg {

/**
 * Copia los elementos en el rango [first - last) a el rango iniciado por
 * `o_begin`
 *
 * @param first Inicio de el rango del que se copiara
 * @param first Final de el rango del que se copiara
 * @param o_begin Inicio del rango al que se copiaran
 * @return El final de el rango al que se copiaron los valores
 */
template<typename InputIt, typename OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt o_begin) {
    for (; first != last; ++first, ++o_begin) {
        *o_begin = *first;
    }
}

/**
 * Copia los elementos en desde `first` hasta `first + count` al rango iniciado
 * por result
 *
 * @param first Inicio de el rango del que se copiara
 * @param count Cantidad de elementos que se copiaran
 * @param result Inicio del rango al que se copiara
 * @return El final de el rango al que se copiaron los valores
 */
template<typename InputIt, typename Size, typename OutputIt>
OutputIt copy_n(InputIt first, Size count, OutputIt result) {
    for (Size i = 0; i < count; ++i, ++result, ++first) {
        *result = *first;
    }
    return result;
}

/**
 * Ejecuta `f` en todos los elementos en el rango [first - last)
 *
 * @param first Inicio del rago
 * @param last Final del rago
 * @param f Una funcion, lambda, o functor que tome como parametro
 *          InputIt::value_type, InputIt::reference, o InputIt::const_reference
 * @return f
 */
template<typename InputIt, typename UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f) {
    for (; first != last; ++first) {
        f(*first);
    }
    return f;
}

namespace extra {

/**
 * Igual que psg::for_each, pero con dos rangos.
 */
template<typename InputIt, typename OtherInputIt, typename BinaryFunc>
BinaryFunc
    for_each(InputIt first, InputIt last, OtherInputIt other, BinaryFunc f) {

    for (; first != last; ++first, ++other) {
        f(*first, *other);
    }
    return f;
}

} // namespace extra

}; // namespace psg
#endif
