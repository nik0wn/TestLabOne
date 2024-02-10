cmake_minimum_required(VERSION 3.27)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(ArraySum STATIC lib/ArraySum.cpp)


target_include_directories(ArraySum PUBLIC ${PROJECT_SOURCE_DIR}/lib)


add_executable(ArraySumTest tests/ArraySumTest.cpp)

target_link_libraries(ArraySumTest ArraySum GTest::gtest_main)

target_include_directories(ArraySumTest PUBLIC ${PROJECT_SOURCE_DIR}/lib)

add_executable(lab1 bin/main.cpp)

target_link_libraries(lab1 ArraySum)

target_include_directories(lab1 PUBLIC ${PROJECT_SOURCE_DIR}/lib)

include(GoogleTest)
gtest_discover_tests(ArraySumTest)
