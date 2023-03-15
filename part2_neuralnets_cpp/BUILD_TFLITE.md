Building TFLITE C++ (Linux)
================

As usual with Google libraries, the build process is absolutely ugly. TFLITE has tons of dependences.
They are built as separate static libraries (tons of them). 
Here you can (thankfully) use CMake for building (no Bazel), but the result
is neither installable nor CMake friendly.
Here (and in the CMake project of our example) I present the solution that is ugly, but it works.


1. Create a "root" directory somewhere. Remember this location!  
`mkdir ~/w/isc_codes/tf_root`  
`cd ~/w/isc_codes/tf_root`  
2. Clone tensorflow source:  
`git clone https://github.com/tensorflow/tensorflow`  
3. Build TFLITE with CMake:  
`mkdir tflite_build`  
`cd tflite_build`  
`cmake ../tensorflow/tensorflow/lite`  
`make -j8` 
4. Hopefully the build is successful. You should now get the result, the static library `libtensorflow-lite.a` in the build directory. But it requires
tons of other `*.a` libraries buried in this directory. This is absolutely ugly. Now you can try our TFLITE example. 
