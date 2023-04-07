cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 17)
project("funcvandroid")

# OpenCV
# This is Hardcoded!!! Change for your location !!!
set(OPENCV_DIR /home/seymour/w/9/OpenCV-android-sdk/sdk/native)
include_directories(${OPENCV_DIR}/jni/include)
# This is the shared version, static version can be found in ${OPENCV_DIR}/staticlibs
message("LILITH ${OPENCV_DIR}/libs/${ANDROID_ABI}/libopencv_java4.so")
set(OpenCV_LIBS  ${OPENCV_DIR}/libs/${ANDROID_ABI}/libopencv_java4.so)

add_library(funcvandroid SHARED native-lib.cpp)
target_link_libraries(funcvandroid log jnigraphics ${OpenCV_LIBS})