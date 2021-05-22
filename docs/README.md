Nota
====

[![Build Status](https://travis-ci.com/Polo123456789/contenedoresSTL.svg?branch=main)](https://travis-ci.com/Polo123456789/contenedoresSTL)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/Polo123456789/contenedoresSTL.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Polo123456789/contenedoresSTL/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Polo123456789/contenedoresSTL.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Polo123456789/contenedoresSTL/context:cpp)

* El `namespace imp` esta reservado para los detalles de la complementación.
* El `namespace extra` tiene unos overloads que considero que serán útiles, pero
  no son estándar.
* La carpeta `common` es para las funcionalidades comunes entre varios
  contenedores. Por ejemplo, el `array` y el `vector` tienen en común algunas
  funciones de acceso aleatorio.
* Los `iterator_templates` estan solo de ejemplo, no se usan en nada

La documentación puede generarla usando doxygen. Para usarla copie la carpteta
include, añadala a el path de include en su compilador.

Probado con clang y visual studio en mi pc y con gcc en travis

Commits
-------

Formato: ("(%c)<%s>%s", tipo, donde, que)

| Tipos | Significado           |
|-------|-----------------------|
| =     | Cambio trivial        |
| ~     | Refactorizacion       |
| +     | Nuevo                 |
| -     | Correccion de error   |
| *     | Modificacion a la API |

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
