cmake_minimum_required(VERSION 3.17)
project(mymath C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wconversion -Wformat)
endif()

add_executable(main main.c mymath.c)
