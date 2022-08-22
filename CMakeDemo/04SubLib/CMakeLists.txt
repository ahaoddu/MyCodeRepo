cmake_minimum_required(VERSION 3.10)

project(hello_library)

add_subdirectory(lib/Hello)

add_executable(main src/main.cpp)

target_link_libraries(main Hello)
