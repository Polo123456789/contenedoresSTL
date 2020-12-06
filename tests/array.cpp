#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch2/catch.hpp"

#include <psg/array.hpp>
#include <psg/memory/functions.hpp>

constexpr size_t            array_size = 10;
psg::array<int, array_size> test_array; // NOLINT

void manual_fill_array(int *span) {
    for (size_t i = 0; i < array_size; i++) {
        span[i] = i;//NOLINT
    }
}

void manual_fill_array_with_1(int *span) {
    for (size_t i = 0; i < array_size; i++) {
        span[i] = 1;//NOLINT
    }
}

TEST_CASE("Metodos del psg::array", "[array]") {
    SECTION("Prerequisitos para el test") {
        REQUIRE(test_array.data() != nullptr);
        REQUIRE(test_array.size() == array_size);
        REQUIRE(test_array.max_size() == array_size);

        // LLenado manual del array
        manual_fill_array(test_array.data());

        // Requierimos que el operador== funcione para los demas test
        psg::array<int, array_size> identical_array{};
        manual_fill_array(identical_array.data());
        REQUIRE(test_array == identical_array);
    }

    SECTION("Iteradores") {
        psg::array<int, array_size>::iterator test_array_begin =
            test_array.begin();
        psg::array<int, array_size>::iterator test_array_end = test_array.end();
        psg::array<int, array_size>::reverse_iterator test_array_rev_begin =
            test_array.rbegin();
        psg::array<int, array_size>::reverse_iterator test_array_rev_end =
            test_array.rend();

        REQUIRE(psg::addressof(*test_array_begin) == test_array.data());
        REQUIRE(psg::addressof(*test_array_end)
                == test_array.data() + test_array.size());
        REQUIRE(psg::addressof(*test_array_rev_begin)
                == test_array.data() + test_array.size() - 1);
        REQUIRE(psg::addressof(*test_array_rev_end) == test_array.data() - 1);
    }
    SECTION("Funciones miembro") {
        // Construccion por copia
        psg::array<int, array_size> copia1(test_array);
        CHECK(copia1 == test_array);

        psg::array<int, array_size> copia2{};

        copia2 = test_array;
        CHECK(copia2 == test_array);
    }

    SECTION("Acceso a los elementos") {
        CHECK(test_array.front() == 0);
        CHECK(test_array.back() == 9);
        for (size_t i = 0; i < test_array.size(); i++) {
            CHECK(test_array[i] == static_cast<int>(i));
        }
        for (size_t i = 0; i < test_array.size(); i++) {
            CHECK(test_array.at(i) == static_cast<int>(i));
        }
        CHECK_THROWS_AS(test_array.at(array_size), psg::exception);
        CHECK_THROWS_AS(test_array.at(-1), psg::exception);
    }

    SECTION("Capacidad") {
        // Los demas fueron prerequisitos para el test
        CHECK(test_array.empty() == false);
    }

    SECTION("Operaciones") {
        // Revisamos que el fill funcione correctamente
        psg::array<int, array_size> method_filled{};
        method_filled.fill(1);

        psg::array<int, array_size> manually_filled{};
        manual_fill_array_with_1(manually_filled.data());

        REQUIRE(method_filled == manually_filled);

        // Y hacemos lo mismo para el swap
        psg::array<int, array_size> test_copy(test_array);
        test_copy.swap(method_filled);

        CHECK(test_copy == manually_filled);
        CHECK(test_array == method_filled);
    }
}
