cmake_minimum_required(VERSION 3.15)

project(tests VERSION 0.0 LANGUAGES CXX)

set(TESTING )

foreach(file IN ITEMS ${HEADERS})
    list(APPEND TESTING "${SRC_ROOT}/${file}")
endforeach()

foreach(file IN ITEMS ${SOURCES})
    list(APPEND TESTING "${SRC_ROOT}/${file}")
endforeach()

include_directories(${SRC_ROOT})
set(SOURCES rsa-tests.cpp util-tests.cpp)

add_executable(tests ${SOURCES} ${TESTING})

target_link_libraries(tests PRIVATE GTest::gtest_main)