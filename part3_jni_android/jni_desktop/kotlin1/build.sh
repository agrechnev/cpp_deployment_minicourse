#!/bin/bash
# Build the C++ code in linux into a shared lib
g++ -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux com_example_Hello.cpp -shared -o libidiot.so
