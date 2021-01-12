#ifndef PSG_LIST_NODE_HPP
#define PSG_LIST_NODE_HPP

#include <psg/memory.hpp>

namespace psg::imp {

/// List node
/// 
/// It will have a value, and pointers to the previous, and next elements. At
/// destruction, it will delete the next element in the list.
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

    struct insert_before_t {};
    struct insert_after_t {};
    static constexpr insert_after_t  insert_after;
    static constexpr insert_before_t insert_before;

    list_node(const_reference v, list_node* previous, insert_after_t);
    list_node(const_reference v, list_node* next, insert_before_t);
    list_node(value_type&& v, list_node* previous, insert_after_t);
    list_node(value_type&& v, list_node* next, insert_before_t);

    list_node(const list_node &l) = delete;
    list_node &operator=(const list_node &l) = delete;

    list_node(list_node &&l) noexcept;
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
    resourse_hanldler next = nullptr;
    value_type        object;
};




}; // namespace psg::imp

#endif
