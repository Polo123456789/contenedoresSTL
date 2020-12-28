#include "catch2/catch.hpp"
#include <psg/memory.hpp>
#include <pgsl/gsl.hpp>

// clang-format off
static_assert(psg::is_same_v<int *, pgsl::owner<int *>>);
static_assert(
    psg::is_same_v<pgsl::index, size_t> || psg::is_same_v<pgsl::index, ptrdiff_t>
);
// clang-format on

TEST_CASE("pgsl::at", "[gsl] [gsl_views]") {
    constexpr size_t size = 10;
    int              array[size];

    REQUIRE(array == psg::addressof(pgsl::at(array, 0)));

    for (pgsl::index i = 0; i < size; i++) {
        pgsl::at(array, i) = i;
    }

    for (pgsl::index i = 0; i < size; i++) {
        CHECK(array[i] == pgsl::narrow_cast<int>(i));
    }

    REQUIRE_THROWS_AS(pgsl::at(array, size + 1), psg::exception);
}
