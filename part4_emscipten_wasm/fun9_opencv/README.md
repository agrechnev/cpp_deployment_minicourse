Fun 9: OpenCV example
===================

First, you have to build OpenCV for Emscripten from the source. Ignore the official docs with their Python script.
It only works with the ancient Emscripten 2.0.10, not good! Instead, use plain cmake like this
(in the OpenCV source directory):

`mkdir build_wasm3`  
`cd build_wasm3`  
`emcmake cmake <settings> ..`  
`emmake make -j12`  

You can experiment with different settings, the ones that worked for me (With Emscripten 3.x and OpenCV 4.x) are
in the file `config_emsdk_cv.sh`. If successfull, you will find `.cmake` files and the static libraries `lib/lib_*.a` 
in the build directory.

When building your cmake project, you'll have to specify the path to the OpenCV build directory:

`emcmake cmake -DOpenCV_DIR=<some path>/build_wasm3  ..`  
