Nota
====

* El `namespace imp` esta reservado para los detalles de la complementación.
* El `namespace extra` tiene unos overloads que considero que serán útiles, pero
  no son estándar.
* La carpeta `common` es para las funcionalidades comunes entre varios
  contenedores. Por ejemplo, el `array` y el `vector` tienen en común algunas
  funciones de acceso aleatorio.

La documentación puede generarla usando doxygen. Para usarla copie la carpteta
include, añadala a el path de include en su compilador.

Probado con clang y visual studio. Cada cierto tiempo con gcc

Checklist:
==========

* [X] array.hpp
* [ ] algorithm.hpp (Parcial)
* [ ] vector.hpp (Parcial: En rework para que siga RAII, que si los
  constructores de los objetos tiran exceptiones deja un leak de memoria)
* [ ] exception.hpp (Parcial)
* [ ] iterator.hpp (Parcial)
* [ ] memory.hpp (Parcial)
* [ ] type_traits.hpp (Parcial)
* [ ] utility.hpp (Parcial)
* [ ] deque.hpp
* [ ] forward_list.hpp
* [ ] list.hpp
* [ ] map.hpp
* [ ] queue.hpp
* [ ] set.hpp
* [ ] span.hpp
* [ ] stack.hpp
* [ ] unordered_map.hpp
* [ ] unordered_set.hpp
