Building TFLITE C++ (Linux)
================


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
4. Hopefully the build is successful. You should now get the result, the static library `libtensorflow-lite.a` in the build directory. Now you can try our TFLITE
example. 
