cmake_minimum_required(VERSION 3.10)

project(hello_library)

add_library(hello_library SHARED 
    lib/Hello/Hello.cpp
)

target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/lib/Hello/include
)

add_executable(hello_binary 
    src/main.cpp
)

target_link_libraries( hello_binary
    PRIVATE 
        hello_library
)
