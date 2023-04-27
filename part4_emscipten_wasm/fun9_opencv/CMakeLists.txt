cmake_minimum_required(VERSION 3.1)
project(mycpp)
set(CMAKE_CXX_STANDARD 17)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Run it like this: 
# emcmake cmake -DOpenCV_DIR=<OpenCV dir> ..
# Where <OpenCV dir> is your wasm build dir (contains .cmake files), for example
# emcmake cmake -DOpenCV_DIR=/home/seymour/w/misc_codes/opencv/build_wasm3/ ..

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} )
message("OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS} ")
message("OpenCV_LIBS = ${OpenCV_LIBS} ")

# We need malloc, free; we also need wasm-exceptions, because they were used in my OpenCV build
#message("before: ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-fwasm-exceptions -s EXPORTED_FUNCTIONS=_malloc,_free")
#message("after: ${CMAKE_CXX_FLAGS}")

add_executable(mycpp mycpp.cpp)
target_link_libraries(mycpp ${OpenCV_LIBS})
