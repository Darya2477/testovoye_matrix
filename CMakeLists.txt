cmake_minimum_required(VERSION 3.0)
project(matrix_multiplier)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(matrix_multiplier ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(matrix_multiplier PRIVATE ${SRC_FILES})

enable_testing()
add_test(NAME test_script COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_script.py)

add_custom_target(run_tests
    DEPENDS matrix_multiplier
    COMMAND ctest -V
)

add_custom_target(build_and_test
    DEPENDS matrix_multiplier run_tests
)
