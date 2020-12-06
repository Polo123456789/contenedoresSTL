cmake_minimum_required(VERSION 3.18.0)
project(Tests)


include_directories("../include")

add_executable(test
    "array.cpp"
    "test.cpp")

set_target_properties(test
    PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS off
    )
