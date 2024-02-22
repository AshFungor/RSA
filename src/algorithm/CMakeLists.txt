cmake_minimum_required(VERSION 3.15)

project(algorithm VERSION 0.0 LANGUAGES CXX)

set(SOURCES rsa.cpp)
set(HEADERS rsa.hpp)

add_library(algorithm STATIC ${SOURCES} ${HEADERS})

target_link_libraries(algorithm PRIVATE util)
target_include_directories(algorithm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
