cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 17)
project("funcvandroid")

# OpenCV
# This is Hardcoded!!! Change for your location !!!
set(OPENCV_DIR /home/seymour/w/9/OpenCV-android-sdk/sdk/native)
include_directories(${OPENCV_DIR}/jni/include)

# OpenCV static libs
set(OpenCV_LIBS_DIR1 ${OPENCV_DIR}/staticlibs/${ANDROID_ABI}/)
file(GLOB OpenCV_LIBS1 "${OpenCV_LIBS_DIR1}/*.a")
set(OpenCV_LIBS_DIR2 ${OPENCV_DIR}/3rdparty/libs/${ANDROID_ABI}/)
file(GLOB OpenCV_LIBS2 "${OpenCV_LIBS_DIR2}/*.a")
set(OpenCV_LIBS ${OpenCV_LIBS1} ${OpenCV_LIBS2} z)
message("OpenCV_LIBS=${OpenCV_LIBS}")

add_library(funcvandroid SHARED native-lib.cpp)
target_link_libraries(funcvandroid log jnigraphics ${OpenCV_LIBS})