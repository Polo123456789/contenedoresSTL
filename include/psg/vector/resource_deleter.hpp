#ifndef PSG_VECTOR_RESOURCE_HANDLER_HPP
#define PSG_VECTOR_RESOURCE_HANDLER_HPP

#include <psg/memory.hpp>

namespace psg::imp {

// TODO(Pablo): Implementar allocated_unique_ptr
// 
// NEXT: Terminar el resource_deleter
//
// Ahora nos topamos con otro problema, ya que el resource_deleter tiene que
// tener conocimiento de el tamaño de la cantidad de objetos asignados. Supongo
// que para seguir con el modelo de RAII tendrem que implementar un
// allocated_unique_ptr.
//
// NOTE: El unique_ptr<[]> No funciona porque eta hecho para trabajar con new y
// delete, por ende no tiene conocimiento de la cantidad de objetos asignados

template<typename Allocator>
class vector_resource_deleter {
   private:
    using traits = typename psg::allocator_traits<Allocator>;

   public:
    using pointer = typename traits::pointer;
    void operator()(pointer p) {

    }

   private:
    Allocator &alloc;
};

}; // namespace psg::imp

#endif
