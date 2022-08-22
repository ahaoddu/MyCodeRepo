cmake_minimum_required(VERSION 3.10)

project(header)

set(SRC src/main.cpp src/Printer.cpp)

add_executable(header ${SRC})

target_include_directories(header PRIVATE ${PROJECT_SOURCE_DIR}/include)