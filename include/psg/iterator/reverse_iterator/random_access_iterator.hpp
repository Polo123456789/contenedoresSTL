#ifndef PSG_ITERATOR_REVERSE_ITERATOR_RANDOM_ACCESS_ITERATOR_HPP
#define PSG_ITERATOR_REVERSE_ITERATOR_RANDOM_ACCESS_ITERATOR_HPP

#include <cstddef>
#include <psg/iterator/iterator_tags.hpp>
#include <psg/iterator/iterator_traits.hpp>

namespace psg::imp {

template<typename Iter>
class reverse_random_access_iterator {

   public:
    using iterator_tag = bidirectional_iterator_tag;
    using value_type = typename iterator_traits<Iter>::value_type;
    using reference = typename iterator_traits<Iter>::reference;
    using pointer = typename iterator_traits<Iter>::pointer;
    using difference_type = typename iterator_traits<Iter>::difference_type;

    explicit reverse_random_access_iterator(Iter normal_iterator)
        : normal_iterator(normal_iterator) {}

    reverse_random_access_iterator &operator--(void) noexcept {
        ++normal_iterator;
        return *this;
    }

    reverse_random_access_iterator operator--(int) noexcept {
        reverse_random_access_iterator copy(normal_iterator);
        ++normal_iterator;
        return copy;
    }

    reverse_random_access_iterator &operator++(void) noexcept {
        --normal_iterator;
        return *this;
    }

    reverse_random_access_iterator operator++(int) noexcept {
        reverse_random_access_iterator copy(normal_iterator);
        --normal_iterator;
        return copy;
    }

    bool operator==(const reverse_random_access_iterator &other) noexcept {
        return normal_iterator == other.normal_iterator;
    }

    bool operator!=(const reverse_random_access_iterator &other) noexcept {
        return normal_iterator != other.normal_iterator;
    }

    reference operator*(void) noexcept {
        return *normal_iterator;
    }

    pointer operator->() noexcept {
        return normal_iterator.operator->();
    }

    reverse_random_access_iterator &
        operator+=(difference_type amount) noexcept {
        normal_iterator -= amount;
        return *this;
    }

    reverse_random_access_iterator
        operator+(difference_type amount) const noexcept {
        return reverse_random_access_iterator(normal_iterator - amount);
    }

    reverse_random_access_iterator &
        operator-=(difference_type amount) noexcept {
        normal_iterator += amount;
        return *this;
    }

    reverse_random_access_iterator
        operator-(difference_type amount) const noexcept {

        return reverse_random_access_iterator(normal_iterator + amount);
    }

    difference_type
        operator-(const reverse_random_access_iterator &rhs) const noexcept {
        return -(normal_iterator - rhs.normal_iterator);
    }

    bool operator<(const reverse_random_access_iterator &rhs) const noexcept {
        return normal_iterator >= rhs.normal_iterator;
    }

    bool operator>(const reverse_random_access_iterator &rhs) const noexcept {
        return normal_iterator <= rhs.normal_iterator;
    }

    bool operator<=(const reverse_random_access_iterator &rhs) const noexcept {
        normal_iterator > rhs.normal_iterator;
    }

    bool operator>=(const reverse_random_access_iterator &rhs) const noexcept {
        return normal_iterator < rhs.normal_iterator;
    }

    reference operator[](difference_type index) noexcept {
        return normal_iterator[-index];
    }

   private:
    Iter normal_iterator{};
};

}; // namespace psg::imp

#endif
