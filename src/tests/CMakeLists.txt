cmake_minimum_required(VERSION 3.15)

project(tests VERSION 0.0 LANGUAGES CXX)

set(SOURCES rsa-tests.cpp util-tests.cpp)

add_executable(tests ${SOURCES})

target_link_libraries(tests PRIVATE GTest::gtest_main)
target_link_libraries(tests PRIVATE algorithm)
target_link_libraries(tests PRIVATE util)
