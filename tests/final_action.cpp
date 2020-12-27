#include "catch2/catch.hpp"
#include <pgsl/gsl.hpp>

TEST_CASE("final_action", "[pgsl] [final_action]") {
    bool flag = false;
    {
        auto set_flag = pgsl::finally([&]() {
            flag = true;
        });
    }
    REQUIRE(flag);
}
