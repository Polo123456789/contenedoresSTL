#include <psg/type_traits.hpp>

void type_traits_assertions_test_() {
    //clang-format off
    static_assert(
        psg::is_same_v<int, int> &&
        psg::is_same_v<double, double> &&
        psg::is_same_v<void, void> &&
        psg::is_same_v<float, float>
    );

    static_assert(psg::true_type{});
    static_assert(!psg::false_type{});

    static_assert(psg::is_same_v<
                    int,
                    psg::remove_reference_t<int&>
    >);

    static_assert(psg::is_same_v<
                    int,
                    psg::remove_reference_t<int&&>
    >);

    static_assert(psg::is_same_v<
                    const volatile int,
                    psg::remove_reference_t<const volatile int&>
    >);

    static_assert(psg::is_same_v<
                    int&,
                    psg::add_lvalue_reference_t<int>
    >);

    static_assert(psg::is_same_v<
                    int&,
                    psg::add_lvalue_reference_t<int&>
    >);

    static_assert(psg::is_same_v<
                    int&&,
                    psg::add_rvalue_reference_t<int&&>
    >);
}
