#include <psg/memory/allocated_unique_ptr.hpp>
#include <psg/type_traits.hpp>

#include "catch2/catch.hpp"

static bool is_allocated = false; //NOLINT

template<typename T>
class test_allocator {
   public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using propagate_on_container_move_assingment = psg::false_type;
    using propagate_on_container_copy_assingment = psg::false_type;
    template<typename U>
    struct _rebind {
        using other = test_allocator<U>;
    };
    template<typename U>
    using rebind = _rebind<U>;
    using difference_type = ptrdiff_t;
    using is_allways_equal = psg::true_type;

    constexpr test_allocator() = default;

    [[nodiscard]] pointer allocate([[maybe_unused]] size_type size) {
        is_allocated = true;
        // NOLINTNEXTLINE No va a ser derefenciado
        return reinterpret_cast<int *>(
            1); // Para que el psg::imp::allocated_unique_ptr::reset se
                // ejecute correctamente
    }
    void deallocate([[maybe_unused]] T *       ptr,
                    [[maybe_unused]] size_type size [[maybe_unused]]) noexcept {
        is_allocated = false;
    }

   private:
    static constexpr size_type max_alloc_size =
        size_type(-1) / sizeof(value_type);
};

using test_type = int;
using alloc = test_allocator<test_type>;
using traits = psg::allocator_traits<alloc>;
constexpr traits::size_type allocated_size = 10;

TEST_CASE("Allocated Unique Pointer", "[allocated_unique_ptr] [memory]") {
    REQUIRE(!is_allocated);

    alloc      a{};
    test_type *raw_ptr = traits::allocate(a, allocated_size);

    REQUIRE(is_allocated);

    {
        // Constructed and destructed
        psg::imp::allocated_unique_ptr<alloc> smart_ptr(raw_ptr,
                                                        a,
                                                        allocated_size);
    }
    REQUIRE(!is_allocated);
}
