#include "iterator.hpp"

template <class T>
struct iterator : public psg::iterator<psg::input_iterator_tag, T> {};

int main()
{
    iterator<int>::value_type a;
}
