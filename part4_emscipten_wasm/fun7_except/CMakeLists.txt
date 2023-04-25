cmake_minimum_required(VERSION 3.1)
project(excep)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# To catch exceptions

# JS-way (old, slow)
#set(CMAKE_CXX_FLAGS "-fexceptions")

# WASM-native-way (new, fast)
set(CMAKE_CXX_FLAGS "-fwasm-exceptions")

add_executable(excep excep.cpp)
