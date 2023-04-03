cmake_minimum_required(VERSION 3.10)
project(jni_java3_cpp)
set(CMAKE_CXX_STANDARD 17)

# JNI
message("JAVA_HOME = $ENV{JAVA_HOME}")
include_directories($ENV{JAVA_HOME}/include)
include_directories($ENV{JAVA_HOME}/include/linux)

add_library(idiot SHARED com_example_Box.cpp com_example_Box.h BoxImpl.h)
