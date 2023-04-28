C++ deployment examples 4: Emscripten + WASM
==============

Developing with emscripten is tricky. First, install Emscripten following the official instructions.  
To activate the Emscripten toolchain in your terminal before building anything, type:  
`source <path_to_emscripten>/emsdk_env.sh`  

The examples:  

* `fun1`: Minimal example  
* `fun2`: Using JS arrays and calling C++ `malloc()` from the JS  
* `fun3`: Building C++ code as a JS module  
* `fun4`: Using `embind`  
* `fun5`: Using `embind` to wrap a C++ class  
* `fun6`: C++ memory issues, increasing the C++ heap  
* `fun7`: C++ exceptions  
* `fun8`: C++ threads  
* `fun9`: C++ OpenCV example  

Building C++ examples:

`fun` uses a script `compile.sh`. For all other examples, use CMake:  

`source <path_to_emscripten>/emsdk_env.sh`  
`mkdir build`  
`cd build`  
`emcmake cmake ..`  
`emmake make -j12`  

For examples `fun8`, `fun9`, see their own READMEs for additional details.

To run the examples in the browser, I used the simple web server (except for `fun8`):  
`python3 -m http.server`  
And then opened `localhost:8000` in the browser.
