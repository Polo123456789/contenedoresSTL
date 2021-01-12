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

    struct insert_before_tag {};
    struct insert_after_tag {};
    static constexpr insert_after_tag  insert_after;
    static constexpr insert_before_tag insert_before;

    list_node(allocator_type &alloc,
              const_reference v,
              list_node *     previous,
              insert_after_tag /*unused*/);

    list_node(allocator_type &alloc,
              const_reference v,
              list_node *     next,
              insert_before_tag /*unused*/);

    list_node(allocator_type &alloc,
              value_type &&   v,
              list_node *     previous,
              insert_after_tag /*unused*/);

    list_node(allocator_type &alloc,
              value_type &&   v,
              list_node *     next,
              insert_before_tag /*unused*/);

    reference get_value() noexcept {
        return object;
    }
    const_reference get_value() const noexcept {
        return object;
    }

    list_node* get_previous() const noexcept {
        return previous;
    }

    list_node* get_next() const noexcept {
        return next.get();
    }

   private:
    struct deleter {
        explicit deleter(allocator_type &alloc) : alloc(alloc) {}
        void operator()(pointer p) noexcept;

       private:
        allocator_type &alloc;
    };
    using resourse_hanldler = psg::unique_ptr<list_node, deleter>;
    resourse_hanldler make_handler(list_node* next);

    allocator_type &  alloc;
    list_node *       previous = nullptr;
    resourse_hanldler next = nullptr;
    value_type        object;
};

template<typename T, typename Allocator>
auto list_node<T, Allocator>::make_handler(list_node *next)
    -> resourse_hanldler {

    deleter d(alloc);
    return psg::unique_ptr<T, deleter>(next, d);
}

template<typename T, typename Allocator>
list_node<T, Allocator>::list_node(allocator_type &alloc,
                                   const_reference v,
                                   list_node *     previous,
                                   insert_after_tag /*unused*/)
    : alloc(alloc), previous(previous), object(v) {}

template<typename T, typename Allocator>
list_node<T, Allocator>::list_node(allocator_type &alloc,
                                   const_reference v,
                                   list_node *     next,
                                   insert_before_tag /*unused*/) 
: alloc(alloc), object(v) {
    next = make_handler(next);
}

template<typename T, typename Allocator>
list_node<T, Allocator>::list_node(allocator_type &alloc,
                                   value_type &&   v,
                                   list_node *     previous,
                                   insert_after_tag /*unused*/)
    : alloc(alloc), previous(previous), object(psg::move(v)) {}

template<typename T, typename Allocator>
list_node<T, Allocator>::list_node(allocator_type &alloc,
                                   value_type &&   v,
                                   list_node *     next,
                                   insert_before_tag /*unused*/)
: alloc(alloc), object(psg::move(v)) {
    next = make_handler(next);
}


}; // namespace psg::imp

#endif
