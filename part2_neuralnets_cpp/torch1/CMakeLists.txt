cmake_minimum_required(VERSION 3.1)
project(torch1)
set(CMAKE_CXX_STANDARD 17)

# Find Torch
# -DTorch_DIR=/home/seymour/libtorch/libtorch/share/cmake/Torch
find_package(Torch REQUIRED)
include_directories(${TORCH_INCLUDE_DIRS})
message("TORCH_LIBRARIES=${TORCH_LIBRARIES}")
message("TORCH_INCLUDE_DIRS=${TORCH_INCLUDE_DIRS}")
message("TORCH_CXX_FLAGS=${TORCH_CXX_FLAGS}")

# Find OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(torch1 torch1.cpp)
target_link_libraries(torch1 ${OpenCV_LIBS} ${TORCH_LIBRARIES})
