add_library(Hello SHARED Hello.cpp)
target_include_directories(Hello
    PUBLIC 
    include
)