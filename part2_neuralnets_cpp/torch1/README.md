Libtorch (torch C++) example
==========================

`Libtorch` is the Torch C++ API which is similar to PyToch and can load TorchScript models directly.  

First, download libtorch from the pytorch site. In the download menu choose:  
PyTorch Build: stable  
Your OS: your OS (Linux for me)  
Package: libtorch  
Language: C++/Java  
Compute Platform: Either CUDA or CPU  
Run this Command: Download here (cxx11 ABI)  

Note: For simplicity, I chose the CPU version. If you want CUDA, you must have both CUDA and CuDNN fully installed,
and CMake should be able to find them.

Download `libtorch`, put the ZIP file somewhere (I used `~/libtorch`) and unzip it. We have to help CMake find it:

`mkdir build`  
`python3 create_pt_model.py`  
`cd build`  
`cmake -DTorch_DIR=${HOME}/libtorch/libtorch/share/cmake/ ..`  
`make`  
