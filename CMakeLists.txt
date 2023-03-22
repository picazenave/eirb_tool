cmake_minimum_required(VERSION 3.12...3.25)

project(
  main
  VERSION 1.0
  LANGUAGES C)

set(CMAKE_C_STANDARD 99)
include_directories(include) 

file(GLOB_RECURSE SRC_FILES src/*.c)

add_executable(main ${SRC_FILES})