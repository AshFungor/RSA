cmake_minimum_required(VERSION 3.15)

project(attack VERSION 0.0 LANGUAGES CXX)

set(SOURCES attack.cpp)

add_executable(attack ${SOURCES})

target_link_libraries(attack PRIVATE util)
target_link_libraries(attack PRIVATE algorithm)

file(COPY plaintext.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})