cmake_minimum_required(VERSION 3.15.0)
project(Tests)


include_directories("../include")

add_executable(test
    "array.cpp"
    "allocator.cpp"
    "narrow_cast.cpp"
    "test.cpp")

set_target_properties(test
    PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS off
    )
