#include <psg/memory.hpp>

#include "catch2/catch.hpp"

bool element_constructed = false; // NOLINT
bool element_destroyed = false;   // NOLINT

// NOLINTNEXTLINE
class AllocTest {
   public:
    explicit AllocTest(int num) {
        val = num;
        element_constructed = true;
    }
    ~AllocTest() {
        element_destroyed = true;
    }
    bool operator==(int num) const noexcept {
        return val == num;
    }

   private:
    int val = 0;
};

TEST_CASE("psg::allocator", "[allocator]") {
    using ALI = psg::allocator<AllocTest>;
    ALI  a;
    AllocTest *i = nullptr;

    psg::allocator<int> dummie;
    constexpr size_t max_int_alloc_size = psg::allocator_traits<psg::allocator<int>>::max_size(dummie);

    REQUIRE_THROWS_AS(psg::allocator_traits<psg::allocator<int>>::allocate(dummie, max_int_alloc_size + 1), psg::exception);

    constexpr int allocated_size = 1;
    constexpr int value_to_construt = 2;

    i = psg::allocator_traits<ALI>::allocate(a, allocated_size);
    REQUIRE(i != nullptr);

    psg::allocator_traits<ALI>::construct(a, i, value_to_construt);
    REQUIRE(element_constructed);
    REQUIRE(*i == value_to_construt);

    psg::allocator_traits<ALI>::destroy(a, i);
    REQUIRE(element_destroyed);
    psg::allocator_traits<ALI>::deallocate(a, i, allocated_size);

}
