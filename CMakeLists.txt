cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)
project(xcalc_core VERSION 0.0.1 LANGUAGES CXX)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

