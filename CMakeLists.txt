cmake_minimum_required(VERSION 3.21)
project(git_rep)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(enum)

add_executable(string_edit_distance
        dynamic_programing/edit_distance/edit_distance.cpp)
