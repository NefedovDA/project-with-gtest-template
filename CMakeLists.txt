cmake_minimum_required(VERSION 3.15)

project(GTestTemplate)

set(CMAKE_CXX_STANDARD 14)

set(TEST_DIR "googletest-framework")

# Add GoogleTest to the project
include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_SOURCE_DIR}/${TEST_DIR}
)

# Add test runner link
add_library(test_runner run_tests.cpp)
target_link_libraries(test_runner gtest)

set(SOURCE
        src/main.cpp)

set(TESTS
        test/test.cpp)

add_executable(run ${SOURCE})

add_executable(test ${SOURCE} ${TESTS})

target_link_libraries(test test_runner)
target_link_options(test PRIVATE "-e_run_tests")