cmake_minimum_required(VERSION 2.8..3.25)

project(
  main
  C)

set(CMAKE_C_STANDARD 99)
include_directories(include) 

set (CMAKE_C_FLAGS "-std=gnu99")

file(GLOB_RECURSE SRC_FILES src/*.c)

add_executable(main ${SRC_FILES})
