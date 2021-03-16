#ifndef PSG_VECTOR_RESOURCE_HANDLER_HPP
#define PSG_VECTOR_RESOURCE_HANDLER_HPP

#include <psg/memory.hpp>

namespace psg::imp {

// TODO(Pablo): Terminar el resource_handler

template<typename Allocator>
class vector_resource_handler {
   private:
    using traits = typename psg::allocator_traits<Allocator>;

   public:
    using pointer = typename traits::pointer;
    void operator()(pointer p) {}

   private:
    Allocator &alloc;
};

}; // namespace psg::imp

#endif
