cmake_minimum_required(VERSION 3.9.0)
project(Tests)


include_directories("../include")

add_executable(run_tests
    "array.cpp"
    "allocator.cpp"
    "narrow_cast.cpp"
    "unique_ptr.cpp"
    "final_action.cpp"
    "type_traits.cpp"
    "pgsl_views.cpp"
    "test.cpp")

set_target_properties(run_tests
    PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS off
    )

# https://stackoverflow.com/questions/2368811/how-to-set-warning-level-in-cmake
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic)
endif()
