cmake_minimum_required(VERSION 3.15)

project(RSA VERSION 0.0 LANGUAGES CXX)

set(SOURCES rsa.cpp util.cpp main.cpp)
set(HEADERS rsa.hpp util.hpp definitions.hpp)

add_executable(RSA ${SOURCES} ${HEADERS})