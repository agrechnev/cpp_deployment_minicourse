cmake_minimum_required(VERSION 3.10)
project(pybind_example4 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# pybind11_DIR=${HOME}/.local/lib/python3.10/site-packages/pybind11/share/cmake/pybind11
find_package(pybind11 REQUIRED)
pybind11_add_module(example example.cpp)

