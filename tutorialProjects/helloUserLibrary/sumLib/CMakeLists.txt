cmake_minimum_required(VERSION 3.13)
project(sumLib)

add_library(sumLib STATIC "${CMAKE_CURRENT_SOURCE_DIR}/src/sum.cpp")
target_include_directories(sumLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")