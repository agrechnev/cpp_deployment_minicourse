cmake_minimum_required(VERSION 3.1)
project(opencv1)
set(CMAKE_CXX_STANDARD 17)

# Find OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(opencv1 opencv1.cpp)
target_link_libraries(opencv1 ${OpenCV_LIBS})
