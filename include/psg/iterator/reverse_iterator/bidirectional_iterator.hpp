#ifndef PSG_ITERATOR_REVERSE_ITERATOR_BIDIRECTIONAL_ITERATOR_HPP
#define PSG_ITERATOR_REVERSE_ITERATOR_BIDIRECTIONAL_ITERATOR_HPP

#include <psg/iterator/iterator_tags.hpp>
#include <psg/iterator/iterator_traits.hpp>

namespace psg::imp {

template<typename Iter>
class reverce_bidirecitional_iterator {
   public:
    using iterator_tag = bidirectional_iterator_tag;
    using value_type = typename iterator_traits<Iter>::value_type;
    using reference = typename iterator_traits<Iter>::reference;
    using pointer = typename iterator_traits<Iter>::pointer;
    using difference_type = typename iterator_traits<Iter>::difference_type;

    reverce_bidirecitional_iterator(Iter normal_iterator) //NOLINT [[implicit]]
        : normal_iterator(normal_iterator) {}

    reverce_bidirecitional_iterator &operator--(void) noexcept {
        ++normal_iterator;
        return *this;
    }

    reverce_bidirecitional_iterator operator--(int) noexcept {
        reverce_bidirecitional_iterator copy(normal_iterator);
        ++normal_iterator;
        return copy;
    }

    reverce_bidirecitional_iterator &operator++(void) noexcept {
        --normal_iterator;
        return *this;
    }

    reverce_bidirecitional_iterator operator++(int) noexcept {
        reverce_bidirecitional_iterator copy(normal_iterator);
        --normal_iterator;
        return copy;
    }

    bool operator==(const reverce_bidirecitional_iterator &other) noexcept {
        return normal_iterator == other.normal_iterator;
    }

    bool operator!=(const reverce_bidirecitional_iterator &other) noexcept {
        return normal_iterator != other.normal_iterator;
    }

    reference operator*(void) noexcept {
        return *normal_iterator;
    }

    pointer operator->() noexcept {
        return normal_iterator.operator->();
    }

   private:
    Iter normal_iterator{};
};

} // namespace psg::imp

#endif
