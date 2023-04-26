cmake_minimum_required(VERSION 3.1)
project(mycpp)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

#message("before: ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-pthread -sPTHREAD_POOL_SIZE=6")
#message("after: ${CMAKE_CXX_FLAGS}")


add_executable(mycpp mycpp.cpp)
