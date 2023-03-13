cmake_minimum_required(VERSION 3.1)
project(ort1)
set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED ${ORT_ROOT})
    set(ORT_ROOT "$ENV{HOME}/ort")
endif()
message("ORT_ROOT = ${ORT_ROOT}")

include_directories(${ORT_ROOT}/include)
link_directories(${ORT_ROOT}/lib)

set(ORT_LIBS onnxruntime)

add_executable(ort1 ort1.cpp)
target_link_libraries(ort1 ${ORT_LIBS})
