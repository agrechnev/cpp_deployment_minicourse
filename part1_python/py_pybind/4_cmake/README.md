Building the CMake example on Linux
================

CMake cannot find `pybind11` PIP-installation, so you will need to help it with the option `-Dpybind11_DIR`,
and point it to the directory containing the `*.cmake` files, in my case:  
`-Dpybind11_DIR=${HOME}/.local/lib/python3.10/site-packages/pybind11/share/cmake/pybind11`  
Use `pip3 show -f pybind11` to find these files.

Bulld and run on Linux:  
`mkdir build`  
`cd build`  
`cmake -Dpybind11_DIR=<path_to_pybind11> ..`  
`make`  
`mv *.so ..`  
`cd ..`  
`python3 run_example.py`  
