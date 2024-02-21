cmake_minimum_required(VERSION 3.15)

project(RSA VERSION 0.0 LANGUAGES CXX)

set(SOURCES rsa.cpp util.cpp)
set(HEADERS rsa.hpp util.hpp definitions.hpp)

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(RSA ${SOURCES} ${HEADERS} main.cpp)

add_subdirectory(tests)