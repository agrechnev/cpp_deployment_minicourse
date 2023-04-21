cmake_minimum_required(VERSION 3.1)
project(pfile)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Export malloc and free from C++
set(CMAKE_CXX_FLAGS "-s EXPORTED_FUNCTIONS=_malloc,_free")

message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

add_executable(pfile pfile.cpp)
