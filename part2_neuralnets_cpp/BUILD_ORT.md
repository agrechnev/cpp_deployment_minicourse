Building Microsoft ONNX runtime for C++
==============

This instruction is for Ubuntu 22.04, for other OSes the details can be different. Requires python3.

Based on the official build instructions  
https://onnxruntime.ai/docs/build/


We are going to build ONNX runtime from the source and install it by hand to `${HOME}/ort`.

1. Open a terminal. Go to the directory where you want ONNX runtime *source code* to be placed (anywhere you want actually)  
`cd ~/w/misc_codes`  
2. Clone ONNX runtime from GitHub  
`git clone --recursive https://github.com/microsoft/onnxruntime`  
`cd onnxruntime`  
We are using the `main` branch of ONNX runtime which is currently version 1.15. If you want another version, check it out  
`git checkout v1.13.1`  
Use `git tag` for the complete list.  
3. ONNX runtime wants really recent CMake versions (3.24 at the moment of writing this), which Ubuntu does not provide. Luckily, snap comes to the rescue.  
`sudo snap install cmake`  
The latest CMake will be in `/snap/cmake/current/bin/`. We want to make it the default CMake (for this terminal session only).  
`export PATH=/snap/cmake/current/bin/:${PATH}`  
`which cmake`  
4. Configure and build ONNX runtime (in the dirctory `onnxruntime`)  
`./build.sh --config Release --build_shared_lib --parallel`  
The build process is going to take a few minutes. Hopefully, it will reach 100% successfully and pass 100% of the unit tests. The result can be found in `build/Linux/Release`.  
5. Finally, we install it by hand to `${HOME}/ort`.  
`mkdir ~/ort`  
`mkdir ~/ort/lib`  
`cp -P build/Linux/Release/*.so* ~/ort/lib/`  
`cp -r include ~/ort`  
6. Optional: Remove the `build` directory to save disk space, as it is no longer needed.  
`rm -rf build`  

Now you can build our examples. Enjoy!
