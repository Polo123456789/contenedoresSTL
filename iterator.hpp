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
 * Este header define los iteradores disponibles para utilizar en las clases,
 * estos llevan como parametro de template el conetendor al que pertenecen (para
 * poder tener polimorfismo pero en tiempo de compilacion) y el valor que
 * regresan.
 *
 * */

#ifndef PSG_ITERATOR_HPP
#define PSG_ITERATOR_HPP

#include "iterator/legacy_iterator.hpp"
#include "iterator/legacy_input_iterator.hpp"
#include "iterator/legacy_forward_iterator.hpp"
#include "iterator/legacy_bidirectional_iterator.hpp"
#include "iterator/legacy_random_acces_iterator.hpp"

 // El LegacyContiguosIterator, es el de randon acces pero en memoria continua.
 // No lo incluyo ya que de momento creo que seria bloat nada mas.

#endif
