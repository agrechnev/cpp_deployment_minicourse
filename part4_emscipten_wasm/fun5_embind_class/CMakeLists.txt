cmake_minimum_required(VERSION 3.1)
project(hero)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

add_executable(hero hero.cpp)
target_link_libraries(hero embind)
