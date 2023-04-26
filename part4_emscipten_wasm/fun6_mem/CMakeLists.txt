cmake_minimum_required(VERSION 3.1)
project(mem)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# To increase the C++ heap size from the default 16 Mb

# Either staticaly

#set(CMAKE_CXX_FLAGS "-s TOTAL_MEMORY=1100MB")

# Or enable growth
set(CMAKE_CXX_FLAGS "-sALLOW_MEMORY_GROWTH")

add_executable(mem mem.cpp)
