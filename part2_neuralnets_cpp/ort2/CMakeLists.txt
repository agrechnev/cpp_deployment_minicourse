cmake_minimum_required(VERSION 3.1)
project(ort2)
set(CMAKE_CXX_STANDARD 17)

# Find ORT by hand : no cmake way
if(NOT DEFINED ${ORT_ROOT})
    set(ORT_ROOT "$ENV{HOME}/ort")
endif()
message("ORT_ROOT = ${ORT_ROOT}")

include_directories(${ORT_ROOT}/include)
link_directories(${ORT_ROOT}/lib)


# Find OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(ORT_LIBS onnxruntime)

add_executable(ort2 ort2.cpp)
target_link_libraries(ort2 ${ORT_LIBS}  ${OpenCV_LIBS})
