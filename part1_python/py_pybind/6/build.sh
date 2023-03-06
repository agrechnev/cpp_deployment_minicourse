#!/bin/bash
c++ -O3 -Wall -shared -std=c++17 -fPIC -I/usr/include/eigen3 $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)
