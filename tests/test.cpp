#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// Test de ejemplo:
//
// unsigned int Factorial(unsigned int number) {
//     return number > 1 ? Factorial(number - 1) * number : 1;
// }
// 
// SCENARIO("Factorials are computed", "[factorial]") {
//     GIVEN("A Factorial function") {
//         WHEN("We give it numbers") {
//             THEN("It gives results") {
//                 unsigned int fac_0 = Factorial(0);
//                 REQUIRE(fac_0 == 1);
//                 REQUIRE(Factorial(1) == 1);
//                 REQUIRE(Factorial(2) == 2);
//                 REQUIRE(Factorial(3) == 6);
//                 REQUIRE(Factorial(10) == 3628800);
//             }
//         }
//     }
// }
// 
// TEST_CASE("Factorials are computed", "[factorial]") {
//     REQUIRE(Factorial(0) == 1);
//     REQUIRE(Factorial(1) == 1);
//     REQUIRE(Factorial(2) == 2);
//     REQUIRE(Factorial(3) == 6);
//     SECTION("Big Numbers") {
//         REQUIRE(Factorial(10) == 3628800);
//     }
// }
