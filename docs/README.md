Nota
====

[![Build Status](https://travis-ci.com/Polo123456789/contenedoresSTL.svg?branch=main)](https://travis-ci.com/Polo123456789/contenedoresSTL)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/Polo123456789/contenedoresSTL.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Polo123456789/contenedoresSTL/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Polo123456789/contenedoresSTL.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Polo123456789/contenedoresSTL/context:cpp)

Una implementacion en C++17 de las librerias de contenedores, iteradores,
algoritmos, y utilidades generales basado en [este draft del estandar de
C++17](docs/cpp17-draft.pdf). Y la GSL basado en lo que se comenta en las [core
guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-gsl)


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
