cmake_minimum_required(VERSION 3.19)
project(JsonDemo C)

set(CMAKE_C_STANDARD 11)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()

add_library(leptjson leptjson.c)
add_executable(leptjson_test test.c)
target_link_libraries(leptjson_test leptjson)
