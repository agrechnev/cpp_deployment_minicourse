TFLITE C++ example (ResNet50)
===================

First, build TFLITE as explained in `../BUILD_TFLITE.md`. Remember your root dir. Then type 
(replace my root with your actual root):  
`mkdir build`  
`python3 create_tflite.py`  
`cd build`  
`cmake -DTF_ROOT=${HOME}/w/misc_codes/tf_root ..`  
`make`  

The CMake project is super-ugly, but with Google libs it's hard to do things properly!
