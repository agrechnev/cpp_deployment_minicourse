First, build ONNX runtime and install it into `~/ort` as explained in `../BUILD_ORT.md`.

Then build as usual, but we also want to create teh ONX model:  
`mkdir build`  
`python3 create_onnx.py`  
`cd build`  
`cmake ..`  
`make`  
