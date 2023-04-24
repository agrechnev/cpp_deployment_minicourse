cmake_minimum_required(VERSION 3.1)
project(mymul)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# These to options will build a JS module !
set(CMAKE_CXX_FLAGS "-s EXPORT_ES6=1 -s MODULARIZE=1")

add_executable(mymul mymul.cpp)
