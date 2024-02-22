cmake_minimum_required(VERSION 3.15)

project(RSA VERSION 0.0 LANGUAGES CXX)

set(SOURCES main.cpp)

add_subdirectory(algorithm)
add_subdirectory(util)
add_subdirectory(tests)

add_executable(RSA ${SOURCES})

target_link_libraries(RSA PRIVATE util)
target_link_libraries(RSA PRIVATE algorithm)
