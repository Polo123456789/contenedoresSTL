#ifndef PSG_LIST_NODE_HPP
#define PSG_LIST_NODE_HPP

#include <psg/memory.hpp>

namespace psg::imp {

template<typename T, typename Allocator>
class list_node {
   public:
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = typename allocator_traits<Allocator>::pointer;
    using const_pointer = typename allocator_traits<Allocator>::const_pointer;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    list_node();
    list_node(const list_node &l);
    list_node(list_node &&l) noexcept;
    list_node &operator=(const list_node &l);
    list_node &operator=(list_node &&l) noexcept;
    ~list_node() noexcept;

   private:
    struct deleter {
        explicit deleter(allocator_type &alloc) : alloc(alloc) {}
        void operator()(pointer p) noexcept;

       private:
        allocator_type &alloc;
    };
    using resourse_hanldler = psg::unique_ptr<T, deleter>;

    list_node *       previous = nullptr;
    list_node *       next = nullptr;
    resourse_hanldler object = nullptr;
};

}; // namespace psg::imp

#endif
