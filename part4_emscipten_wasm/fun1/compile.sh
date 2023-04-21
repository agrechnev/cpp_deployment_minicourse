#!/bin/bash
emcc -o myadd.js myadd.cpp -O3 -s EXPORTED_RUNTIME_METHODS=ccall,cwrap
