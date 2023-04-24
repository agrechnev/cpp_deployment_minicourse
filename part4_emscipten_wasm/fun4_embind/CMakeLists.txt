cmake_minimum_required(VERSION 3.1)
project(myadd)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

add_executable(myadd myadd.cpp)
target_link_libraries(myadd embind)
