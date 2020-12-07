#include <pgsl/gsl.hpp>

#include "catch2/catch.hpp"

TEST_CASE("Narrowing cast", "[cast][narrowing cast]") {
    unsigned char narrowed = 0;
    int a = 10;
    narrowed = pgsl::narrow_cast<unsigned char>(a);
    CHECK(narrowed == 10);
    CHECK_THROWS_AS(pgsl::narrow<unsigned char>(512), pgsl::narrowing_error);
}
