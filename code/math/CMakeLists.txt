cmake_minimum_required(VERSION 3.17)
project(mymath C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wconversion -Wformat")

add_executable(main main.c mymath.c)

